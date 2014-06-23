#include <iostream>
using namespace std;

class Date {
	int d, m, y;
public:
	// ...

	Date(int, int, int);   // day, month, year
	Date(int, int);        // day, month, today's year
	Date(int);             // day, today's month and year
	Date();   	       // default Date: today
	Date(const char*);     // date in string reprentation
};

int main()
{
	Date today {4};  //4, today.m, today.y
	Date july4 {"July 4, 1983"};
	Date guy {5, 11}; //5, November, today.y
	Date now;         // default initialized as today
	Date start {};    // default initialized as today
	return 0;
}
