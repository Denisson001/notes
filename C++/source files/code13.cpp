template<class T, class Alloc = std::allocator<T>>
class vect{
	T* arr;
	size_t sz, cap;
	Alloc alloc;
	using traits = allocator_traits<Alloc>;
public:
	vect(){
		cap = 1;
		sz = 0;
		arr = (T*)(new char[sizeof(T)]);
	}
};

void push_back(const T &x){
	if (sz == cap){
		T* newarr = traits::allocate(alloc, cap * 2);
		for (int i = 0; i < cap; ++i){
			traits::construct(alloc, newarr + i, arr[i]);
		}
		for (int i = 0; i < cap; ++i){
			traits::destroy(alloc, arr + i);
		}
		traits::deallocate(alloc, arr, cap);
		arr = newarr;
		cap <<= 1;
	}
	//arr[sz] = x;
	//new(arr + sz) T(x);
	//alloc.construct(arr + sz, x);
	traits::construct(alloc, arr + sz, x);
	sz++;
}

template <class ... Args>
void emplace_back(const Args &... args) { //... }

T& operator[](size_t i) {
    return arr[i];
}    

const T& operator[](size_t i) const { return arr[i]; } //for const vector

traits::select_on_container_copy_construction(alloc);


int main(){
	vector<int> v(100);
	sizeof(v);
}

int main(){
	vector<int> v(100);
	delete[] &(v[0]);
}

template<
    class T,
    class Allocator = std::allocator<T>
> class vector;