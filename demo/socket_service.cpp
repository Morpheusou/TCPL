#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int Service(){
	int sockfd, newsockfd, portno, clilen;	
	char buffer[256] = {0};
	struct sockaddr_in serv_addr, cli_addr;
	int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		perror("ERROR opening socket");
		exit(1);
	}	

	bzero((char*)&serv_addr, sizeof(serv_addr));
	portno = 5001;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if(bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("ERROR on binding");
		exit(1);
	}

	listen(sockfd, 5);
	clilen = sizeof(cli_addr);
	while(1)
	{
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, ((socklen_t*)&clilen));
		if (newsockfd < 0)
		{
			perror("ERROR on accept");
			exit(1);
		}
		n = read(newsockfd, buffer, 255);
		if (n < 0)
		{
			perror("ERROR reading from socket");
			exit(1);
		}
		printf("Here is the mesage: %s\n", buffer);
		n = write(newsockfd, "I got your message", 18);

		if (n < 0)
		{
			perror("ERROR writing to socket");
			exit(1);
		}
	}
}
int main()
{
	Service();
	
	return 0;
}
