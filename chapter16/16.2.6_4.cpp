#include <iostream>
using namespace std;

struct X {
	explicit X();
	explicit X(int, int);
};

X::X()
{
	cout << "constructor without parameter" << endl;
}

X::X(int a, int b)
{
	cout << "constructor with two parameter" << endl;
}

int main()
{
	X x1 = {};  //error: implicit
//	X x2 = {1, 2}; // error: implicit

	X x3 {}; // OK: explicit
	X x4 {1, 2}; //OK: explicit

	int f(X);

	int i1 = f({}); //error: implicit
//	int i2 = f({1, 2}); // error: implicit

	int i3 = f(X{}); // OK: explicit
	int i4 = f(X{1, 2}); // OK: explicit
	return 0;
}
