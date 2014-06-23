#include <iostream>
using namespace std;

class Date {
	int d, m, y;
public:
	Date(int dd =0, int mm =0, int yy =0);
	// ...
};

Date today;

Date::Date(int dd, int mm, int yy)
{
	d = dd ? dd : today.d;
	m = mm ? mm : today.m;
	y = yy ? yy : today.y;

	// check that the Date is valid
}

int main()
{
	return 0;
}
