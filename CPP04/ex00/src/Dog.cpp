#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog") { std::cout << type << CONSTRUCTOR << std::endl; }

Dog::Dog(Dog const &rhs) : Animal(rhs) {
	std::cout << type << COPYCON << std::endl;
	*this = rhs;
}

Dog::~Dog() { std::cout << type << DESTRUCTOR << std::endl; }

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << type << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}

void Dog::makeSound() const { std::cout << BARK << std::endl; }