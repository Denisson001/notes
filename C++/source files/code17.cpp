void push_back(const T &x);
void push_back(T &&x);

template<typename T>
void f(T &&x);

template<typename T>
void f(const T &&x);

template<class ... Args>
void construct(T *p, Args &&... args){
	new (p) T(std::forward<Args>(args)...);
}

template<class T>
T&& forward(typename std::remove_reference<T>::type &t){
	return static_cast<T&&>(t);
}

BigInteger operator+(const BigInteger &x){
	BigInteger ans = *this;
	ans += x;
	return ans;
}

void f() const & {}
void f() const && {}


template<class T>
T&& forward(typename std::remove_reference<T>::type &&t){
	return static_cast<T&&>(t);
}