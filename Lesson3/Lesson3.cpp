#include "stdafx.h"
#include <ObjBase.h>
#include <AtlBase.h>
#include <comutil.h>
#include <Windows.h>
#include <iostream>
#include <msxml6.h>

#pragma comment(lib, "msxml6.lib")
#pragma comment(lib, "comsuppw.lib")

#define MAX_BUFFER_LEN 4096

using namespace std;


bool GetXml(char * filename, IXMLDOMDocument3 ** xmlDoc)
{
	VARIANT_BOOL b;
	VARIANT      var;
	bool         bRetVal;
	
	HRESULT hr = CoCreateInstance(__uuidof(DOMDocument60), NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument3, (void**)xmlDoc);
	if (FAILED(hr))
		return false;

	// don't valide on parse
	(*xmlDoc)->put_validateOnParse(VARIANT_TRUE);
	// asynchrnous processing not permited
	(*xmlDoc)->put_async(VARIANT_FALSE);
	// resolve externals during loading
	(*xmlDoc)->put_resolveExternals(VARIANT_TRUE);
	// white spaces
	(*xmlDoc)->put_preserveWhiteSpace(VARIANT_FALSE);


	IXMLDOMSchemaCollection * schemaPtr;
	hr = CoCreateInstance(__uuidof(XMLSchemaCache60), NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMSchemaCollection, (void**)&schemaPtr);
	if (FAILED(hr))
	{
		(*xmlDoc)->Release();
		(*xmlDoc) = NULL;
		return false;
	}
	hr = schemaPtr->add(_bstr_t("http://www.johnysparadise.ic.cz/pokus"), _variant_t("IptXml.xsd"));
	if (FAILED(hr))
	{
		(*xmlDoc)->Release();
		schemaPtr->Release();
		return false;
	}
	(*xmlDoc)->putref_schemas(variant_t((IUnknown*)schemaPtr));



	VariantInit(&var);
	V_BSTR(&var) = SysAllocString(_bstr_t(filename));
	V_VT(&var)   = VT_BSTR;
	hr = (*xmlDoc)->load(var, &b);
	VariantClear(&var);
		
	bRetVal = (SUCCEEDED(hr) && (b == VARIANT_TRUE));

	if (!bRetVal)
	{
		IXMLDOMParseError* pErr;
		(*xmlDoc)->get_parseError(&pErr);
		if (pErr != NULL)
		{
			BSTR errDesc;
			pErr->get_reason(&errDesc);
			const char* pstr = _com_util::ConvertBSTRToString(errDesc);
			cout << pstr << endl;
			pErr->Release();
		}

		(*xmlDoc)->Release();
		(*xmlDoc) = NULL;
		return bRetVal;
	}

	return bRetVal;
}

bool GetNodeValue(IXMLDOMNode* node, _bstr_t& bstr, _bstr_t& val)
{
	BSTR text;

	if (node == NULL)
		return false;

	if (bstr == _bstr_t(""))
	{
		node->get_text(&text);
		val.Assign(text);
		return true;
	}

	IXMLDOMNode* n = NULL;
	node->selectSingleNode(bstr, &n);
	if (n != NULL)
	{
		n->get_text(&text);
		val.Assign(text);
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char* argv[])
{
	IXMLDOMDocument3 * xmlDoc;

	CoInitialize(NULL);
	if (!GetXml("IptXml.xml", &xmlDoc))
	{
		cout << "Cannot read the file!" << endl;
		system("PAUSE");
		return 0;
	}

	IXMLDOMSchemaCollection * schCol;
	HRESULT hr = xmlDoc->get_namespaces(&schCol);
	if (FAILED(hr))
	{
		cout << "Could not get the schema collection." << endl;
		return 0;
	}

	long schemaCnt;
	hr = schCol->get_length(&schemaCnt);
	if (SUCCEEDED(hr))
	{
		cout << "Schamas (" << schemaCnt << "):" << endl;
		for (int i=0; i<schemaCnt; i++)
		{
			BSTR ns;
			char pom[200];
			schCol->get_namespaceURI(i, &ns);
			char *p= _com_util::ConvertBSTRToString(ns);
			strcpy(pom, p);
			cout << "\t" << pom << endl;
		}
		cout << endl;
	}
	schCol->Release();

	xmlDoc->setProperty(_bstr_t("SelectionNamespaces"), variant_t(_bstr_t("xmlns:bk='http://www.johnysparadise.ic.cz/pokus'")));

	IXMLDOMNodeList* nodeList = NULL;
	IXMLDOMElement*  root     = NULL;
	IXMLDOMNode*     node     = NULL;
	long			 len      = 0;

	xmlDoc->get_documentElement(&root);
	root->selectNodes(_bstr_t(L"/bk:Database/bk:Movie[bk:Year = 1998]"), &nodeList);
	nodeList->nextNode(&node);
	nodeList->get_length(&len);
	cout << "Celkem: " << len << endl;
	while (node != NULL)
	{
		_bstr_t name;
		if (GetNodeValue(node, _bstr_t("bk:Name"), name))
		{
			cout << "\t" << name << endl;
		}

		nodeList->nextNode(&node);
	}

	VARIANT v;
	VariantInit(&v);
	V_BSTR(&v) = SysAllocString(L"D:\\pokus.xml");
	V_VT(&v)   = VT_BSTR;
	xmlDoc->save(v);
	VariantClear(&v);

	CoUninitialize();
	system("PAUSE");
	return 0;
}

