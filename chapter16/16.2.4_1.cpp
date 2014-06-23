#include <iostream>
using namespace std;

class Date1 {
	int d, m, y; // private by default
public:
	Date1(int dd, int mm, int yy);
	void add_year(int n);  // add n years
};

struct Date2 {
private:
	int d, m, y;
public:
	Date2(int dd, int mm, int yy);
	void add_years(int n);  // add n years
};

class Date3 {
public:
	Date3(int dd, int mm, int yy);
	void add_year(int n); // add n years
private:
	int d, m, y;
};

class Date4 {
public:
	Date4(int dd, int mm, int yy);
private:
	int d, m, y;
public:
	void add_year(int n); // add n years
};

int main()
{
	return 0;
}
