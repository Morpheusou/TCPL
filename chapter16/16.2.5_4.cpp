#include <iostream>
using namespace std;

struct Date1 {
	int d, m, y;
};

Date1 today;

class Date {
	int d, m, y;
public:
	Date(int dd = today.d, int mm = today.m, int yy = today.y);
	// ...
};

Date::Date(int dd, int mm, int yy)
{
	// ... chate that Date is valid
}
