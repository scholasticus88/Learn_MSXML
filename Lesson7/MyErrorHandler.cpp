#include "MyErrorHandler.h"
#include <iostream>

using namespace std;

CMyErrorHandler::CMyErrorHandler(void)
{
}

CMyErrorHandler::~CMyErrorHandler(void)
{
}

HRESULT STDMETHODCALLTYPE CMyErrorHandler::QueryInterface(REFIID riid, void** ppvObject)
{
	if (riid == __uuidof(ISAXContentHandler))
	{
		*ppvObject = static_cast<ISAXErrorHandler*>(this);
		return S_OK;
	}

	if (riid == __uuidof(IUnknown))
	{
		*ppvObject = static_cast<IUnknown*>(this);
		return S_OK;
	}

	this->AddRef();

	*ppvObject = NULL;
	return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE CMyErrorHandler::AddRef(void)
{
	return InterlockedIncrement(&m_lCount);
}
    
ULONG STDMETHODCALLTYPE CMyErrorHandler::Release(void)
{
	long l = InterlockedDecrement(&m_lCount);
	if (l == 0)
		delete this;
	return l;
}

HRESULT CMyErrorHandler::raw_error(struct ISAXLocator* pLocator, unsigned short* pwchErrorMessage, HRESULT hrErrorCode)
{
	char txt[256] = {0};
	wcstombs(txt, pwchErrorMessage, 256);

	int x = 0;
	int y = 0;
	if (pLocator)
	{
		pLocator->raw_getLineNumber(&x);
		pLocator->raw_getColumnNumber(&y);
	}

	cout << "Je tu error(" << x << ", " << y << "): " << txt << endl;
	return S_OK;
}

HRESULT CMyErrorHandler::raw_fatalError(struct ISAXLocator* pLocator, unsigned short* pwchErrorMessage, HRESULT hrErrorCode)
{
	char txt[256];
	wcstombs(txt, pwchErrorMessage, 256);

	int x = 0;
	int y = 0;
	if (pLocator)
	{
		pLocator->raw_getLineNumber(&x);
		pLocator->raw_getColumnNumber(&y);
	}

	cout << "Je tu fatal error(" << x << ", " << y << "): " << txt << endl;
	return S_OK;	
}

HRESULT CMyErrorHandler::raw_ignorableWarning(struct ISAXLocator* pLocator, unsigned short* pwchErrorMessage, HRESULT hrErrorCode)
{
	char txt[256];
	wcstombs(txt, pwchErrorMessage, 256);

	int x = 0;
	int y = 0;
	if (pLocator)
	{
		pLocator->raw_getLineNumber(&x);
		pLocator->raw_getColumnNumber(&y);
	}

	cout << "Je tu ignorable warning: " << x << ", " << y << "): " << txt << endl;
	return S_OK;		
}