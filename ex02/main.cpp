#include "mutantstack.hpp"
#include <iostream>

template<typename T>
void print_stack(MutantStack<T> &mstack) {
	for (typename MutantStack<T>::iterator i = mstack.begin(); i != mstack.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

int main() {
	srand(time(NULL));
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		MutantStack<int> mstack;
		int size = 8;
		for (int i = 0; i < size; i++) {
			mstack.push(rand() % 27);
		}
		print_stack(mstack);
		mstack.pop();
		mstack.pop();
		print_stack(mstack);
		mstack.push(32);
		print_stack(mstack);
		MutantStack<int>::iterator it = mstack.begin() + 3;
		std::cout << *it << std::endl;
		it += 5;
		std::cout << *it << std::endl;
	}
	/*
	{
		MutantStack<int> mstack;
		int size = 8;
		for (int i = 0; i < size; i++) {
			mstack.push(rand() % 27);
		}
		print_stack(mstack);
		try {
			for (int i = 0; i < size + 1; i++) {
				mstack.pop();
			}
		}
		catch (std::exception ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
	*/
}
