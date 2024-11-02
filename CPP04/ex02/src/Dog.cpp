#include "../inc/Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	brain = new Brain();
	std::cout << type << CONSTRUCTOR << std::endl;
}

Dog::Dog(Dog const &rhs) : AAnimal(rhs) {
	brain = NULL;
	std::cout << type << COPYCON << std::endl;
	*this = rhs;
}

Dog::~Dog() {
	delete brain;
	std::cout << type << DESTRUCTOR << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << type << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		type = rhs.type;
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	return *this;
}

void Dog::makeSound() const { std::cout << type << BARK << std::endl; }
