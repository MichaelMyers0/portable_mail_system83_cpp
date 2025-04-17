#include "socklib.h"
namespace constants_space
{
	enum {datagram_cap = 512};
	enum {sleep_t = 10};
};
int main()
{
	socket_class s;
	struct sockaddr_un sun;
	const std::string path("server_socket");
	char datagram[constants_space::datagram_cap];

	sun.sun_family = AF_UNIX;
	strcpy(sun.sun_path, path.data());
	auto len = strlen(sun.sun_path);
	*(sun.sun_path + len) = 0;
	auto slen = sizeof(sun);

	s.create_socket();
	s.bind_socket((const struct sockaddr*)&sun, slen);
	sleep(constants_space::sleep_t);
	for (;;)
	{
		s.recieve_datagram(datagram, constants_space::datagram_cap);
		len = strlen(datagram);
		if (len)
			break;
	}
	printf("%s\n", datagram);
	s.close_socket();
	s.delete_socket_file(path);

	exit(0);
}
