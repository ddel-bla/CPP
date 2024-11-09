#include "../inc/iter.hpp"

template <typename T>
void print(T& x) {
	std::cout << x << std::endl;
	return;
}

int main() {

	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(int);

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charArrayLength = sizeof(charArray) / sizeof(char);

	int tab[] = {0, 1, 2, 3, 4};

	// Using iter with intArray
	std::cout << "Iterating through an INT array:" << std::endl;
	iter(intArray, intArrayLength, printNum<int>);
	std::cout << std::endl;

	// Using iter with doubleArray
	std::cout << "Iterating through a DOUBLE array:" << std::endl;
	iter(doubleArray, doubleArrayLength, printNum<double>);
	std::cout << std::endl;

	// Using iter with charArray
	std::cout << "Iterating through a CHAR array:" << std::endl;
	iter(charArray, charArrayLength, printNum<char>);
	std::cout << std::endl;

}