#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
class search
{
	void open_dir(DIR*& dirp, const char* path);
	void close_dir(DIR* dirp);
	char back_slash = '/';
public:	
	search() = default;
	void run_search(const char* start, const char* name, char* path);
	~search() = default;
};
#endif
