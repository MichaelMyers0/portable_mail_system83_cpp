#include "socklib.h"
namespace constants_space
{
	enum {datagram_cap = 512};
};
int main()
{
	socket_class s;
	struct sockaddr_un sun, dest;
	const char* path = "client_socket", *dest_path = "server_socket";
	char datagram[constants_space::datagram_cap] = "Hello, from client\n";

	sun.sun_family = AF_UNIX;
	strcpy(sun.sun_path, path);
	auto len = strlen(sun.sun_path);
	*(sun.sun_path + len) = 0;
	auto slen = sizeof(sun);

	dest.sun_family = AF_UNIX;
	strcpy(dest.sun_path, dest_path);
	len = strlen(dest.sun_path);
	*(dest.sun_path + len) = 0;
	slen = sizeof(dest);

	s.create_socket();
	s.bind_socket((const struct sockaddr*)&sun, slen);
	len = strlen(datagram);
	*(datagram + len) = 0;
	s.send_datagram((const struct sockaddr*)&dest, datagram, len, slen);
	s.close_socket();
	s.delete_socket_file(path);

	exit(0);
}
