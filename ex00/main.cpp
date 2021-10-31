#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

template <typename CONTAINER>
void ContainerTest () {
	CONTAINER _container(10);

	for (typename CONTAINER::iterator i = _container.begin(); i != _container.end(); i++) {
		*i = rand() % 15;
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	try {
		std::cout << *easyfind(_container, 13) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}

int main () {
	srand(time(NULL));
	ContainerTest<std::vector<int> >();
	ContainerTest<std::list<int> >();
}