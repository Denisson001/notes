template<typename ... Types>
void f(Types ... args);

void print(){}

template<typename Head, typename ... Tail>
void print(Head x, Tail ... t){
	cout << x << ' ';
	print(t...);
}

int main(){
	print(23, "42", 0.21);
}

sizeof...(t)

void print(Head x, Tail& ... t){}

template<class T>
struct St{};

template<typename Head, typename ... Tail>
void print(Head x, St<Tail> ... t){}

tuple<int, double, std::string> t = make_tuple(1, 2.0, "3");
get<0>(t); get<1>(t); get<2>(t);
get<int>(t); get<double>(t); get<string>(t);

template<class T, class Cmp>
void sort(T *begin, T *end, Cmp cmp){
	//...
	cmp(*x, *y);
	//...
}

template<class T>
struct less{
	bool operator()(const T &x, const T &y){
		return x < y;
	}
};

int x = 5, y = 10;
less<int> l;
l(x, y);

template<class T>
struct Base{
	void f(){
		static_cast<T*>(this)->f();
	}
};

struct Derived : public Base<Derived>{
	void f(){ cout << "YEAH!"; }
};

int main(){
	Derived d;											stdout:
	Base<Derived> &b = d;									YEAH!
	b.f();
}

int *p = new int[1000];					std::bad_alloc

dynamic_cast<Derived&>(b);				std::bad_cast

throw x;
	
try{
	//...
} catch(int x) {
	//...
} catch() {
	//...
}

catch(...)

try{
	int x;
	throw x;
} catch(double x) {										stdout:
	cout << 1;														2
} catch(int x) {
	cout << 2;
} catch(...) {
	cout << 3;
}

try{
	int* x;
	throw x;
} catch(void *x) {										stdout:
	cout << 1;														1 
} catch(int *x) {
	cout << 2;
}

struct Base{};
struct Derived : Base{};

try{
	Derived d;
	throw d;	
} catch(Base &x) {										stdout:
	cout << 1;														1
} catch(Derived &x) {
	cout << 2;
}