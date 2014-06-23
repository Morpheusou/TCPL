#include <iostream>
class Date {
	int d, m, y;
public:
	explicit Date(int dd =0, int mm =0, int yy =0);
	// ...
};

void my_fct(Date d);

Date d1{15};     // OK: considered explicit
Date d2 = Date{15}; // OK: explicit
//Date d3 = {15};     // error: = initialization does not do imiplicit conversions
//Date d4 = 15;  // error: = initialization does not do implicit conversions

void f()
{
//	my_fct(15);   // error: argument passing does not do implicit conversions
//	my_fct({15}); // error: argument passing does not do implicit conversions
	my_fct(Date{15});  // OK: explicit
	// ...
}
