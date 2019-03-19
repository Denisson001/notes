bool expired() const;
std::shared_ptr<T> lock() const;

template<
    class T,
    class Deleter = std::default_delete<T>
> class unique_ptr;

void operator()(T *ptr){
	delete ptr;
}

template<class T> 
class enable_shared_from_this;
class C : public std::enable_shared_from_this<C>{};
shared_from_this();

for (const std::pair<MyType, std::string> &x : m)
for (std::pair<MyType, std::string> x : m)

auto x = y;

for (const auto &x : m)

template<typename T>
void f(const T &x)

auto &&x = y;

const auto &&x = y;

std::vector<int> v = {1, 2, 3};
int x{5};
auto x = {1, 2, 3}