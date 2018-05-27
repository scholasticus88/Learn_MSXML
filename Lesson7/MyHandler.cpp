#include "MyHandler.h"
#include <iostream>

using namespace std;

CMyContentHandler::CMyContentHandler(void)
{
	m_currentElement = ELT_NONE;
	m_pDatabase      = NULL;
	m_pCurrentMovie  = NULL;
	m_pCurrentActor  = NULL;
	m_bPrepared		 = false;
}

CMyContentHandler::~CMyContentHandler(void)
{
	if (m_pDatabase)
		delete m_pDatabase;
}

HRESULT STDMETHODCALLTYPE CMyContentHandler::QueryInterface(REFIID riid, void** ppvObject)
{
	if (riid == __uuidof(ISAXContentHandler))
	{
		*ppvObject = static_cast<ISAXContentHandler*>(this);
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

ULONG STDMETHODCALLTYPE CMyContentHandler::AddRef(void)
{
	return InterlockedIncrement(&m_lCount);
}
    
ULONG STDMETHODCALLTYPE CMyContentHandler::Release(void)
{
	long l = InterlockedDecrement(&m_lCount);
	if (l == 0)
		delete this;
	return l;
}

HRESULT CMyContentHandler::putDocumentLocator(struct MSXML2::ISAXLocator * pLocator)
{
	return this->raw_putDocumentLocator(pLocator);
}

HRESULT CMyContentHandler::startDocument()
{
	return this->raw_startDocument();
}

HRESULT CMyContentHandler::endDocument()
{
	return this->raw_endDocument();
}

HRESULT CMyContentHandler::startPrefixMapping(unsigned short * pwchPrefix, int cchPrefix, unsigned short * pwchUri, int cchUri)
{
	return this->raw_startPrefixMapping(pwchPrefix, cchPrefix, pwchUri, cchUri);
}

HRESULT CMyContentHandler::endPrefixMappin(unsigned short * pwchPrefix, int cchPrefix)
{
	return this->raw_endPrefixMapping(pwchPrefix, cchPrefix);
}

HRESULT CMyContentHandler::startElement(unsigned short * pwchNamespaceUri, int cchNamespaceUri, unsigned short * pwchLocalName,
                                 int cchLocalName, unsigned short * pwchQName, int cchQName, 
								 struct MSXML2::ISAXAttributes * pAttributes)
{
	return this->raw_startElement(pwchNamespaceUri, cchNamespaceUri, pwchLocalName, cchLocalName, pwchQName, cchQName, pAttributes);
}

HRESULT CMyContentHandler::endElement(unsigned short * pwchNamespaceUri, int cchNamespaceUri, unsigned short * pwchLocalName,
                               int cchLocalName, unsigned short * pwchQName, int cchQName)
{
	return this->raw_endElement(pwchNamespaceUri, cchNamespaceUri, pwchLocalName, cchLocalName, pwchQName, cchQName);
}

HRESULT CMyContentHandler::characters(unsigned short * pwchChars, int cchChars)
{
	return this->raw_characters(pwchChars, cchChars);
}

HRESULT CMyContentHandler::ignorableWhitespace(unsigned short * pwchChars, int cchChars)
{
	return this->raw_ignorableWhitespace(pwchChars, cchChars);
}

HRESULT CMyContentHandler::processingInstruction(unsigned short * pwchTarget, int cchTarget, 
										  unsigned short * pwchData, int cchData)
{
	return this->raw_processingInstruction(pwchTarget, cchTarget, pwchData, cchData);
}

HRESULT CMyContentHandler::skippedEntity(unsigned short * pwchName, int cchName)
{
	return this->raw_skippedEntity(pwchName, cchName);
}

HRESULT __stdcall CMyContentHandler::raw_putDocumentLocator(struct MSXML2::ISAXLocator * pLocator )
{
	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_startDocument()
{
	cout << "----- START OF DOCUMENT -----" << endl;
	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_endDocument()
{
	cout << "----- END OF DOCUMENT -----" << endl;
	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_startPrefixMapping(unsigned short * pwchPrefix, int cchPrefix, unsigned short * pwchUri, int cchUri)
{
	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_endPrefixMapping(unsigned short * pwchPrefix, int cchPrefix)
{
	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_startElement(unsigned short * pwchNamespaceUri, int cchNamespaceUri, unsigned short * pwchLocalName,
								   int cchLocalName, unsigned short * pwchQName, int cchQName, struct MSXML2::ISAXAttributes * pAttributes)
{
	char* elem = _com_util::ConvertBSTRToString(_bstr_t((wchar_t*)pwchLocalName));
	m_currentElement = GetElementType(elem); 
	switch (m_currentElement)
	{
		case ELT_DATABASE:
			m_pDatabase = new CMovieDatabase();
			break;
		case ELT_MOVIE:
			{
				wchar_t* name  = NULL;
				int      len   = 0;
				int      ind   = 0; 
				m_pCurrentMovie = new CMovie();
				try
				{
					ind = pAttributes->getIndexFromName((unsigned short*)TEXT(""), 0, (unsigned short*)TEXT("medium"), 6);
					pAttributes->getValue(ind, (unsigned short**)&name, &len);
					m_pCurrentMovie->SetMedium(_com_util::ConvertBSTRToString(name));
				} catch (...) { }
			}
			break;
		case ELT_ACTOR_NAME:
			m_pCurrentActor = new CActor();
			break;
	}

	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_endElement(unsigned short * pwchNamespaceUri, int cchNamespaceUri, unsigned short * pwchLocalName,
										 int cchLocalName, unsigned short * pwchQName, int cchQName)
{
	char* elem = _com_util::ConvertBSTRToString(_bstr_t((wchar_t*)pwchLocalName));
	m_currentElement = GetElementType(elem); 
	switch (m_currentElement)
	{
		case ELT_MOVIE:
			{
				if (m_pDatabase)
				{
					m_pDatabase->insert(m_pDatabase->end(), m_pCurrentMovie);
					m_pCurrentMovie = NULL;
				} else {
					cout << "Database is null !!!" << endl;
				}
			}
			break;
		case ELT_ACTOR_NAME:
			{
				if (m_pCurrentMovie)
				{
					m_pCurrentMovie->AddActor(m_pCurrentActor);
					m_pCurrentActor = NULL;
				} else {
					cout << "Current movie is NULL!" << endl;
				}
			}
			break;
		case ELT_DATABASE:
			m_bPrepared = true;
			break;
	}
	
	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_characters(unsigned short * pwchChars, int cchChars)
{
	char* elem = _com_util::ConvertBSTRToString(_bstr_t((wchar_t*)pwchChars));
	m_currentElement = GetElementType(elem); 
	
	switch (m_currentElement)
	{
		case ELT_MOVIE_NAME:
			m_pCurrentMovie->SetName(elem);
			break;
		case ELT_MOVIE_YEAR:
			m_pCurrentMovie->SetYear(atoi(elem));
			break;
		case ELT_MOVIE_OVER18:
			{
				if (strcmp(elem, "yes") == 0)
					m_pCurrentMovie->SetOver18(true);
				else if (strcmp(elem, "no") == 0) 
					m_pCurrentMovie->SetOver18(false);
				else throw "Invalid value !";
			}
			break; 
		case ELT_ACTOR_NAME:
			m_pCurrentActor->SetName(elem);
			break;
	}

	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_ignorableWhitespace(unsigned short * pwchChars, int cchChars)
{
	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_processingInstruction(unsigned short * pwchTarget, int cchTarget, unsigned short * pwchData, int cchData)
{
	return S_OK;
}

HRESULT __stdcall CMyContentHandler::raw_skippedEntity(unsigned short * pwchName, int cchName)
{
	return S_OK;
}

CMyContentHandler::ELEMENT_TYPE CMyContentHandler::GetElementType(const char* elem)
{
	if (strcmp(elem, "Database") == 0)
		return ELT_DATABASE;
	if (strcmp(elem, "Movie") == 0)
		return ELT_MOVIE;
	if (strcmp(elem, "Actor") == 0)
		return ELT_ACTOR_NAME;
	if (strcmp(elem, "Name") == 0)
		return ELT_MOVIE_NAME;
	if (strcmp(elem, "Year") == 0)
		return ELT_MOVIE_YEAR;
	if (strcmp(elem, "Over18") == 0)
		return ELT_MOVIE_OVER18;
	return ELT_NONE;
}

CMovieDatabase* CMyContentHandler::Detach()
{
	CMovieDatabase* pRetVal = m_pDatabase;
	m_pDatabase = NULL;
	return pRetVal;
}

bool CMyContentHandler::IsDataPrepared() const
{
	return m_bPrepared;
}