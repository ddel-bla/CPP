#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(Cure const &cpy) : AMateria(cpy) {
	*this = cpy;
}

Cure::~Cure() {
}

Cure &Cure::operator=(Cure const &rhs) {
	if (this != &rhs)
		this->_type = getType();
	return *this;
}

std::string const &Cure::getType() const {
	return _type;
}

AMateria *Cure::clone() const {
	AMateria *clone = new Cure();
	return clone;
}

void Cure::use(ICharacter &target) {
	std::cout << HEALS << target.getName() << WOUNDS << std::endl;
}
