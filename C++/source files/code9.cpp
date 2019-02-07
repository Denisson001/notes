//template<class T>
template<typename T>
void swap(T &a, T &b){}

typename<typename T>
class C {};

int a, b;
swap<int>(a, b);
swap(a, b);

C<int> c;

template<class T>
void f(T &x);

void f(int &x);

template<class T, class Z>
void f(T &x, Z &y) { cout << 1 << "\n"; }

template<class T>
void f(int &x, T&y) { cout << 2 << "\n"; }

void f(int &x, int &y) { cout << 3 << "\n"; }

int main(){
    int x;
    double y;                            stdout:
    f(x, x);                                     3
    f(x, y);                                     2
    f(y, x);                                     1
    f(y, y);                                     1
}


template<class T>
void f(T &x, double &y) { cout << 4 << "\n"; }
f(x, y);

typedef set<int, vector<int>> mytype;

template<typename T>
using mytype = set<int, vector<T>>;
mytype<int> d;

template<class T>
class C{
public:
    typedef T type;
};

template<class T>
int f(){
    typename C<T>::type x;
}

template<class T>
struct remove_const{
    typedef T type;
};

template<class T>
struct remove_const<const T>{
    typedef T type;
};

typename remove_const<T>::type x;

template<class T>
void f(T x);
int x;              f(x);  T = int
int &y = x;         f(y);  T = int
const int z = 0;    f(z);  T = int
const int &t = z;   f(t);  T = int

template<class T>
void f(T &x);
int x;              f(x);  T = int,         int&       x
int &y = x;         f(y);  T = int,         int&       x
const int z = 0;    f(z);  T = const int,   const int& x
const int &t = z;   f(t);  T = const int,   const int& x

template<class T, int n>
class array{};
array<int, 10> a;

template<class S, class W>
struct D{};

template<class S, class W, template<class, class> class T>
void f(T<S, W> &t){}

D<int, double> d;
f(d);

template<class T = int>
void f(){}