#include <iostream>
using namespace std;

class base {
public:
	base(){ cout << "base ctor" << endl; }
	virtual void print() { cout << "base::print" << endl; }

	virtual ~base() { cout << "~base" << endl; }
};

class derive : public base
{
public:
	derive(){ cout << "derive ctor" << endl; }
	
	virtual void print() { cout << "derive::print" << endl; }

	virtual ~derive(){ cout << "~derive" << endl; }
};

int main()
{
	base* b = new derive();
	delete b;
	return 0;
}
