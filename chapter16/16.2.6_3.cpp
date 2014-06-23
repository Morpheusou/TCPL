#include <iostream>
using namespace std;

class Date {
	int d, m, y;
public:
	explicit Date(int dd);
	// ...
};

Date::Date(int dd) { /* ...  */ }  // OK
explicit Date::Date(int dd) { /* ... */ } // error


