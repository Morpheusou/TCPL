#include <iostream>

//---------A---------------
class singleton
{
public:
	static singleton *Instance() { return &_instance;}
private:
	static singleton _instance;
};

//----------B--------------
class singleton
{
public:
	singleton& Instance() {return _instance;}
private:
	static const int _refCount = 100;
	static singleton _instance;
};

//----------C--------------
class singleton
{
public:
	singleton Instance() { return _instance; }
private:
	static singleton _instance;
};

//----------D--------------
class singleton
{
public:
	singleton Instance() { return _instance; }
private:
	singleton _instance;
};

int main()
{
	return 0;
}
