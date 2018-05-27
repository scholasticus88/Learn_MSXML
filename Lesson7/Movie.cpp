#include "Movie.h"

CMovie::CMovie(void)
{
	memset(m_pszName, 0, MAX_NAME_LEN);
	memset(m_pszMedium, 0, MAX_NAME_LEN);
	m_bOver18   = true;
	m_iYear     = 0;
	m_pActrList = NULL;
}

CMovie::~CMovie(void)
{
	if (m_pActrList)
	{
		for (int i=0; i<m_pActrList->size(); i++)
		{
			CActor* pAct = m_pActrList->at(i);
			if (pAct)
				delete pAct;
		}
		delete m_pActrList;
	}
}

const char* CMovie::GetName() const
{
	return m_pszName;
}

void CMovie::SetName(const char* name)
{
	strncpy(m_pszName, name, MAX_NAME_LEN);
}

const char* CMovie::GetMedium() const
{
	return m_pszMedium;
}

void CMovie::SetMedium(const char* medium)
{
	strncpy(m_pszMedium, medium, MAX_NAME_LEN);
}

int CMovie::GetYear() const
{
	return m_iYear;
}

void CMovie::SetYear(int year)
{
	m_iYear = year;
}

bool CMovie::IsOver18() const
{
	return m_bOver18;
}

void CMovie::SetOver18(bool bOver18)
{
	m_bOver18 = bOver18;
}

void CMovie::AddActor(CActor* pActor)
{
	if (m_pActrList == NULL)
		m_pActrList = new vector<CActor*>();

	m_pActrList->insert(m_pActrList->end(), pActor);
}



