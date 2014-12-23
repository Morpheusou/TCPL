#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
const int PORT_NUM = 10000;

int echo_server()
{
	struct sockaddr_in addr;
	int addr_len = sizeof(addr);
	char buf[256];
	int n_handle;

	int s_handle = socket (PF_UNIX, SOCK_DGRAM, 0);
	if (s_handle == -1) return -1;

	addr.sin_family = AF_INET;
	addr.sin_port = PORT_NUM;
	addr.sin_addr.s_addr = INADDR_ANY;

	if (bind (s_handle, (struct sockaddr *) &addr, sizeof addr) == -1)
		return -1;

	if (n_handle = accept (s_handle, (struct sockaddr *) &addr, &addr_len) != -1) {
		int n;
		while ((n = read (s_handle, buf, sizeof buf)) > 0)
			write (n_handle, buf, n);
		close(n_handle);
	}
	return 0;
}

int main()
{
	echo_server();
	return 0;
}
