#include "socklib.h"

socket_class::~socket_class()
{
	sfd = -1;
}

void socket_class::create_socket()
{
	errno = 0;
	sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if (sfd == -1)
	{
		perror("void socket_class::create_socket()\n");
		exit(1);
	}
}

void socket_class::close_socket()
{
	errno = 0;
	auto res = close(sfd);
	if (res == -1)
	{
		perror("void socket_class::close_socket()\n");
		exit(2);
	}
}

