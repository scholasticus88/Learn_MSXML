#pragma once

#include <vector>
#include "Actor.h"

using namespace std;

class CMovie
{
private:
	char m_pszName[MAX_NAME_LEN];
	int  m_iYear;
	bool m_bOver18;
	vector<CActor*>* m_pActrList;
	char m_pszMedium[MAX_NAME_LEN];

public:
	CMovie(void);
	~CMovie(void);

	const char* GetName() const;
	void SetName(const char* name);
	int GetYear() const;
	void SetYear(int year);
	bool IsOver18() const;
	void SetOver18(bool bOver18);
	void AddActor(CActor* pActor);
	const char* GetMedium() const;
	void SetMedium(const char* medium);
};


