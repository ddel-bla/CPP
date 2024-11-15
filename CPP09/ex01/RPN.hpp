#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <deque> 
#include <limits>

class RPN
{
	private:
		std::deque<int> num;
	public:
		~RPN(void);
		RPN(void);
		RPN(const RPN &cp);
		RPN& operator=(const RPN &other);
		void pushfrontQueue(int n);
		void pushbackQueue(int n);
		void popfrontQueue();
		void popbackQueue();
		void printDeque();
		int getSize();
		int operator[](size_t i);

		void calculate(RPN& num, char simbol);
		void aux(RPN& num, int n);
		class ExceptionErr: public std::exception {
			virtual const char* what() const throw() {
				return "Error";
			}
		};
};

#endif
