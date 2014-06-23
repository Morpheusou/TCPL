#include <iostream>

using namespace std;

template<typename T, typename Allocator>
class List {
	private:
	struct Link {
		T val;
		Link* succ;
		Link* prev;
	};
	// ...
};
int main()
{
	return 0;
}
