#include "stdafx.h"
#include "DbExporter.h"

int main(int argc, char* argv[])
{
	CoInitialize(NULL);
	HRESULT hr;

	CDbExporter dbe;
	
	MSXML2::IXMLDOMDocumentPtr pDoc = NULL;

	if (!dbe.Init())
	{
		printf("Could not init the DB access...\n");
		return 0;
	}
	dbe.CreateExportDocument(pDoc);
	//dbe.ExportTable("Customer", pDoc, pDoc->GetdocumentElement());
	//dbe.ExportTable("Message", pDoc, pDoc->GetdocumentElement());
	dbe.ExportAll("jojo", pDoc, pDoc->GetdocumentElement());
	dbe.UnInit();

	pDoc->save(_variant_t("D:\\outxml.xml"));

	pDoc.Release();

	CoUninitialize();
	system("PAUSE");
	return 0;
}

