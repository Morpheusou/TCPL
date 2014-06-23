#include<iostream>
#include<complex>
#include<vector>
using namespace std;

template<typename T>
void f(T);

template<typename T>
class X {
	class M {/* ... */};
	// ...
	void mf();
};

void f()
{
	struct S { /* ... */};
	vector<S> vs;  //OK
	//vector<X::M> vm; // error: X::M is private
	// ...
}
template<typename T>
void X<T>::mf()
{
	//vector<S> vs; // error: no S in scope
	vector<M> vm; // OK
}
int main()
{
	f(1);			// T deduce to be int
	f<double>(1);		// T is double
	f<complex<double>>(1);  // T is complex<double>
	
	X<double> x1;           // T is double
	X<complex<double>> x2;	// T is complex<double>

	vector<double> x;      // vector of doubles
	vector<complex<double>> x22; // vector of complex:w
}
