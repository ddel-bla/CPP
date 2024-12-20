#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#define NOTFOUND "Not found by easyfind so it was hard to find."

template <typename T>
int easyfind(T &container, int num) {
	typename T::iterator val = std::find(container.begin(), container.end(), num);
	if (val != container.end())
		return std::distance(container.begin(), val);
	return std::cout << NOTFOUND << std::endl, 1;
}

#endif