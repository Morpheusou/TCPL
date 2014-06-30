class Date {
	int d, m, y;
public:
	int day() const { return d; }
	int month() const { return m; }
	int year() const; // add n years
	int add_year(int n);
	// ...
};
/*
int date::year() const
{
	return ++y;  // error: attempt to change member value in const function
}
*/
int Date::year() const // error: const missing in member function type
{
	return y;
}

void f(Date& d, const Date& cd)
{
	int i = d.year(); // OK
	d.add_year(1); // OK
	int j = cd.year(); // OK
	//cd.add_year(1); // error: cannot change value of a const Date
}
