#include <iostream>
using namespace std;

class Date {
	int d, m, y;
public:
	Date(int dd, int mm, int yy); // constructor
	// ...
};

int main()
{
	Date today = Date(23, 6, 1983); 
	Date xmas(25, 12, 1990); // abbreviated form
	//Date my_birthday;        // error: initializer missing
	//Date release1_0(10, 12); // error: third argument missing

	return 0;
}
