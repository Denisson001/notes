struct Base{
	void f();
};

struct Derived : public Base{
	void f(int x);
};

int main(){
	Derived d;
	d.Base::f();
}

struct Derived : public Base{
    using Base::f;
    void f(int x);
};

struct Base{
public:
	void f();
};

struct Derived : public Base{
private:
	void f(int x);
};

int main(){
	Derived d;
	d.f();
}

struct Granny{
	int a;
};

struct Mom : private Granny{
	int b;
};

struct Son : public Mom{
	int c;
	void f(Granny &g){

	}
}

struct Son : public Mom{
	int c;
	void f(::Granny &g){

	}
}

struct Granny{
	int a;
	friend struct Son;
};

struct Mom : private Granny{
	int b;
	friend struct Son;
};

struct Granny{
protected:
	int a;
};

struct Mom : public Granny{
	int b;
	friend void f();
};

void f(){
	Mom m;
	m.a;
}