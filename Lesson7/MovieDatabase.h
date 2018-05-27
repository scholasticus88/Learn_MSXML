#pragma once

#include <vector>
#include "Movie.h"

class CMovieDatabase : public std::vector<CMovie*>
{
public:
	CMovieDatabase(void);
	~CMovieDatabase(void);
};
