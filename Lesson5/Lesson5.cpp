#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ObjBase.h>
#include <AtlBase.h>
#include <comutil.h>
#include <msxml6.h>

#pragma comment(lib, "msxml6.lib")
#pragma comment(lib, "comsuppw.lib")

using namespace std;

int main(int argc, char* argv[])
{
	CoInitialize(NULL);

	IXMLHTTPRequest* pXmlHttp = NULL;
	HRESULT hr = CoCreateInstance(CLSID_XMLHTTP60, NULL, CLSCTX_INPROC_SERVER, IID_IXMLHTTPRequest, (void**)&pXmlHttp);
	if (SUCCEEDED(hr) && pXmlHttp)
	{
		// Open the request
		_bstr_t method = L"GET";
		_bstr_t url = L"http://johnysparadise.ic.cz/xml/pokus.xml";
		_variant_t async = false;
		hr = pXmlHttp->open(method, url, async, _variant_t(), _variant_t());
		pXmlHttp->send(_variant_t(""));
		if (SUCCEEDED(hr))
		{
			long lStatus;
			pXmlHttp->get_status(&lStatus);
			cout << "Status: " << lStatus << endl;

			BSTR statusText;
			pXmlHttp->get_statusText(&statusText);
			cout << "Status text: " << _com_util::ConvertBSTRToString(statusText) << endl;

			BSTR header;
			pXmlHttp->getResponseHeader(_bstr_t(L"Content-Type") , &header);
			cout << "Content: " << _com_util::ConvertBSTRToString(header) << endl;

			BSTR resp;
			pXmlHttp->get_responseText(&resp);
			//cout << _com_util::ConvertBSTRToString(resp) << endl;

			IXMLDOMDocument3 * pXmlDom;
			HRESULT hr = CoCreateInstance(__uuidof(DOMDocument60), NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument3, (void**)&pXmlDom);
			if (SUCCEEDED(hr) && pXmlDom)
			{
				pXmlDom->put_validateOnParse(VARIANT_FALSE);
				pXmlDom->put_async(VARIANT_FALSE);
				pXmlDom->put_preserveWhiteSpace(VARIANT_TRUE);
				pXmlDom->put_resolveExternals(VARIANT_FALSE);

				VARIANT_BOOL success;
				hr = pXmlDom->loadXML(resp, &success);
				if (!SUCCEEDED(hr) || (success == VARIANT_FALSE))
				{
					cout << "Nelze nacist xml odpovedi!" << endl;
					pXmlDom->Release();
					return 0;
				}

				IXMLDOMElement* root;
				hr = pXmlDom->get_documentElement(&root);
				if (!SUCCEEDED(hr))
				{
					cout << "Nelze ziskat root... " << endl;
					pXmlDom->Release();
					return 0;
				}

				IXMLDOMNode* usernameNode;
				IXMLDOMNode* passwordNode;
				IXMLDOMNode* superPwdNode;

				root->selectSingleNode(_bstr_t(L"username"), &usernameNode);
				root->selectSingleNode(_bstr_t(L"password"), &passwordNode);
				root->selectSingleNode(_bstr_t(L"superpwd"), &superPwdNode);

				BSTR txt;
				usernameNode->get_text(&txt);
				cout << "Username:" << _com_util::ConvertBSTRToString(txt) << endl;

				passwordNode->get_text(&txt);
				cout << "Password:" << _com_util::ConvertBSTRToString(txt) << endl;

				superPwdNode->get_text(&txt);
				cout << "SuperPwd:" << _com_util::ConvertBSTRToString(txt) << endl;
			}
		}
	}

	cout << endl << endl;
	CoUninitialize();
	system("PAUSE");
	return 0;
}

