struct X {
	int m;
	void f();
};

void user(X x, X* px)
{
	//m = 1; // error: there is no m in scope
	x.m = 1; // OK
	//x->m = 1; // error: x is not a pointer
	px->m = 1; // OK
	//px.m = 1; // error: px is a pointer
}

void X::f()
{
	m = 1; // OK
}
