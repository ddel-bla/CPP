#include "../inc/BrainDamage.hpp"

BrainDamage::BrainDamage()
	: AMateria("braindamage") {
}

BrainDamage::BrainDamage(BrainDamage const &cpy) : AMateria(cpy) {
	*this = cpy;
}

BrainDamage::~BrainDamage() {
}

BrainDamage &BrainDamage::operator=(BrainDamage const &rhs) {
	if (this != &rhs) this->_type = getType();
	return *this;
}

std::string const &BrainDamage::getType() const { return _type; }

AMateria *BrainDamage::clone() const {
	AMateria *clone = new BrainDamage();
	return clone;
}

void BrainDamage::use(ICharacter &target) {
	std::cout << CAUSING << target.getName() << DAMAGE << std::endl;
}

