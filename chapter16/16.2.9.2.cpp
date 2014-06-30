#include <string>
using namespace std;
class Date {
public:
	// ...
	string string_rep() const; // string representation
private:
	bool cache_valid;
	string cache;
	void compute_cache_value(); // fill cache
	// ...
};
