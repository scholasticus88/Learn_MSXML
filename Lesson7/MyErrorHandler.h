#ifndef __MY_ERROR_HANDLER__

#define __MY_ERROR_HANDLER__

#import <msxml6.dll> 

using namespace MSXML2;

/////////////////////////////////////////////////
//
//  CMyContentHandler
//     - implements ISAXContentHandler
//     - handles all events from SAXReader
//
/////////////////////////////////////////////////

class CMyErrorHandler : public MSXML2::ISAXErrorHandler
{
private:
	long			 m_lCount;

public:
	CMyErrorHandler(void);
	virtual ~CMyErrorHandler(void);

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, __RPC__deref_out void __RPC_FAR *__RPC_FAR *ppvObject);
    virtual ULONG STDMETHODCALLTYPE AddRef(void);
    virtual ULONG STDMETHODCALLTYPE Release(void);

	virtual HRESULT __stdcall raw_error (
        /*[in]*/ struct ISAXLocator * pLocator,
        /*[in]*/ unsigned short * pwchErrorMessage,
        /*[in]*/ HRESULT hrErrorCode );
    virtual HRESULT __stdcall raw_fatalError (
        /*[in]*/ struct ISAXLocator * pLocator,
        /*[in]*/ unsigned short * pwchErrorMessage,
        /*[in]*/ HRESULT hrErrorCode );
    virtual HRESULT __stdcall raw_ignorableWarning (
        /*[in]*/ struct ISAXLocator * pLocator,
        /*[in]*/ unsigned short * pwchErrorMessage,
        /*[in]*/ HRESULT hrErrorCode );
};

#endif