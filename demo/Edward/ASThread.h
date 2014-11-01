#ifndef ASThread_h__
#define ASThread_h__

#include "cocos2d.h"
#if defined(_WIN32) || defined(__WIN32__) || defined(_MSC_VER)
#include "pthread/pthread.h"
#else
#include "pthread.h"
#endif

USING_NS_CC;

class ASThread
{
public:
	ASThread(void) { m_isStoped = false; }
	virtual ~ASThread(void) {}

	bool startASThread()
	{
		return (pthread_create(&_thread, NULL, &innerThreadFunc, this) == 0);
	}

	void waitForThreadToExit()
	{
		(void) pthread_join(_thread, NULL);
	}

protected:
	virtual void innerThreadImplemtation() = 0;

private:
	static void* innerThreadFunc(void* th) { ((ASThread*)th)->innerThreadImplemtation(); return NULL; }

protected:
	bool m_isStoped;

private:
	pthread_t _thread;
};

#endif // ASThread_h__
