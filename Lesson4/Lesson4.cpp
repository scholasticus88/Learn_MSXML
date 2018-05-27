#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ObjBase.h>
#include <AtlBase.h>
#include <comutil.h>
#include <Windows.h>
#include <msxml6.h>

#pragma comment(lib, "msxml6.lib")
#pragma comment(lib, "comsuppw.lib")

using namespace std;

////////////////////////////////////////////
//
// NO-NAMESPACE XML VALIDATION
//
////////////////////////////////////////////
int main(int argc, char* argv[])
{
	IXMLDOMDocument* xmlDoc = NULL;
	HRESULT hr;

	CoInitialize(NULL);
	
	hr = CoCreateInstance(__uuidof(DOMDocument60), NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, (LPVOID*)&xmlDoc); 
	if (!SUCCEEDED(hr))
	{
		cout << "Cannot create XML Document object" << endl;
		return 0;
	}

	xmlDoc->put_async(VARIANT_FALSE);
	xmlDoc->put_resolveExternals(VARIANT_TRUE);
	xmlDoc->put_validateOnParse(VARIANT_TRUE);

	VARIANT_BOOL vbStatus;
	VARIANT str;
	VariantInit(&str);
	V_BSTR(&str) = SysAllocString(L"MyData.xml");
	V_VT(&str) = VT_BSTR;
	xmlDoc->load(str, &vbStatus);
	VariantClear(&str);

	if (vbStatus != VARIANT_TRUE)
	{
		IXMLDOMParseError * pErr;
		xmlDoc->get_parseError(&pErr);
		if (pErr)
		{
			BSTR bstrDesc;
			BSTR bstrSrc;
			long line;
			long pos;
			pErr->get_reason(&bstrDesc); 
			pErr->get_line(&line);
			pErr->get_line(&pos);
			pErr->get_srcText(&bstrSrc);
			cout << "Chyba:  " << "\t" << _com_util::ConvertBSTRToString(bstrDesc) << endl;
			cout << "Line:   " << "\t" << line << endl;
			cout << "Column: " << "\t" << pos << endl;
			cout << "Source: " << "\t" << _com_util::ConvertBSTRToString(bstrSrc) << endl;
			pErr->Release();
		}
	}
	else
	{
		cout << "SUCCESS !" << endl;
	}

	xmlDoc->Release();

	CoUninitialize();
	system("PAUSE");
	return 0;
}

