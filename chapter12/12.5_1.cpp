#include <string>
using namespace std;

void error(string s) {};

void (*efct) (string);

void f()
{
	efct = &error;
	efct("error");
}

void (*f1) (string) = &error;
void (*f2) (string) = error;

void g()
{
	f1("Vasa");
	(*f2)("Mary Rose");
}
