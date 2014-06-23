#include <iostream>
using namespace std;

template <typename C>
class String {
public:
	String();
	//explicit String(const *C);
	String(const String&);
	String operator=(const String&);

	C& operator[](int n) { return ptr[n]; } //unchecked element access
	String& operator+=(C c); // add c at end
	//...

	private:
	static const int short_max = 15; // for the short string optimization
	int sz;
	C* ptr; //ptr points to sz Cs
};
char ch[15];
template <typename C>
String<C>::String() : sz{0}, ptr{ch}
{
	ch[0] = {};// terminating 0 of the appropriate character type
}

template<typename C>
String& String<C>::operator+=(C c)
{
	//... add c to the end of the string
	return *this;
}
int main()
{
	String<char> cs;
	String<unsigned char> us;
	String<wchar_t> ws;

	struct Jchar { /* ... */ } //Japanese character

	String<Jchar> js;
	return 0;
}
