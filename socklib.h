#ifndef SOCKLIB_H
#define SOCKLIB_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
class socket_class
{
	int sfd;
	struct sockaddr_un s;
public:	
	socket_class() = default;
	void create_socket();
	void close_socket();
	~socket_class();
};
#endif
