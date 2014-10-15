#include <pthread.h>
#include <iostream>
using namespace std;

class thread
{
public:
	thread(void) { _isStoped = false; }
	virtual ~thread(void) {}

	bool startThread()
	{
		return (pthread_create(&_thread, NULL, &threadFunc, this) == 0 );
	}
	void join()
	{
		(void) pthread_join(_thread, NULL);
	}	
protected:
	virtual void threadImplementation() = 0;
private:
	static void* threadFunc(void* th)
	{
		cout <<"Edward %s, thread::threadFunc" << endl;
		((thread*)th)->threadImplementation();
		return NULL;
	}
protected:
	bool _isStoped;
private:
	pthread_t _thread;
};

class mythread : public thread
{
public:
	mythread(void) {}
	~mythread(void) {}
protected:
	virtual void threadImplementation()
	{
		cout << "my thread implementation details" << endl;
	}

};

int main()
{
	mythread athread;
	athread.startThread();
	athread.join();
	thread * pthread = new mythread();
	pthread->startThread();
	pthread->join();
	return 0;
}
