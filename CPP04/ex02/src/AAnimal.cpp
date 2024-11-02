#include "../inc/AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") { std::cout << CONSTRUCTOR_A << std::endl; }

AAnimal::AAnimal(std::string const &type) : type(type) {
	std::cout << type << CONSTRUCTED_A << std::endl;
}

AAnimal::AAnimal(AAnimal const &rhs) {
	std::cout << COPYCON_A << std::endl;
	*this = rhs;
}

AAnimal::~AAnimal() { std::cout << type << DESTRUCTOR_A << std::endl; }

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
	std::cout << type << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}

void AAnimal::makeSound() const { std::cout << ANI << std::endl; }
