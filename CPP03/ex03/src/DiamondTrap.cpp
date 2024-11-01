#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("defClapTrap"), ScavTrap(), FragTrap(), _name("Default") {
	std::cout << DT << CONSTRUCTOR << std::endl;
	ScavTrap itsAWrap;
	EnergyPoints = itsAWrap.getPoints();
}

DiamondTrap::DiamondTrap(std::string const &name)
	: ClapTrap(name + "_clap_trap"), ScavTrap(), FragTrap(), _name(name) {
	std::cout << DT << name << CONSTRUCTOR << std::endl;
	ScavTrap itsAWrap;
	EnergyPoints = itsAWrap.getPoints();;
}

DiamondTrap::DiamondTrap(DiamondTrap const &rhs)
	: ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs), _name(rhs._name) {
	std::cout << DT << COPY << std::endl;
	*this = rhs;
}

DiamondTrap::~DiamondTrap() {
	std::cout << DT << _name << DESTRUCTOR << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		_name = rhs._name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << DT << _name << " is " << CT << name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}