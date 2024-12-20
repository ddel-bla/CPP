#include <iostream>
#include <cstdlib>

#define NO_ARG "This program doesn't take arguments"

static void InputCheck(int argc, char **argv) {
	(void)argv;
	if (argc != 1) {
		std::cerr << NO_ARG << std::endl;
		exit (1);
	}
}

int main(int argc, char **argv) {
	InputCheck(argc, argv);
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << std::endl;

	std::cout << "Address of str:             " << &str << std::endl;
	std::cout << "Address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "Address held by stringREF:  " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Value of str:               " << str << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: " << stringREF << std::endl;
	std::cout << std::endl;

	return (0);
}