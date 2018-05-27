#ifndef __DB_EXPORTER__

#define __DB_EXPORTER__

#include <vector>

#import "C:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")
#import <msxml6.dll>

using namespace std;

class CDbExporter
{
public:
	CDbExporter(void);
	~CDbExporter(void);

	bool Init();
	bool UnInit();

	bool CreateExportDocument(MSXML2::IXMLDOMDocumentPtr& pDoc);
	bool ExportAll(_bstr_t bstrSchema, MSXML2::IXMLDOMDocumentPtr& pDoc, MSXML2::IXMLDOMElementPtr& pParent);
	bool ExportTable(_bstr_t pszTableName, MSXML2::IXMLDOMDocumentPtr& pDoc, MSXML2::IXMLDOMElementPtr& pParent);

private:
	_ConnectionPtr m_pConnection;

};

#endif