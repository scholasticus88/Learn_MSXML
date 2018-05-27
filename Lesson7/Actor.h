#pragma once

#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define MAX_NAME_LEN 30

class CActor
{
private:
	char m_pszName[MAX_NAME_LEN];

public:
	CActor(void);
	~CActor(void);

	const char* GetName() const;
	void SetName(const char* name);
};
