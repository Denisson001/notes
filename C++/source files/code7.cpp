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

struct Granny{
    int a;
    Granny(int a): a(a) {}
};

struct Mom : public Granny{
    int b;
    Mom(int b): b(b) {}
};

int main(){
    
}

struct Mom : public Granny{
    int b;
    Mom(int b): Granny(...), b(b) {}
};

struct Mom : public Granny{
    int b;
    Mom(int a, int b): a(a), b(b) {}
};

struct Granny{
    int a;
    Granny(int a): a(a) {}
};

struct Mom : public Granny{
    int b;
    Mom(): Granny(0), b(0) {}
};

struct Son : public Mom{
    int c;
    Son(int c): Granny(0), c(c) {}
};

int main(){

}

struct Parallelogram{
    int x;
};

struct Rectangle : public Parallelogram{
    int y;
};

struct Rhombus : public Parallelogram{
    int z;
};

struct Square : public Rectangle, public Rhombus{
    int t;
};

int main(){
    Square s;
    cout << sizeof(s) / sizeof(int);
}

Square s;
s.Parallelogram::x;
s.Rectangle::x;
s.Rhombus::x;

struct Rectangle : private Parallelogram{
    int y;
}

int main(){
    Square s;
    s.x;
}

struct Granny{
    int x;
};

struct Mom : public Granny{
    int y;
};

struct Son : public Mom, public Granny{
    int z;
};

int main(){
    Son s;
}

struct Parallelogram{
    int x;
};

struct Rectangle : virtual public Parallelogram{
    int y;
};

struct Rhombus : virtual public Parallelogram{
    int z;
};

struct Square : public Rectangle, public Rhombus{
    int t;
};

int main(){
    Square s;
    s.x;
}

struct W{
    int y;
};

struct V{
    int x;
};

struct A : public W, virtual public V{                        W   V   W
    int x, y;                                                  \ / \ /
};                                                              A   B
                                                                 \ /
struct B : public W, virtual public V{                            D

};

struct D : public A, public B{
     
};

int main(){
    D d;          
    d.x;   
    //d.y;    
}                              

Base b;
Derived d;
b = d;
//d = b;

Base &b = d;
Base *b = d;
