#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << FT << name << CONSTRUCTOR << std::endl;
}

FragTrap::FragTrap(std::string newname) : ClapTrap(newname) {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << FT << name << CONSTRUCTED << std::endl;
}

FragTrap::FragTrap(FragTrap const &rhs) : ClapTrap(rhs) {
	std::cout << FT << COPY << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap() {
	std::cout << FT << name << DESTRUCTOR << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	std::cout << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		name = rhs.name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << FT << HIGH5 << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (HitPoints <= 0)
		std::cout << FT << name << DEAD_NO_ATCK << target << std::endl;
	else if (EnergyPoints <= 0)
		std::cout << FT << name << CANT_ATTACK << target << std::endl;
	else {
		std::cout << FT << name << ATTACKS << target  << CAUSING << AttackDamage << DAMAGE << std::endl;
		EnergyPoints--;
	}
}