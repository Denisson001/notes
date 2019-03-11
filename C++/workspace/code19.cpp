void f(){
	int *p = new int;
	g();
	delete p;
}

template<class T>
class auto_ptr{
	T* ptr;
public:
	auto_ptr(T* ptr): ptr(ptr) {}
	~auto_ptr() { delete ptr; }
};

template<class T>
class unqiue_ptr{
	T* ptr;
public:
	unqiue_ptr(T* ptr): ptr(ptr) {}
	~unqiue_ptr() { delete ptr; }
	unqiue_ptr(const unqiue_ptr<T>&) = delete;
	unqiue_ptr<T>& operator=(const unqiue_ptr<T>&) = delete;
	unqiue_ptr(unqiue_ptr<T> &&p) noexcept {
		ptr = p.ptr;
		p.ptr = nullptr;
	}
	unqiue_ptr<T>& operator=(unqiue_ptr<T> &&p) noexcept {
		ptr = p.ptr;
		p.ptr = nullptr;
	}
};

class unqiue_ptr <T[ ]> { ... };

void f(){
	std::unique_ptr<int> p = std::unique_ptr<int>(new int);
	std::unique_ptr<int> pp = std::move(p);
	g();
}

template<class T>
class shared_ptr{
private:
	struct Helper{
		T *ptr;
		int count;
	};
	Helper *h;
public:
	shared_ptr(T *ptr){
		h = new Helper;
		h.ptr = ptr;
		h.count = 1;
	}
};

shared_ptr<T> p = make_shared<T>(args);

template<class T, class ... Args>
shared_ptr<T> make_shared(Args &&... args){
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

f(g(), std::shared_ptr<int>(new int));

void *p = new char[sizeof(T) + sizeof(Helper)];
new (p + sizeof(Helper)) T(std::forward<Args>(args)...);

std::allocator<int> alloc;
std::shared_ptr<int> p = std::allocate_shared<int> (alloc, 42);

template<class T, class Alloc, class ... Args>
shared_ptr<T> allocate_shared(const Alloc &alloc, Args &&... args){
	void *p = std::allocator_traits<Alloc>(alloc, /*...*/);
	/*...*/
}