#include <iostream>
#include <vector>
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
		int d, y;
		Month m;
	};

	bool is_date(int d, Month m, int y); // true for valid date
	bool is_leapyear(int y); // true if y is a leap year

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b); 

	bool midnight() { return true; }
	const Date& default_date(); // the default date
	ostream& operator<<(ostream& os, const Date& d); // print d to os
	istream& operator>>(istream& is, Date& d); // read Date from is into d

	Date::Date(int dd, Month mm, int yy) :d{dd}, m{mm}, y{yy}
	{
		if (y == 0) y = default_date().year();
		if (m == Month{}) m = default_date().month();
		if ( d == 0) d = default_date().day();

		if (!is_valid()) throw Bad_date();
	}
	void fill (vector<Date>& aa)
	{
		while (cin) {
			Date d;
			try {
				cin >> d;
			}catch (Date::Bad_date) {
				// ... my error handling ...
				continue;
			}

			aa.push_back(d);  // see chapter 4.4.2
		}
	}
	bool Date::is_valid()
	{
		return is_date(d, m, y);
	}

	inline int Date::day() const
	{
		return d;
	}

	Date& Date::add_month(int n)
	{
		if (n == 0) return *this;

		if (n>0) {
			int delta_y = n/12;   // number of whole years
			int mm = static_cast<int>(m)+n%12; // number of months ahead

			if (12 < mm) {
				++ delta_y;
				mm -= 12;
			}

			// ... handle the cases where the month mm does't have day d ...

			y += delta_y;
			m = static_cast<Month> (mm);
			return *this;
		}
		return *this;
	}
}// Chrono

