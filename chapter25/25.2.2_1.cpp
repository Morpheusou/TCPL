#include <iostream>
using namespace std;

template<typename T, int max>
class Buffer {
	T v[max];
	public:
	Buffer(){}
	// ...
};

class Record {
};

template<typename T, char* label>
class X{
	// ...
};

char lx2[] = "BMW323Ci";
int main()
{
	//X<int, "BMW323Ci">x1; // error: string literal as template
	X<int, lx2> x2;
	Buffer<char, 128> cbuf;
	Buffer<int, 5000> ibuf;
	Buffer<Record, 8> rbuf;
	return 0;
}
