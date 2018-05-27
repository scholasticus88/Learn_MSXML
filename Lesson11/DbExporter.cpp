#include "DbExporter.h"

CDbExporter::CDbExporter(void):
	m_pConnection(NULL)
{

}

CDbExporter::~CDbExporter(void)
{

}

bool CDbExporter::Init()
{
	HRESULT hr;
	bool bRetVal = false;

	try
	{
		hr = m_pConnection.CreateInstance(__uuidof(Connection));
		if (FAILED(hr))
			return false;
		
		_bstr_t bstrConnectionStr = "Provider=SQLNCLI10;Server=.;Database=Pokus;Trusted_Connection=yes;";
		hr = m_pConnection->Open(bstrConnectionStr, _bstr_t(""), _bstr_t(""), adConnectUnspecified);
		bRetVal = (!FAILED(hr));
	}
	catch (_com_error&)
	{
		bRetVal = false;
	}

	return bRetVal;
}

bool CDbExporter::UnInit()
{
	m_pConnection->Close();
	m_pConnection.Release();
	return true;
}

bool CDbExporter::CreateExportDocument(MSXML2::IXMLDOMDocumentPtr& pDoc)
{
	HRESULT hr;
	bool    bRetVal = false;

	try
	{
		hr = pDoc.CreateInstance(__uuidof(DOMDocument));
		if (FAILED(hr))
			return false;

		MSXML2::IXMLDOMElementPtr pRoot = pDoc->createElement("Export");
		pDoc->appendChild(pRoot);
		bRetVal = true;
	}
	catch (_com_error&)
	{
		bRetVal = false;
	}

	return false;
}

bool CDbExporter::ExportTable(_bstr_t pszTableName, MSXML2::IXMLDOMDocumentPtr& pDoc, MSXML2::IXMLDOMElementPtr& pParent)
{
	bool bRetVal = false;

	try
	{
		_bstr_t bstrCmt = "This is the export of [";
		bstrCmt += pszTableName;
		bstrCmt += "] table.";
		MSXML2::IXMLDOMCommentPtr pComment = pDoc->createComment(bstrCmt);
		MSXML2::IXMLDOMNodePtr pCmtNode;
		pComment->QueryInterface(__uuidof(MSXML2::IXMLDOMNode), (void**)&pCmtNode);
		pParent->appendChild(pCmtNode);

		_bstr_t bstrSql = "SELECT * FROM ";
		bstrSql += pszTableName;

		_bstr_t bstrRowElementName = pszTableName;
		bstrRowElementName += "Row";

		MSXML2::IXMLDOMElementPtr pTableElement = pDoc->createElement(pszTableName);

		_RecordsetPtr pRs = m_pConnection->Execute(bstrSql, NULL, adCmdText);
		if (pRs != NULL)
		{
			pRs->MoveFirst();
			while (!pRs->EndOfFile && !pRs->BOF)
			{
				MSXML2::IXMLDOMElementPtr pRowElement = pDoc->createElement(bstrRowElementName);				

				for (int i=0; i<pRs->Fields->Count; i++)
				{
					_bstr_t bstrName  = pRs->Fields->Item[(LONG)i]->Name;
					_bstr_t bstrValue = "";      

					if (pRs->Fields->Item[(LONG)i]->Value.vt != VT_NULL)
					{
						_bstr_t value = pRs->Fields->Item[(LONG)i]->Value;
						bstrValue     = _com_util::ConvertBSTRToString(value);
					}

					MSXML2::IXMLDOMElementPtr pColElement = pDoc->createElement(bstrName);
					pColElement->put_text(bstrValue);
					pRowElement->appendChild(pColElement);
				}

				pTableElement->appendChild(pRowElement);

				pRs->MoveNext();
			}

			pRs->Close();
		}

		pParent->appendChild(pTableElement);
		bRetVal = true;
	}
	catch (_com_error&)
	{
		bRetVal = false;
	}

	return bRetVal;
}

bool CDbExporter::ExportAll(_bstr_t bstrSchema, MSXML2::IXMLDOMDocumentPtr& pDoc, MSXML2::IXMLDOMElementPtr& pParent)
{
	bool bRetVal = false;
	try
	{
		_bstr_t bstrSql = "SELECT TABLE_NAME FROM INFORMATION_SCHEMA.TABLES";
		if (bstrSchema.length() > 0)
		{
			bstrSql += " WHERE TABLE_SCHEMA = '";
			bstrSql += bstrSchema;
			bstrSql += "'";
		}

		_RecordsetPtr pRs = m_pConnection->Execute(bstrSql, NULL, NULL);
		while (!pRs->EndOfFile && !pRs->BOF)
		{
			_bstr_t bstrTableName = pRs->Fields->Item[L"TABLE_NAME"]->Value;

			if (bstrSchema.length() > 0)
				bstrTableName = bstrSchema + "." + bstrTableName;

			bool bRes = ExportTable(bstrTableName, pDoc, pParent);
			if (!bRes)
				return false;

			pRs->MoveNext();	
		}
		pRs->Close();

		bRetVal = true;
	}
	catch (_com_error&)
	{
		bRetVal = false;
	}

	return bRetVal;
}






