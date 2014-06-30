struct S {
	int m;
	int f();
	static int sm;
};

int S::f() { return m; }
int S::sm {7};
int (S::*) pmf() {&S::f};
