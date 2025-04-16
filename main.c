#include "socklib.h"
int main()
{
	socket_class s;
	s.create_socket();
	s.close_socket();
	exit(0);
}
