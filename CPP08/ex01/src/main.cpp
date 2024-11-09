#include <cstdlib>
#include <exception>

#include "../inc/Span.hpp"

int main(void) {
	Span sp = Span(5);
	std::cout << "SUBJECT EXAMPLE TEST" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}