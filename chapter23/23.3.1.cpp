#include <vector>
using namespace std;

class Shape {
	int a;
};

class Circle : public Shape {
};

int main()
{
	Shape * p {new Circle()};
	//vector<Circle> c = new vector<Circle>{};
	//vector<Shape*> q = c;
//	vector<Shape>* q {new  vector<Circle>{}};
//	vector<Shape> vs {vector<Circle>{}};
	//vector<Shape *> q {new vector<Circle>{}};
	return 0;
}
