#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#define NSPF "No span can be found."
#define INVS "Invalid size has been passed to span, it must be 1 or above."
#define SPAF "The span is already full, cannot accept more numbers."

class Span {
	private:
		unsigned int spanSize;
		std::vector<int> numbers;
	public:
		Span();
		Span(Span const &cpy);
		Span(const unsigned int &numbers);
		~Span();
		Span &operator=(Span const &rhs);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addNumber(int number);
		void fillSpan();
		void fillSpanSmartWay(int startValue, int endValue);
		void fillSpanDumbWay(std::vector<int>::iterator const &start,
							std::vector<int>::iterator const &end);
		int size();

		template <typename Iterate>
		void addNumber(Iterate begin, Iterate end) {
			if (spanSize < numbers.size() + end - begin) throw spanAlreadyFullException();
			numbers.insert(numbers.end(), begin, end);
		}

		class noSpanFoundException : public std::exception {
		public:
			const char *what() const throw();
		};

		class spanAlreadyFullException : public std::exception {
		public:
			const char *what() const throw();
		};

		class spanInvalidSizeException : public std::exception {
		public:
			const char *what() const throw();
		};

};

unsigned long long getCurrentTimeMicros();

#endif