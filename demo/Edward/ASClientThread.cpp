#include "ASClientThread.h"
#include "ASConfig.h"

#if defined(_WIN32) || defined(__WIN32__) || defined(_MSC_VER)
	#include "pthread/pthread.h"
#else
	#include "pthread.h"
#endif

ASClientThread::ASClientThread(void)
{
}

ASClientThread::ASClientThread( int socket )
{
	m_socket = socket;
	m_isStoped = m_isLogin = false;
}


ASClientThread::~ASClientThread(void)
{
}

void ASClientThread::innerThreadImplemtation()
{
	char buffer[AS_SOCKET_BUFFER];
	while(!m_isStoped) 
	{
		if (!m_isLogin)
		{
			m_isLogin = true;
			send(m_socket, "send_client", 12, 0);
		} else {
			send(m_socket, "conn_client", 12, 0);
		}
		memset(buffer, 0, sizeof(buffer));
		recv(m_socket, buffer, sizeof(buffer), 0);
		if (strcmp("send_server", buffer))
		{

		}
	}
}
