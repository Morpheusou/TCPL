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

	bool midnight() { return true; }
	const Date& default_date(); // the default date
	ostream& operator<<(ostream& os, const Date& d); // print d to os
	istream& operator>>(istream& is, Date& d); // read Date from is into d

	class Time{};
	class Date_and_time {
	private:
		Date d;
		Time t;
	public:
		Date_and_time(Date d, Time t);
		Date_and_time(int d, Month m, int y, Time t);
		// ...
	};
	Month do_something(Date d);
	int do_something(int d);
}// Chrono
