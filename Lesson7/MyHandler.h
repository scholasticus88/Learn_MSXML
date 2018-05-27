#pragma once

#include "Movie.h"
#include "MovieDatabase.h"


#import <msxml6.dll> 

using namespace MSXML2;

/////////////////////////////////////////////////
//
//  CMyContentHandler
//     - implements ISAXContentHandler
//     - handles all events from SAXReader
//
/////////////////////////////////////////////////

class CMyContentHandler : public MSXML2::ISAXContentHandler
{
private:
	typedef enum
	{
		ELT_NONE,
		ELT_DATABASE,
		ELT_ACTOR_NAME,
		ELT_MOVIE,
		ELT_MOVIE_NAME,
		ELT_MOVIE_OVER18,
		ELT_MOVIE_YEAR
	} ELEMENT_TYPE;
	
	long			 m_lCount;
	ELEMENT_TYPE	 m_currentElement;
	CActor*			 m_pCurrentActor;
	CMovie*          m_pCurrentMovie;
	CMovieDatabase*  m_pDatabase;
	bool			 m_bPrepared;

	CMyContentHandler::ELEMENT_TYPE GetElementType(const char* elem);

public:
	CMyContentHandler(void);
	virtual ~CMyContentHandler(void);

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, __RPC__deref_out void __RPC_FAR *__RPC_FAR *ppvObject);
    ULONG STDMETHODCALLTYPE AddRef(void);
    ULONG STDMETHODCALLTYPE Release(void);

	HRESULT putDocumentLocator(struct MSXML2::ISAXLocator * pLocator);
    HRESULT startDocument();
    HRESULT endDocument();
    HRESULT startPrefixMapping(unsigned short * pwchPrefix, int cchPrefix, unsigned short * pwchUri, int cchUri);
    HRESULT endPrefixMappin(unsigned short * pwchPrefix, int cchPrefix);
    HRESULT startElement(unsigned short * pwchNamespaceUri, int cchNamespaceUri, unsigned short * pwchLocalName,
		                 int cchLocalName, unsigned short * pwchQName, int cchQName, struct MSXML2::ISAXAttributes * pAttributes);
    HRESULT endElement(unsigned short * pwchNamespaceUri, int cchNamespaceUri, unsigned short * pwchLocalName,
                       int cchLocalName, unsigned short * pwchQName, int cchQName);
    HRESULT characters(unsigned short * pwchChars, int cchChars);
    HRESULT ignorableWhitespace(unsigned short * pwchChars, int cchChars);
    HRESULT processingInstruction(unsigned short * pwchTarget, int cchTarget, unsigned short * pwchData, int cchData);
    HRESULT skippedEntity(unsigned short * pwchName, int cchName);

	CMovieDatabase* Detach();
	bool            IsDataPrepared() const;

private:
	virtual HRESULT __stdcall raw_putDocumentLocator(
		/*[in]*/ struct MSXML2::ISAXLocator * pLocator);
	virtual HRESULT __stdcall raw_startDocument( );
	virtual HRESULT __stdcall raw_endDocument( );
	virtual HRESULT __stdcall raw_startPrefixMapping(
		/*[in]*/ unsigned short * pwchPrefix,
		/*[in]*/ int cchPrefix,
		/*[in]*/ unsigned short * pwchUri,
		/*[in]*/ int cchUri);
	virtual HRESULT __stdcall raw_endPrefixMapping(
		/*[in]*/ unsigned short * pwchPrefix,
		/*[in]*/ int cchPrefix);
	virtual HRESULT __stdcall raw_startElement(
		/*[in]*/ unsigned short * pwchNamespaceUri,
		/*[in]*/ int cchNamespaceUri,
		/*[in]*/ unsigned short * pwchLocalName,
		/*[in]*/ int cchLocalName,
		/*[in]*/ unsigned short * pwchQName,
		/*[in]*/ int cchQName,
		/*[in]*/ struct MSXML2::ISAXAttributes * pAttributes);
	virtual HRESULT __stdcall raw_endElement(
		/*[in]*/ unsigned short * pwchNamespaceUri,
		/*[in]*/ int cchNamespaceUri,
		/*[in]*/ unsigned short * pwchLocalName,
		/*[in]*/ int cchLocalName,
		/*[in]*/ unsigned short * pwchQName,
		/*[in]*/ int cchQName);
	virtual HRESULT __stdcall raw_characters(
		/*[in]*/ unsigned short * pwchChars,
		/*[in]*/ int cchChars);
	virtual HRESULT __stdcall raw_ignorableWhitespace(
		/*[in]*/ unsigned short * pwchChars,
		/*[in]*/ int cchChars);
	virtual HRESULT __stdcall raw_processingInstruction(
		/*[in]*/ unsigned short * pwchTarget,
		/*[in]*/ int cchTarget,
		/*[in]*/ unsigned short * pwchData,
		/*[in]*/ int cchData);
	virtual HRESULT __stdcall raw_skippedEntity(
		/*[in]*/ unsigned short * pwchName,
		/*[in]*/ int cchName);
};
