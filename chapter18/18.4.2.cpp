#include <memory>
using namespace std;
class Record{
};
class Invalid_unique_ptr {
};

template <typename T, typename D = default_delete<T>>
class unique_ptr {
public:
	explicit operator bool() const noexcept;
};

void use(unique_ptr<Record> p, unique_ptr<int> q)
{
	if (!p)
		throw Invalid_unique_ptr{};
	
	bool b = p; 
	int x = p+q;
}
