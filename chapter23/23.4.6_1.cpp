#include <iostream>
using namespace std;

class Shape {
	//...
	template<typename T>
	virtual bool intersect(const T&) const = 0;
};

int main()
{
	return 0;
}
