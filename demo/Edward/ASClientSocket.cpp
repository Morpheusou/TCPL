#include "ASClientSocket.h"
#include "ASConfig.h"
#include "ASClientThread.h"

#if defined(_WIN32) || defined(__WIN32__) || defined(_MSC_VER)
	#include "pthread/pthread.h"
#else
	#include "pthread.h"
#endif

ASClientSocket::ASClientSocket(void)
{
}


ASClientSocket::~ASClientSocket(void)
{
}

bool ASClientSocket::startClientSocket( std::string address )
{
	CCLOG("Edward %s", "ASClientSocket startClientSocket");
	int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in serverAddr;
	serverAddr.sin_addr.s_addr = inet_addr(address.c_str());  
	serverAddr.sin_family = AF_INET;  
	serverAddr.sin_port = htons(SERVER_PORT);
	int status = connect(clientSocket, (sockaddr*)&serverAddr, sizeof(sockaddr)); 

	if (-1 == status) 
	{
		CCLOG("Edward %s", "ASClientSocket connect failed!");
	}

	ASThread *thread = new ASClientThread(clientSocket);
	thread->startASThread();
	return true;
}

//void * clientReceive( void* arg )
//{
//	ServerInfo info = *(ServerInfo*)arg;
//	sockaddr_in serverAddr;
//	int len = sizeof(serverAddr);
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(SERVER_PORT);
//	serverAddr.sin_addr.s_addr = inet_addr(info.serverAddress.c_str());
//
//	char *buffer = new char[AS_SOCKET_BUFFER];
//	bool login = false;
//	while(true) 
//	{
//		memset(buffer, 0, sizeof(buffer));
//		recvfrom(info.socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&serverAddr, &len);
//		if (!login) 
//		{
//			memset(buffer, 0, sizeof(buffer));
//			sendto(info.socket, buffer, AS_SOCKET_BUFFER, 0, (sockaddr*)&serverAddr, len);
//		}
//	}
//}
