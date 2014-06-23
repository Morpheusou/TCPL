#include <iostream>
using namespace std;

template<typename T> class Matrix;
template<typename T> class Vector;
template<typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
	Vector<T> r;
	// ... use m.v[i] and v.v[i] for direct access to elements 

	return r;
}

template<typename T>
class Vector {
	T v[4];
public:
	friend Vector operator*<>(const Matrix<T>&, const Vector&);
	// ...
};

template<typename T>
class Matrix {
	Vector<T> v[4];
	public:
	friend Vector<T> operator*<>(const Matrix&, const Vector<T>&);
	// ...
};


int main()
{
	return 0;
}
