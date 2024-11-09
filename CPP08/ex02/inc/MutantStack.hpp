#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

#define SEARCHING_FOR	"Searching for element: "
#define CHECKING_AT		"Checking element at index: "
#define NO_MATCH_AT		"No match, going to check element at index: "
#define ITERATING		"Iterating..."
#define ELEM			"The element "
#define FOUND_AT		" has been found at index: "

template <typename T>
	class MutantStack : public std::stack<T> {
		public:
			typedef typename std::stack<T>::container_type::iterator iterator;
			typedef typename std::stack<T>::container_type::const_iterator const_iterator;

			iterator begin() { return std::stack<T>::c.begin(); }
			iterator end() { return std::stack<T>::c.end(); }
			const_iterator begin() const { return std::stack<T>::c.begin(); }
			const_iterator end() const { return std::stack<T>::c.end(); }
	};

#endif