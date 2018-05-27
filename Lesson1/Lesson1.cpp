#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <ObjBase.h>
#include <comutil.h>
#include <msxml6.h>

#pragma comment(lib, "msxml6.lib")
#pragma comment(lib, "comsuppw.lib")

int main(int argc, char* argv[])
{
	CoInitialize(NULL);

	IXMLDOMDocument* xmlDoc;
	HRESULT hr = CoCreateInstance(__uuidof(DOMDocument60), NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, (void**)(&xmlDoc));
	if (FAILED(hr))
	{
		printf("Cannot create instance of DOMDocument.\n");
		return 0;
	}

	// don't valide on parse
	xmlDoc->put_validateOnParse(VARIANT_FALSE);
	// asynchrnous processing not permited
	xmlDoc->put_async(VARIANT_FALSE);
	// resolve externals during loading
	xmlDoc->put_resolveExternals(VARIANT_TRUE);
	// white spaces
	xmlDoc->put_preserveWhiteSpace(VARIANT_FALSE);

	VARIANT_BOOL b;
	hr = xmlDoc->loadXML(_bstr_t(L"<root></root>"), &b);	
	if (b != VARIANT_TRUE)
	{
		IXMLDOMParseError * err;
		BSTR bstr;
		long line, linepos;
		xmlDoc->get_parseError(&err);
		err->get_reason(&bstr);
		err->get_line(&line);
		err->get_linepos(&linepos);
		printf("Error (%d, %d): %S \n", line, linepos, bstr);
		system("PAUSE");
		return 0;
	}

	IXMLDOMNode * pNode;
	VARIANT v2;
	v2.vt = VT_I2;
	v2.iVal = 1;
	xmlDoc->createNode(v2, _bstr_t(L"child"), _bstr_t(L""), &pNode);

	IXMLDOMElement* root;
	IXMLDOMNode* newnode; 
	xmlDoc->get_documentElement(&root);
	root->appendChild(pNode, &newnode);

	VARIANT val;
	val.vt = VT_I2;
	val.iVal = 10;
	root->setAttribute(_bstr_t("MyAttr"), val);

	BSTR x;
	xmlDoc->get_xml(&x);
	printf("%S", x);

	VARIANT v;
	v.vt = VT_BSTR;
	v.bstrVal = _bstr_t(L"D:\\pokus.xml");
	xmlDoc->save(v);


	xmlDoc->Release();
	
	CoUninitialize();
	system("PAUSE");
	return 0;
}

