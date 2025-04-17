#ifndef SOCKLIB_H
#define SOCKLIB_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string>
#include <cstring>
class socket_class
{
	int sfd;
	struct sockaddr_un s;
public:	
	socket_class() = default;
	void create_socket();
	void bind_socket(const struct sockaddr* addr, socklen_t slen);
	void send_datagram(const struct sockaddr* addr, const std::string& datagram, size_t len, socklen_t slen);
	void recieve_datagram(char* datagram, int len);
	void close_socket();
	void delete_socket_file(const std::string& fname);
	~socket_class();
};
#endif
