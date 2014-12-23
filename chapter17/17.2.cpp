#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<typename Target =string, typename Source =string>
Target to(Source arg)
{
	Target result;
	return result;
}

struct Tracer {
	string mess;
	Tracer(const string &s) :mess{s} { clog << mess; }
	~Tracer() { clog << "~" << mess; }
};

void f(const vector<int>& v)
{
	Tracer tr {"in f() \n" };
	for (auto x : v) {
		Tracer tr {string{"v loop "} + to<string>(x) + '\n'};
		// ...
	}
}
