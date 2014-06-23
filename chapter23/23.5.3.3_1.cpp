#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename C>
T get_nth(C& p, int n); // get the nth element

struct Index {
	operator int() {}
	// ...
}; 

void f(vector<int>& v, short s, Index i)
{
	int i1 = get_nth<int>(v, 2); //exact match
	int i2 = get_nth<int>(v, s); // standard conversion: short to int
	int i3 = get_nth<int>(v, i); // user-define conversion: Index to int
}


int main()
{
	return 0;
}
