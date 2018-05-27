#include <objbase.h>
#include <iostream>
#include <windows.h>
#include <tchar.h>

#import <msxml6.dll> 

using namespace std;

int main(int argc, char* argv[])
{
	HRESULT hr;

	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		cout << "Could not initialize COM apartment..." << endl;
		return 0;
	}

	// create a SAX reader
	MSXML2::ISAXXMLReaderPtr pSaxReader;
	hr = pSaxReader.CreateInstance(__uuidof(MSXML2::SAXXMLReader60));
	if (FAILED(hr))
	{
		cout << "Could not create instance of SAX reader..." << endl;
		return 0;
	}

	// create a SAX writer
	MSXML2::IMXWriterPtr pMXWriter;
	hr = pMXWriter.CreateInstance(__uuidof(MSXML2::MXXMLWriter60));
	if (FAILED(hr))
	{
		cout << "Could not create instance of SAX reader..." << endl;
		return 0;
	}

	// create a XML DOM document
	MSXML2::IXMLDOMDocument2Ptr pXmlDoc;
	hr = pXmlDoc.CreateInstance(__uuidof(MSXML2::DOMDocument60));
	if (FAILED(hr))
	{
		cout << "Could not create instance of DOM dicument..." << endl;
		return 0;
	}

	// the xml shall be indented
	hr = pMXWriter->put_indent(VARIANT_TRUE);
	// set the encoding
	hr = pMXWriter->put_encoding(_bstr_t("UTF-16"));
	// standalone
	hr = pMXWriter->put_standalone(VARIANT_FALSE);
	// version
	hr = pMXWriter->put_version(_bstr_t("1.1"));
	// ommitting xml declaration
	hr = pMXWriter->put_omitXMLDeclaration(VARIANT_TRUE);
	// set the output to the DOM document
	hr = pMXWriter->put_output(_variant_t(pXmlDoc.GetInterfacePtr()));

	// MXXMLWriter imlements ISAXContentHandler
	MSXML2::ISAXContentHandler* pContentHandler;
	hr = pMXWriter->QueryInterface(__uuidof(MSXML2::ISAXContentHandler), (void**)&pContentHandler);

	// manualy create document	 
	pContentHandler->startDocument();
	pContentHandler->processingInstruction(L"xml", 3, L"version='1.0'", 13);
	pContentHandler->startElement(L"abc:efg", 7, L"Database", 8, L"Database", 8, NULL);
	pContentHandler->startElement(L"abc:efg", 7, L"Movie", 5, L"Movie", 5, NULL);
	pContentHandler->characters(L"Desperado", 9);
	pContentHandler->endElement(L"abc:efg", 7, L"Movie", 5, L"Movie", 5);
	pContentHandler->endElement(L"abc:efg", 7, L"Database", 8, L"Database", 5);
	pContentHandler->endDocument();

	// we managed to build the DOM via SAX
	// but indent and formating settings (that we set to the MXWriter) are not aaplied because
	// here we get the string from the DOM and not from MXWriter !!!
	BSTR txt;
	pXmlDoc->get_xml(&txt);
	cout << _com_util::ConvertBSTRToString(txt) << endl << endl;

	pSaxReader.Release();
	pXmlDoc.Release();
	pMXWriter.Release();
	
	CoUninitialize();
	system("PAUSE");
	return 0;
}