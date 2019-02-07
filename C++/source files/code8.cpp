struct Base{
    int a;
    void f();
};

struct Derived : public Base{
    int b;
    void f();
};

int main(){
    Base b;
    Derived d;
    Base &g = d;
    g.f();
    //g.b;
}

Base *g = &d;
g->f();
//g->b;

Base &g = d;
static_cast<Derived&>(g).f();

Base b;
Derived d;
b = d;
static_cast<Derived&>(b).f();

static_cast<Base&>(d).f();

reinterpret_cast<Base&>(d).f();

struct A{
};

struct B : A{
};

struct C : A{
};

struct D : B, C{    
};

int main(){
    D d;
    static_cast<A&>(d); //incorrect
}

struct A{
    int x;
    virtual void foo();
};

struct B : A{
    void g(){
        cout << "YEAH!\n";
    }
};

void f(A &a){
    try{
        B &b = dynamic_cast<B&>(a);
        b.g();
    } catch(const std::bad_cast &e){
        std::cout << e.what(); 
    }
}

void s(A *a){
    B *b = dynamic_cast<B*>(a);
    if (b) b->g();
    else std::cout << "nullptr\n";
}

int main(){
    A a;                                      stdout:
    B b;                                          YEAH!
    f(b);                                         std::bad_cast
    f(a);                                         YEAH!
    s(&a);                                        nullptr
    s(&b);
}

struct Base{
    int a;
    void f();
};

struct Derived : public Base{
    int b;
    void f();
};

int main(){
    Derived d;
    Base &b = d;
    b.f();
}

struct Base{
    int a;
    virtual void f();
};

D *d = new D();
B *b = d;
delete b;

virtual ~B() {}

struct Shape{
    virtual double area() const = 0;
};

struct Square : public Shape{
    double a, b;
    double area() const {
        return a * b;
    }
};

int main(){
    Square sq;
    Shape &sh = sq;
    sh.area();
}

double Shape::area() const {}

struct Base{
    virtual void f();
};

struct Derived : Base{
    void f() override;
};

struct Base{
    virtual void foo();
};
 
struct A : Base{
    void foo() final; // A::foo is overridden and it is the final override
    void bar() final; // Error: non-virtual function cannot be overridden or be final
};
 
struct B final : A{ // struct B is final
    void foo() override; // Error: foo cannot be overridden as it's final in A
};
 
struct C : B{ // Error: B is final
};

#include <typeinfo>
int x;
typeid(x).name();

class Base{
public:
    virtual void vvfunc() {}
};

class Derived : public Base {};

using namespace std;
int main(){
    Derived* pd = new Derived;
    Base* pb = pd;
    cout << typeid( pb ).name() << endl;   //prints "class Base *"
    cout << typeid( *pb ).name() << endl;   //prints "class Derived"
    cout << typeid( pd ).name() << endl;   //prints "class Derived *"
    cout << typeid( *pd ).name() << endl;   //prints "class Derived"
    delete pd;
}

class Bas {
public:
    void vvfunc() {}
};

cout << typeid( pb ).name() << endl;   //prints "class Base *"
cout << typeid( *pb ).name() << endl;   //prints "class Base"
cout << typeid( pd ).name() << endl;   //prints "class Derived *"
cout << typeid( *pd ).name() << endl;   //prints "class Derived"
