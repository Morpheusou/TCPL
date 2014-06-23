#include <iostream>
#include <string>
using namespace std;

class Shape {
};
template<typename T>
class Vector { // general vector type
	T* v;
	int sz;
public:
	Vector(); 
    explicit Vector(int); 

    T& elem(int i) {return v[i];}
    T& operator[](int i);

    void swap(Vector&);
    // ...
};

int main()
{
    Vector<int> vi;
    Vector<Shape*> vps;
    Vector<string> vs;
    Vecotr<char*> vpc;
    Vector<Node*> vpn;
    return 0;
}
