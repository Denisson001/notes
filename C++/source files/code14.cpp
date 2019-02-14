class BoolProxy{};

BoolProxy operator[ ](int i){
	return BoolProxy(i);
}

#include <deque>
#include <stack>

std::stack<int, vector<int>> st;

template<
    class T,
    class Container = std::deque<T>
> class queue;

#include <list>

template<
    class T,
    class Allocator = std::allocator<T>
> class list;

stack<int, std::vector> st;

#include <queue>

template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;

template<
    class T,
    class Allocator = std::allocator<T>
> class deque;

template<
    class T,
    class Container = std::deque<T>
> class stack;

iterator insert(std::list<T>::const_iterator pos, const T &value);

template<class InputIt>
iterator insert(std::list<T>::const_iterator pos, InputIt first, InputIt last);

void splice(const_iterator pos, list &other,
            const_iterator first, const_iterator last);

template<class Compare>
void sort(Compare comp);
l.sort(std::greater<int>());

l.unique();

iterator erase(const_iterator pos);
iterator erase(const_iterator first, const_iterator last);

l.reverse();

#include<forward_list>

template<
    class T,
    class Allocator = std::allocator<T>
> class forward_list;

template<class U>
std::allocator<U> rebind();

#include<map>

template <class Type> struct rebind {
	typedef allocator<Type> other;
};

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map;

m.insert(std::make_pair(key, value));