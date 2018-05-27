#include "stdafx.h"
#include <objbase.h>
#include <windows.h>

#import <msxml6.dll>

int main(int argc, char* argv[])
{
	MSXML2::IXMLDOMDocumentPtr pDoc = NULL;
	HRESULT hr;

	CoInitialize(NULL);

	hr = pDoc.CreateInstance(__uuidof(DOMDocument));
	if (FAILED(hr))
	{
		printf("Failed to create instance of DOMDocument...\n");
		return 0;
	}

	pDoc->put_async(VARIANT_FALSE);
	pDoc->put_preserveWhiteSpace(TRUE);
	pDoc->put_validateOnParse(VARIANT_TRUE);

	VARIANT_BOOL bSt = pDoc->load(_variant_t("Config.xml"));
	if (bSt != VARIANT_TRUE)
	{
		printf("Failed to load input xml...\n");
		MSXML2::IXMLDOMParseErrorPtr pErr = NULL;
		pDoc->get_parseError(&pErr);
		if (pErr != NULL)
		{
			BSTR bstrReason;
			pErr->get_reason(&bstrReason);
			printf("%s\n", _com_util::ConvertBSTRToString(bstrReason));
		}
		pDoc.Release();
		return 0;
	}
	printf("Loaded successfully...\n");

	///////////////////////////////////////////////////////////////////////////

	MSXML2::IXMLDOMNodePtr pParent = pDoc->selectSingleNode(_bstr_t("/Configuration/EndPoints"));

	MSXML2::IXMLDOMElementPtr pNewEp   = pDoc->createElement(_bstr_t("Endpoint"));
	MSXML2::IXMLDOMElementPtr pNewType = pDoc->createElement(_bstr_t("Type"));
	MSXML2::IXMLDOMElementPtr pNewIP   = pDoc->createElement(_bstr_t("IP"));
	MSXML2::IXMLDOMElementPtr pNewPort = pDoc->createElement(_bstr_t("Port"));
	
	pNewType->put_text(_bstr_t("soap"));
	pNewIP->put_text(_bstr_t("192.168.1.1"));
	pNewPort->put_text(_bstr_t("8080"));
	
	pNewEp->appendChild(pNewType);
	pNewEp->appendChild(pNewIP);
	pNewEp->appendChild(pNewPort);
	pParent->appendChild(pNewEp);

	///////////////////////////////////////////////////////////////////////////

	// create a SAX reader
	MSXML2::ISAXXMLReaderPtr pSaxReader;
	hr = pSaxReader.CreateInstance(__uuidof(MSXML2::SAXXMLReader60));
	if (FAILED(hr))
	{
		return 0;
	}

	// create a SAX writer
	MSXML2::IMXWriterPtr pMXWriter;
	hr = pMXWriter.CreateInstance(__uuidof(MSXML2::MXXMLWriter60));
	if (FAILED(hr))
	{
		return 0;
	}

	pMXWriter->put_encoding(_bstr_t("UTF-8"));
	pMXWriter->put_indent(VARIANT_TRUE);
	pMXWriter->get_omitXMLDeclaration(VARIANT_FALSE);

	MSXML2::ISAXContentHandlerPtr pContentHandler = NULL;
	pMXWriter->QueryInterface(__uuidof(MSXML2::ISAXContentHandler), (void**)&pContentHandler);
	pSaxReader->putContentHandler(pContentHandler);
	pSaxReader->parse(_variant_t(pDoc.GetInterfacePtr()));

	// formatted output
	_bstr_t out = pMXWriter->output;
	char* pszOutput = _com_util::ConvertBSTRToString(out);
	printf("\n%s\n\n", pszOutput);

	pSaxReader.Release();
	pMXWriter.Release();
	pContentHandler.Release();
	pDoc.Release();
	pParent.Release();
	pNewEp.Release();
	pNewIP.Release();
	pNewPort.Release();
	pNewType.Release();

	CoUninitialize();
	system("PAUSE");
	return 0;
}

