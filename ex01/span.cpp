#include "span.hpp"

span::span() : N(0), fillness(0), store(0) {
	
}

span::span(const span& origin) : N(origin.N),
								fillness(origin.fillness),
								store(origin.store) {

}

span& span::operator =(const span& origin) {
	store = origin.store;
	N = origin.N;
	fillness = origin.fillness;
	return (*this);
}

span::~span( void ) {

}

span::span(const unsigned int newN) : N(newN), fillness(0), store(0) {

}

span::span( std::vector<int>::iterator begin, std::vector<int>::iterator end) : N(end - begin), store(N) {
	for (std::vector<int>::iterator i = begin; i != end; i++)
		*i = *begin;
	fillness = N;
}

void span::addNumber(int new_number) {
	if (fillness >= N)
		throw spanFull();
	store.push_back(new_number);
	++fillness;
}

int span::longestSpan() {
	if (fillness < 2)
		throw spanFull();
	std::vector<int> temp = store;
	std::sort(temp.begin(), temp.end());
	return (*(--temp.end()) - *temp.begin());
}

int span::shortestSpan() {
	if (fillness < 2)
		throw spanFull();
	std::vector<int> temp = store;
	std::sort(temp.begin(), temp.end());
	std::vector<int>::iterator i = temp.begin();
	int diff = *std::max_element(i, (i + 2)) - *std::min_element(i, (i + 2));
	for (; i != temp.end() - 2; i++) {
		if (diff > *std::max_element(i, i + 2) - *std::min(i, i + 2))
			diff = *std::max_element(i, i + 2) - *std::min(i, i + 2);
	}
	return (diff);
}

const char * span::spanFull::what() const throw() {
	return ("Span is full!\n");
}
