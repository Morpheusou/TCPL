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
}// Chrono

using namespace Chrono;
void f(Date& d)
{
	Date lvb_day {16, Month::dec, d.year()};
	if (d.day() == 29 && d.month() == Month::feb) {
		// ...
	}

	if (midnight()) d.add_day(1);

	cout << "day after: " << d.add_day(1) << '\n';
	Date dd; // initialized to the default date
	cin>>dd;
	if (dd==d) cout << "Hurray!\n"; 
}
