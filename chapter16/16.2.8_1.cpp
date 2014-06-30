/*class Date {
public:
	void add_month(int n) { m+=n; } // increment the Date's m
	// ...
private:
	int d, m, y;
};
*/
class Date {
public:
	void add_month(int n) { m+=n; } // increment the Date's m
	// ...
private:
	int d, m, y;
};

inline void Date:: add_mont(int n) // add n months
{
	m+=n;  // increment the Date's m
}
