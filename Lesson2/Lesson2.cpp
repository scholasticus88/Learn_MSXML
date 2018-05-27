#include "stdafx.h"
#include <Windows.h>
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

	IXMLDOMNode* node1;
	IXMLDOMNode* node2;
	IXMLDOMNode* newnode;
	VARIANT v;
	v.vt = VT_I2;
	v.iVal = NODE_ELEMENT;
	xmlDoc->createNode(v, _bstr_t(L"MyCarCompany"), _bstr_t(L""), &node1);
	xmlDoc->appendChild(node1, &newnode);

	for (int i=0; i<5; i++)
	{
		char buff[25];
		xmlDoc->createNode(v, _bstr_t(L"child"), _bstr_t(L""), &node2);
		sprintf(buff, "%d", i+1);
		node2->put_text(_bstr_t(buff));
		node1->appendChild(node2, &newnode);
	}

	VARIANT out_path;
	out_path.vt = VT_BSTR;
	out_path.bstrVal = _bstr_t(L"D:\\pokus.xml");
	xmlDoc->save(out_path);

	CoUninitialize();
	system("PAUSE");
	return 0;
}

