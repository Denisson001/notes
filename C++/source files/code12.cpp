T* p = new T(...);
new (p) T(...);
p->~T();

void* operator new(size_t n){}

void* operator new(size_t n, void *p){ return p; }

new (p, ...) T(...);
void* operator new(size_t n, ...){}

void* operator new(size_t n, int k){
	//code here...
}

int *p = new(42) int;



class Animal {
	public:
	virtual void say() = 0;
	virtual ~Animal() {}
};

class Sheep : public Animal {
	public:
	virtual void say() {
		printf("Sheep says baaaaa\n");
	}
	
	virtual ~Sheep() {
		printf("Sheep is dead\n");
	}
	
	void operator delete(void* p) {
		printf("Reclaiming Sheep storage from %p\n", p);
		::operator delete(p);
	}
};

int main(int argc, char** argv) {
	Animal* ap = new Sheep;
	ap->say();
	delete ap;
}

#include <new>
#include <memory>
struct nothrow_t {};
new(std::nothrow) T();
void* operator new (std::size_t size, const std::nothrow_t &nothrow_value) noexcept;

std::new_handler std::set_new_handler(std::new_handler new_p)
std::new_handler std::get_new_handler() 

template<class T>
struct std::allocator<T> {
	typedef T value_type;
	T* allocate(size_t n) const {
		return (T*)(new char[n * sizeof(T)]); 
	}
	void deallocate(T* p, size_t n) const {
		delete[] (char*)p;	
	}
	template<typename ... Args>
	void* construct(T* p, const Args &... args) const {
		return new(p) T(args...);	
	} 
	void destroy(T* p) const {
		p->~T();
	}
};

template<class Alloc>
std::allocator_traits<Alloc>

template<class Alloc>
std::allocator_traits<Alloc>{
	static Alloc::value_type* allocate(Alloc &a, size_t n){
		return a.allocate();		
	} 
}