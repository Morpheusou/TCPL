#include <string>
using namespace std;

void (*pf)(string);
void f1(string);
int f2(string);
void f3(int*);
void f()
{
	pf = &f1;
//	pf = &f2;
//	pf = &f3;

	pf("Hera");
//	pf(1);

//	int i = pf("Zeus");
}
