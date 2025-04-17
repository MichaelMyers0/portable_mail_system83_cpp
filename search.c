#include "search.h"

void search::open_dir(DIR*& dirp, const char* path)
{

	errno = 0;
	dirp = opendir(path);
	if (!dirp)
	{
		perror("void search::open_dir()\n");
		exit(1);
	}
}

void search::close_dir(DIR* dirp)
{
	errno = 0;
	auto res = closedir(dirp);
	if (res == -1)
	{
		perror("void search::close_dir()\n");
		exit(2);
	}
}

void search::run_search(const char* start, const char* name, char* path)
{
	DIR* dirp;
	struct dirent* ent;
	open_dir(dirp, start);
	while ((ent = readdir(dirp)))
	{
		if (0 == strcmp(ent->d_name, ".") || 0 == strcmp(ent->d_name, ".."))
			continue;
		if (ent->d_type == DT_DIR && 0 == strcmp(ent->d_name, name))
		{
			strcpy(path, start);
			auto len = strlen(path);
			*(path + len) = back_slash;
			strcat(path, name);
			break;
		}
	}
	close_dir(dirp);
}
