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

void my_fct(Date d);

void f()
{
	Date d{15}; // plausible: x becomes {15, today.m, today.y}
	// ...
	my_fct(15);  // obscure
	d = 15;      // obscure

	// ...
}
