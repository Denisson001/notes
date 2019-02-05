class Derived : public Base{

};

class Base{
public:
	void f();
};

class Derived : public Base{
public:
	void f();
};

int main(){
	Derived d;
	d.f();
}

class Base{
public:
	void f();
};

class Derived : public Base{
public:
	void f(int x);
};

int main(){
	Derived d;
	d.f();
}

