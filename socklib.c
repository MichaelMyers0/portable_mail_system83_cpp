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

void socket_class::bind_socket(const struct sockaddr* addr, socklen_t slen)
{
	errno = 0;
	auto res = bind(sfd, addr, slen);
	if (res == -1)
	{
		perror("void socket_class::bind_socket()\n");
		exit(2);
	}
}

void socket_class::send_datagram(const struct sockaddr* addr, const char* datagram, size_t len, socklen_t slen)
{
	errno = 0;
	auto cnt = sendto(sfd, datagram, len, 0, addr, slen);
	if (cnt == -1)
	{
		perror("void socket_class::send_datagram()\n");
		exit(3);
	}
}

void socket_class::recieve_datagram(char* datagram, int len)
{
	errno = 0;
	auto cnt = recvfrom(sfd, datagram, len, 0, NULL, NULL);
	if (cnt == -1)
	{
		perror("void socket_class::recieve_datagram()\n");
		exit(4);
	}
}

void socket_class::close_socket()
{
	errno = 0;
	auto res = close(sfd);
	if (res == -1)
	{
		perror("void socket_class::close_socket()\n");
		exit(5);
	}
}

void socket_class::delete_socket_file(const char* fname)
{
	errno = 0;
	auto res = unlink(fname);
	if (res == -1)
	{
		perror("void socket_class::delete_socket_file()\n");
		exit(6);
	}
}
