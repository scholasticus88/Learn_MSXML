#include "stdafx.h"
#include <objbase.h>
#include <iostream>

#import "msxml6.dll"

using namespace std;

bool ProcessXml(MSXML2::IXMLDOMDocument3Ptr& pXmlDoc)
{
	BSTR txt;
	pXmlDoc->get_xml(&txt);
	cout << _com_util::ConvertBSTRToString(txt) << endl;

	/* MUST HAVE A XSD/DTD association
	MSXML2::IXMLDOMParseErrorPtr pErr = pXmlDoc->validate();
	if (pErr)
	{
		BSTR err;
		pErr->get_reason(&err);
		cout << "Error: " << _com_util::ConvertBSTRToString(err) << endl;
		return false;
	}
	*/

	return true;
}

bool GetXML(MSXML2::IXMLDOMDocument3Ptr& pXmlDoc)
{
	HRESULT hr;
	IXMLHttpRequestPtr pReq;
	hr = pReq.CreateInstance(__uuidof(XMLHTTPRequest));
	if (FAILED(hr))
	{
		cout << "Could not create request object." << endl;
		return false;
	}

	VARIANT_BOOL vb = VARIANT_FALSE;
	hr = pReq->open(_bstr_t("GET"), _bstr_t("http://www.w3schools.com/xml/note.xml"), _variant_t(false), _variant_t(""), _variant_t(""));
	if (FAILED(hr))
	{
		cout << "Could not open request." << endl;
		return false;
	}

	hr = pReq->send(_variant_t(""));
	if (FAILED(hr))
	{
		cout << "Sending the request failed." << endl;
		return false;
	}

	long lStatus;
	pReq->get_status(&lStatus);
	if (lStatus != 200)
	{
		cout << "Response status: " << lStatus << endl;
		return false;
	}

	hr = pReq->get_responseXML((IDispatch**) &pXmlDoc);
	if (FAILED(hr))
	{
		cout << "Cannot obtain XML document." << endl;
		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	MSXML2::IXMLDOMDocument3Ptr pXmlDoc;

	CoInitialize(NULL);

	if (GetXML(pXmlDoc))
	{
		ProcessXml(pXmlDoc);
	}

	CoUninitialize();
	system("PAUSE");
	return 0;
}

