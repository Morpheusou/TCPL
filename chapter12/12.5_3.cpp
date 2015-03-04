using P1 = int (*)(int*);
using P2 = void (*) (void);

void f(P1 pf)
{
	P2 pf2 = reinterpret_cast<P2>(pf);
	pf2();

	P1 pf1 = reinterpret_cast<P1>(pf2);
	int x = 7;
	int y = pf1(&x);
}
