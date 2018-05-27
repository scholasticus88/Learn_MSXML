#include "MovieDatabase.h"

CMovieDatabase::CMovieDatabase(void)
{

}

CMovieDatabase::~CMovieDatabase(void)
{
	for (int i=0; i<this->size(); i++)
	{
		CMovie* ptr = at(i);
		if (ptr)
			delete ptr;
	}
}
