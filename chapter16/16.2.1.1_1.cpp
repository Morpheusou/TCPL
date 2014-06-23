#include <iostream>
using namespace std;

struct Date {    // representation
	int d, m, y;
	void init(int dd, int mm, int yy); //initialize
	void add_year(int n); // add n years
	void add_month(int n); // add n months
	void add_day(int n);  // add n days
};

Date my_birthday;

void f()
{
	Date today;
	today.init(16,10,1996);
	my_birthday.init(30,12,1950);

	Date tomorrow = today;
	tomorrow.add_day(1);
}
void Date::init(int dd, int mm, int yy)
{
	d = dd;
	m = mm;
	y = yy;
}



