#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class span {
private:
	unsigned int		N;
	unsigned int		fillness;
	std::vector<int>	store;
public:
	span( void );
	span( const span& origin);
	span& operator =(const span& origin);

	~span( void );

	span( const unsigned int);
	span( std::vector<int>::iterator begin, std::vector<int>::iterator end);
	
	void addNumber(int new_number);
	int shortestSpan();
	int longestSpan();

	class spanFull : public std::exception {
		public:
		const char * what() const throw();
	};
};


#endif
