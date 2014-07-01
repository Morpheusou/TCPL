#include <iostream>
#include <string>
using namespace std;

namespace Chrono {

	enum class Month { jan=1, feb, mar,apr, may,jun, jul, aug, sep, oct, nov, dec };
	class Date {
	public:
		class Bad_date {}; // exception class
		explicit Date(int dd = {}, Month mm = {}, int yy ={}); // {} means "pick a default"

		// nonmodifying functions for examining the Date:
		int day() const;
		Month month() const;
		int year() const;

		string string_rep() const; // string representation
		void char_rep(char s[], int max) const; // C-style string representation

		// (modifying) functions for changing the Date:
		Date& add_year(int n); // add n years
		Date& add_month(int n); // add n months
		Date& add_day(int n); // add n days

		private:
		bool is_valid();  // check if this Date represents a date
		int d, m, y;
	};

	bool is_date(int d, Month m, int y); // true for valid date
	bool is_leapyear(int y); // true if y is a leap year

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b); 

	bool operator!=(Date, Date);  //ineuqality
	bool operator<(Date, Date); // less than
	bool operator>(Date, Date); // greater than

	Date& operator++(Date& d) { return d.add_day(1); } // increase Date by one day
	Date& operator--(Date&d) { return d.add_day(-1); } // decrease Date by one day

	Date& operator+=(Date& d, int n) { return d.add_day(n); } // add n days
	Date& operator-=(Date& d, int n) { return d.add_day(-n); } // subtract n days

	Date operator+(Date d, int n) { return d+=n; } // add n days
	Date operator-(Date d, int n) { return d-=n; } // subtract n days


	bool midnight() { return true; }
	const Date& default_date(); // the default date
	ostream& operator<<(ostream& os, const Date& d); // print d to os
	istream& operator>>(istream& is, Date& d); // read Date from is into d
	
	// chapter 16.3.2_1.cpp
	int diff(Date a, Date b); // number of days in the range [a, b) or [b, a)

	bool is_leapyear(int y);
	bool is_date(int d, Month m, int y);

	const Date& default_date();
	Date next_weekday(Date d);
	Date next_saturday(Date d);

	inline bool operator==(Date a, Date b)
	{
		return a.day()==b.day() && a.month()==b.month() && a.year()==b.year();
	}
}// Chrono

bool Chrono::is_date(int d, Month m, int y)
{
	int ndays;

	switch (m) {
		case Month::feb:
		ndays = 28+is_leapyear(y);
		break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
		ndays = 30;
		break;
		case Month::jan: case Month::mar: case Month::may: case Month::jul:
		case Month::aug: case Month::oct: case Month::dec:
		ndays = 31;
		break;
		default:
		return false;
	}

	return 1<=d && d<=ndays;
}
