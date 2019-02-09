try{
	//...
} catch(...) {
	//...
	throw;
}

try{
	//...
} catch(...) {
	//...
	throw string("abacaba");
}

struct St{
	St(){
		cout << "1\n";
	}
	St(const St &d){
		cout << "2\n";
	}
};

try{
	St s;									stdout:
	throw s;											1
} catch(St &s) {									2

}

try{
	St s;									stdout:
	throw s;											1
} catch(St s) {									2
														2
}

struct Base{ 
	virtual void f();
};
struct Derived : Base{};

try{
	Derived d;
	Base &b = d;
	throw b;
} catch(Base &f){
	dynamic_cast<Derived&>(f);
}

try{
	Derived d;
	throw d;
} catch(Base &f){
	dynamic_cast<Derived&>(f);
	throw f;
}
catch(Base &f){
	throw;
}

void f() throw(/*...*/);

struct Ugly{
	int *p;
	Ugly(){
		p = new int;
		throw 1;
	}
	~Ugly(){
		delete p;
	}
};

try{
	Ugly u;
} catch (...) {

}

p = new ...;
throw ...;
delete p;

struct Ugly{
	~Ugly(){
		//...
		throw 2;
	}
};

{
	Ugly g;
	throw 1; 
}

std::uncaught_exception() 

std::terminate()

std::set_terminate()

void f() noexcept;

template<class T>
void g(T x) noexcept{

}

void g(int x){
	throw 42;
}

template<class T>
void f(T x) noexcept(noexcept(g(x))){
	g(x);
}

int fibonacci(int x){
	if (x <= 1) return x;
	return fibonacci(x - 1) + fibonacci(x - 2);
}

void f() noexcept(fibonacci(10) > 200 ? 1 : 0);

constexpr fibonacci(int x){}