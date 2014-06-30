#include <iostream>
using namespace std;

class Date {
	public:
	int d, m, y;
	public:
	Date (int, int, int);  // day, month, year
	Date(int, int); // day, month, today's year
	Date(int); // day, today's month and year
	Date();  // default Date: today
	Date(const char* ); // date in string representation
	// ...
};

static Date today(1,2,3);

class Date1 {
	int d{today.d};
	int m{today.m};
	int y{today.y};

	public:
	Date1(int, int, int); // day, month, year
	Date1(int, int); // day, month, today's year
	Date1(int); // day, today's month and year
	Date1(); // default Date: today
	Date1(const char*); // date in string representation
	// ...
};

Date1::Date1(int dd):d{dd}, m{today.m}, y{today.y}
{
	// check that the Date is valid
}
