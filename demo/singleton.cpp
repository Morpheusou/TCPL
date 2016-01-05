#include <iostream>

//---------A---------------
class singleton
{
public:
	static singleton *Instance() { return &_instance;}
	int GetCount() { return _refCount; }
private:
	int _refCount;
	static singleton _instance;
};

//----------B--------------
class singleton
{
public:
	static singleton& Instance() {return _instance;}
	int GetCount() { return _refCount; }
private:
	static const int _maxRefCount = 100;
	int _refCount;
	static singleton _instance;
};

//----------C--------------
class singleton
{
public:
	static singleton Instance() { return _instance; }
	int getCount() { return _refCount; }
private:
	int _refCount;
	static singleton _instance;
};

//----------D--------------
class singleton
{
public:
	static singleton Instance() { return _instance; }
	int getCount() { return _refCount; }
private:
	int _refCount;
	singleton _instance;
};

//----------E---------------
class singleton
{
public:
	static singleton *Instance() { 
		_instance = new singleton;
	}
private:
	int _refCount;
	singleton * _instance;
};

//----------F---------------
class singleton
{
public:
	static singleton *Instance() {
		if (_instance == 0) {
			_instance = new singleton;
			_refCount = 1;
		} else {
			++_refCount;
		}
	}
private:
	int _refCount;
	static singleton * _instance;
};
singleton * singleton::_instance = 0;

int main()
{
	int count = singleton::Instance()->GetCount();
	return 0;
}
