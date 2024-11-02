#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(Ice const &cpy) : AMateria(cpy) {
	*this = cpy;
}

Ice::~Ice() {
}

Ice &Ice::operator=(Ice const &rhs) {
	if (this != &rhs) 
		this->_type = getType();
	return *this;
}

std::string const &Ice::getType() const { return _type; }

AMateria *Ice::clone() const {
	AMateria *clone = new Ice();
	return clone;
}

void Ice::use(ICharacter &target) {
	std::cout << SHOOT << target.getName() << AST << std::endl;
}