#include "Actor.h"

CActor::CActor(void)
{
	memset(m_pszName, 0, MAX_NAME_LEN);
}

CActor::~CActor(void)
{

}

const char* CActor::GetName() const
{
	return m_pszName;
}

void CActor::SetName(const char* name)
{
	strncpy(m_pszName, name, MAX_NAME_LEN);
}