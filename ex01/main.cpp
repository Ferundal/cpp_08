#include "span.hpp"
#include <iostream>

int main () {
	srand(time(NULL));
	std::cout << "----------------------------------------------" << std::endl;
	{
		span test;
		try {
			test.addNumber(1);
			std::cout << "You should not see this message" << std::endl;
		}
		catch (std::exception &no_space)
		{
			std::cout << no_space.what() << "You should see this message" << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
	{
		span test;
		try {
			test.addNumber(0);
			std::cout << "You should not see this message" << std::endl;
		}
		catch (std::exception &no_space)
		{
			std::cout << no_space.what() << "You should see this message" << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
	{
		span test(1);
		try {
			test.addNumber(0);
			test.shortestSpan();
			std::cout << "You should not see this message" << std::endl;
		}
		catch (std::exception &no_space)
		{
			std::cout << no_space.what() << "You should see this message" << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
	{
		span test(1);
		try {
			test.addNumber(0);
			test.longestSpan();
			std::cout << "You should not see this message" << std::endl;
		}
		catch (std::exception &no_space)
		{
			std::cout << no_space.what() << "You should see this message" << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
	{
		span test (1);
		try {
			test.addNumber(1);
			std::cout << "You should see this message" << std::endl;
		}
		catch (std::exception &no_space)
		{
			std::cout << no_space.what() << "You should not see this message" << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
	{
		span test (5);
		int val;
		try {
			for (int i = 0; i < 5; i++) {
				val = rand() % 20;
				test.addNumber(val);
				std::cout << val << " ";
			}
			std::cout << std::endl;
			std::cout << "ls: " << test.longestSpan() << std::endl;
			std::cout << "ss: " << test.shortestSpan() << std::endl;
			std::cout << "You should see this message" << std::endl;
		}
		catch (std::exception &no_space)
		{
			std::cout << no_space.what() << "You should not see this message" << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
	{
		std::vector<int> test_vector (10000);
		for (std::vector<int>::iterator i = test_vector.begin(); i != test_vector.end(); i++)
			*i = rand() % 10000;
		span test (test_vector.begin(), test_vector.end());
		try {
			test.addNumber(1);
			std::cout << "You should not see this message" << std::endl;
		}
		catch (std::exception &no_space)
		{
			std::cout << no_space.what() << "You should see this message" << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
	{
		std::vector<int> test_vector (10000);
		for (std::vector<int>::iterator i = test_vector.begin(); i != test_vector.end(); i++)
			*i = rand() % 10000;
		span test (test_vector.begin(), test_vector.end());
		try {
			test.longestSpan();
			std::cout << "You should see this message" << std::endl;
		}
		catch (std::exception &no_space)
		{
			std::cout << no_space.what() << "You should not see this message" << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
	{
		std::vector<int> test_vector (10000);
		for (std::vector<int>::iterator i = test_vector.begin(); i != test_vector.end(); i++)
			*i = rand() % 10000;
		span test (test_vector.begin(), test_vector.end());
		try {
			test.shortestSpan();
			std::cout << "You should see this message" << std::endl;
		}
		catch (std::exception &no_space)
		{
			std::cout << no_space.what() << "You should not see this message" << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
}