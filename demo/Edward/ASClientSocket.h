#ifndef ASClientSocket_h__
#define ASClientSocket_h__

#include "cocos2d.h"

#pragma once
class ASClientSocket
{
public:
	ASClientSocket(void);
	~ASClientSocket(void);

	bool startClientSocket(std::string address);
};

class ServerInfo
{
public:
	int socket;
	std::string serverAddress;
};

#endif // ASClientSocket_h__
