#include <iostream>
using namespace std;

template <typename Scalar>
class complex {
public:
	Scalar re, im;
public:
	complex() :re{}, im{} {}
	
	template<typename T>
	complex(T rr, T ii = 0) :re(rr), im(ii) {}


	complex(const complex&) = default;

	template <typename T>
	complex(const complex<T>& c) :re(c.real()), im(c.imag()) {}

	Scalar real() const { return re; }
	Scalar imag() const { return im; }
	// ...
};

int main()
{
	complex<float> cf; //default value
	complex<double> cd {cf};  // OK: uses float to double conversion
	complex<float> cf2 {cd};   // error: no implicit double->float conversion

	complex<float> cf3 {2.0, 3.0}; // error: no implicit double->float conversion
	complex<double> cd2 {2.0F, 3.0F}; // OK: uses float to double conversion

	class Quad {
		// no conversion to int
	};

	complex<Quad> cq;
	//complex<int> ci {cq}; // error: no Quad to int conversion

	complex<float> cf4 {2.1, 2.9}; // ouch ! narrows
	complex<float> cf5 {cd}; // ouch ! narrows

	return 0;
}
