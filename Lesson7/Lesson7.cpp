#include "stdafx.h"
#include <objbase.h>
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include "MyHandler.h"
#include "MyErrorHandler.h"

#import <msxml6.dll> 

using namespace std;

int main(int argc, char* argv[])
{
	HRESULT hr;
	ISAXXMLReaderPtr pXMLReader;

	CoInitialize(NULL);

	// create instance of the SAX Reader
	hr = pXMLReader.CreateInstance(__uuidof(MSXML2::SAXXMLReader60));
	if (FAILED(hr))
	{
		cout << "Could not create SAX reader." << endl;
		return 0;
	}

	// here we set the content handler the reader
	MSXML2::ISAXContentHandler* pContentHandler = new CMyContentHandler();
	hr = pXMLReader->putContentHandler(pContentHandler);
	if (FAILED(hr))
	{
		cout << "Could not set SAX content handler." << endl;
		return 0;
	}

	// here we set the error handler
	// for non-valid document, the methods of this object will be called
	MSXML2::ISAXErrorHandler* pErrrHandler = new CMyErrorHandler();
	hr = pXMLReader->putErrorHandler(pErrrHandler);
	if (FAILED(hr))
	{
		cout << "Could not set SAX error handler." << endl;
		return 0;
	}

	// create a schema collection - used by SAX for validation
	MSXML2::IXMLDOMSchemaCollectionPtr pSchemaColl;
	hr = pSchemaColl.CreateInstance(__uuidof(MSXML2::XMLSchemaCache60));
	if (FAILED(hr))
	{
		cout << "Could not create schema cache." << endl;
		return 0;
	}

	// add schemas to collection
	hr = pSchemaColl->add(L"movie_db", _variant_t("Schema.xsd"));

	// here we assign schema to the reader and set necessary flags, so that document can be validated
	hr = pXMLReader->raw_putFeature(_bstr_t(L"schema-validation"), _variant_t(true));
	if (FAILED(hr))
	{
		cout << "Could not set validation flags." << endl;
		return 0;
	}
	pXMLReader->raw_putProperty(_bstr_t(L"schemas"), _variant_t(pSchemaColl.GetInterfacePtr()));
	if (FAILED(hr))
	{
		cout << "Could not set validation flags." << endl;
		return 0;
	}

	// try to parse the XML document
	try
	{
		hr = pXMLReader->parseURL((unsigned short*)L"Data.xml");
		if (FAILED(hr))
		{
			cout << "Could not parse the xml document." << endl;
			return 0;
		}

		cout << "SUCCESS !!!" << endl;
	}
	catch (_com_error& e)
	{
		cout << "Error while parsing xml... " << endl;
	}

	pXMLReader.Release();
	pSchemaColl.Release();

	CoUninitialize();
	system("PAUSE");
	return 0;
}

