#include <iostream>
//#2
int foo (int);
int foo (int, int = 10);
//#3
int divide (double, double);
double divide (double, double);
//#4
class array
{
public:
	char &operator[] (unsigned int);
	const char &operator[] (unsigned int) const;
//...
};
int main()
{
	foo (100);
	foo (100, 101);
	return 0;
}
