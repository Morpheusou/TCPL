#include <string>
using namespace std;

string indent(string arg)
{
	return arg;
}

typedef int someType;

class X {
	X(someType);
	X();
	X(const X&);
	X(X&&);
	X& operator=(const X&);
	X& operator=(X&&);
	~X();
};
int main()
{
	string s1 {"Adams"};
	s1 = indent(s1);
	
	string s2 {"Pratchett"};
	s1 = s2;
}
