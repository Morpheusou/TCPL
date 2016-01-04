#include <iostream>

struct Date {
public:
	int _date;
	int _month;
	int _year;
};

class Record {
public:
	static Date _time;
	int _number;
};

int main()
{
	std::cout << sizeof(Record) << std::endl;
	return 0;
}
