#include <iostream>
using namespace std;

template<typename T>
struct X {
	enum E1 { a, b};
	//enum E2; // error: underlying type not known

	enum class E3;
	enum class E4:char;

	struct C1 { /*... */ };
	struct C2;
};

template <typename T>
enum class X<T>::E3 {a,b};      // needed

template <typename T>
enum class X<T>::E4:char {x,y}; // needed

template<typename T>
struct X<T>::C2 { /* ... */ };

int main()
{
	return 0;
}
