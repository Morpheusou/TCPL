#include <iostream>
using namespace std;

class Date {
public:
	// ...
	string string_rep() const;
private:
	mutable bool cache_valid;
	mutable string cache;
	void compute_cache_value() const; // fill (mutable) cache
	// ...
};

string Date::string_rep() const
{
	if (!cache_valid) {
			compute_cache_value();
			cache_valid = true;
	}
	return cache;
}

void f(Date d, const Date cd)
{
	string s1 = d.string_rep();
	string s2 = cd.string_rep(); // OK!
}


