struct Date {
	int d, m, y;
	// ...
	Date& add_year(int n); // add n years
	Date& add_month(int n); // add n months
	Date& add_day(int n);   // add n days
	
	bool leapyear(int n) { return true; }
};

Date& Date::add_year(int n)
{
	if (d == 29 && m == 2 && !leapyear(y+n))  { // beware of February 29
		d = 1;
		m = 3;
	}
	y += n;
	return *this;
}

void f(Date& d)
{
	// ...
	d.add_day(1).add_month(1).add_year(1);
	// ...
}
