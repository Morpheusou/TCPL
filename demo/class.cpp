#include <iostream>

class number {
public:
	double re, im;
};

class complex : number {
	double re, im; // representation: two double
public:
	complex(double r, double i):re(r), im(i) {}
        // other operator

};

struct complex : number {
	double re, im;
public:
	complex (double r, double i):re(r), im(i) {}
	// other operator
};

//-------------puzzle-------------
struct stat { /*...*/ };
int stat(char* name, struct stat* buf);

int main()
{
	complex data{1, 2};
	return 0;
}
