#include <iostream>
using namespace std;

struct cache {
	bool valid;
	string rep;
};

class Date {
public:
	// ...
	string string_rep() const; // string representation
private:
	cache *c; // initialize in constructor
	void compute_cache_value() const; // fill what cache refers to
	// ...
};

string Date::string_rep() const
{
	if(!c->valid) {
		compute_cache_value();
		c->valid = true;
	}
	return c->rep;
}
