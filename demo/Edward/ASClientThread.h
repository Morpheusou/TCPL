#ifndef ASClientThread_h__
#define ASClientThread_h__

#pragma once

#include "ASThread.h"

class ASClientThread : public ASThread
{
public:
	ASClientThread(void);
	ASClientThread(int socket);
	~ASClientThread(void);

	virtual void innerThreadImplemtation();

private:
	int m_socket;
	bool m_isLogin;
};

#endif // ASClientThread_h__
