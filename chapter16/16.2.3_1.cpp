#include <iostream>
using namespace std;

class Date {
	int d, m, y;
public:
	void init(int dd, int mm, int yy); // initialize
	
	void add_year(int n); // add n years
	void add_month(int n); // add n months
	void add_day(int n);  // add n days	
};

void Date::add_year(int n)
{
	y += n;
}

void timewarp(Date& d)
{
	d.y -= 200;  // error: Date::y is private
}

int main()
{
	Date dx;
	dx.m = 3;  // error: m is private
	dx.init(25, 3, 2011); // OK

	return 0;
}
