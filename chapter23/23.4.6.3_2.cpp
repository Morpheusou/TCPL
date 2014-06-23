#include <iostream>
//#include <algorithm>
using namespace std;

template<typename T, typename A>
class List;

template<typename T>
class Link {
	template<typename U, typename A>
	friend class List;
	
	T val;
	Link* succ;
	Link* prev;
};
/*
template<typename T>
struct Iterator {
	Link<T>* current_position;
};
*/
template<typename T, typename A>
class List {
	// ...
	public:
	//template<typename U>
	class Iterator {
		Link<T>* current_position;
		public:
		// ... usual iterator operations ...

	};
	Iterator begin();
	Iterator end();
	// ...
};

class My_allocator {
};
class Your_allocator {
};
/*void fct(List<int>::Iterator b, List<int>::Iterator e) // error: List takes two arguments
{
	auto p = find(b, e, 17);
}
*/
template<typename T, typename U, typename X = int>
int find(T t, U u, X a)
{
	return 0;
}
void fct(List<int, My_allocator>::Iterator b, List<int, Your_allocator>::Iterator e)
{
	auto p = find(b,e,17);
	// ...
}

void user(List<int, My_allocator>& lm, List<int, Your_allocator>& ly)
{
	//fct(lm.begin(), lm.end());
	//fct(ly.begin(), ly.end());
}

int main()
{
	return 0;
}
