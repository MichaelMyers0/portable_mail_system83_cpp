#include <signal.h>
#include <fcntl.h>
#include "socklib.h"
#include "search.h"
namespace constants_space
{
	enum {datagram_cap = 512};
	enum {sleep_t = 10};
};
typedef void (*handler_t)(int);
static volatile sig_atomic_t flag = 0; 
static void handler(int sig)
{
	flag = 1;
}
int main()
{
	socket_class s;
	struct sockaddr_un sun;
	const std::string path("server_socket");
	char datagram[constants_space::datagram_cap], ppath[constants_space::datagram_cap / 2];
	handler_t new_handler;
	search ss;
	bool is_recieved = false;

	new_handler = handler;
	errno = 0;
	auto old_handler = signal(SIGALRM, new_handler);
	if (old_handler == SIG_ERR)
	{
		perror("server signal()\n");
		exit(1);
	}

	sun.sun_family = AF_UNIX;
	strcpy(sun.sun_path, path.data());
	auto len = strlen(sun.sun_path);
	*(sun.sun_path + len) = 0;
	auto slen = sizeof(sun);

	s.create_socket();
	s.bind_socket((const struct sockaddr*)&sun, slen);
	sleep(constants_space::sleep_t);
	alarm(constants_space::sleep_t);
	for (;;)
	{
		s.recieve_datagram(datagram, constants_space::datagram_cap);
		len = strlen(datagram);
		if (!flag && len)
		{
			printf("datagram - %s\n", datagram);
			len = strlen(datagram);
			*(datagram + len) = 0;
			ss.run_search(".", datagram, ppath);
			is_recieved = true;
			break;
		}
		if (flag)
		{
			printf("Warning: Time has expired\n");
			break;
		}
	}
	if (is_recieved)
	{
		printf("%s\n", ppath);
		strcat(ppath, "/");
		strcpy(ppath, "t___t");
		printf("DEBUG_PRINT = %s\n", ppath);
		errno = 0;
		auto fd = open(ppath, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		if (fd == -1)
		{
			perror("failed to create a file");
			exit(2);
		}
		close(fd);
	}
	s.close_socket();
	s.delete_socket_file(path);
	exit(0);
}
