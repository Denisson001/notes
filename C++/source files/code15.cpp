template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class set;

s.find(x) != s.end()

template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator< std::pair<const Key, T> >
> class unordered_map;

std::map<int, string> m;
std::map<int, string>::iterator it = m.begin();

std::map<int, string> m;
for (std::map<int, string>::iterator it = m.begin(); it != m.end(); ++it)
for (std::map<int, string>::const_iterator it = m.cbegin(); it != m.cend(); ++it)	
for (std::map<int, string>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
for (std::map<int, string>::const_reverse_iterator it = m.crbegin(); it != m.crend(); ++it)















template<class Iterator, class tmp>
size_t distance_impl(Iterator first, Iterator second, tmp){
	size_t ans = 0;
	while(first != second) first++, ans++;
	return ans;
}

template<class Iterator>
size_t distance_impl(Iterator first, Iterator second, random_access_iterator_tag){
	return second - first;
}

template<class Iterator>
size_t dist(Iterator first, Iterator second){
	return distance_impl(first, second, typename std::iterator_traits<Iterator>::iterator_category());
}

int main(){
	list<int> a;
	vector<int> b;
	dist(a.begin(), a.end());
	dist(b.begin(), b.end());
}

template<class BidirectionalIterator>
class my_reverse_iterator{
	BidirectionalIterator it;
public:
	my_reverse_iterator(const BidirectionalIterator it): it(it) {}

	
	my_reverse_iterator<BidirectionalIterator>& operator++(){
		--it;
		return *this;
	}
	typename BidirectionalIterator::value_type operator*() const{
		return *it;
	}
};