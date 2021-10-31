#ifndef _easyfind_hpp_
#define _easyfind_hpp_
#include <algorithm>

class NotFound : public std::exception {
	const char * what() const throw() {
		return ("No such value!\n");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int original) {
	typename T::iterator tmp =  std::find(container.begin(), container.end(), original);
	if (original == *tmp)
		return (tmp);
	else
		throw (NotFound());
}

#endif