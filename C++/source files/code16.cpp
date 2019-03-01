template< class InputIt, class OutputIt >
OutputIt copy(InputIt first, InputIt last, OutputIt d_first);

template<class Container>
class back_insert_iterator{};

vector<int> a;
std::back_insert_iterator<vector<int>> it(a);
(*it) = 42;

template< class Container >
std::back_insert_iterator<Container> back_inserter(Container& c);

template<class T>
void swap(T &x, T &y){
	T t = x;
	x = y;
	y = t;
}

vector<int> v;
v.push_back(a);

template<class T>
void swap(T &x, T &y){
    T t = move(x);
    x = move(y);
    y = move(t);
}

vector<int> v;
v.push_back(move(a));

struct C{
    C(C&& x){...}
    C& operator=(C&& x){...}
};

template<class T>
std::remove_reference_t<T>::type&& move(T &&x){
    return static_cast<typename std::remove_reference<T>::type&&>(x);
}
template<class T>
remove_reference_t<T>&& move(T &&x){
    return static_cast<typename std::remove_reference<T>::type&&>(x);
}

int x = 42;
int &&y = x;
int &&z = 42;
int &t = z;
int &&p = z;
int &&p = move(z);


		 glvalue        rvalue
		/       \      /      \
	  /         \    /        \
 lvalue        xvalue        prvalue