#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << ST << name << CONSTRUCTOR << std::endl;
}

ScavTrap::ScavTrap(std::string newname) : ClapTrap(newname) {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << ST << name << CONSTRUCTED << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &rhs) : ClapTrap(rhs) {
	std::cout << ST << COPY << std::endl;
	*this = rhs;
}

ScavTrap::~ScavTrap() {
	std::cout << ST << name << DESTRUCTOR << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		name = rhs.name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	return *this;
}

void ScavTrap::guardGate(void) {
	std::cout << ST << name << GUARD << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (HitPoints <= 0)
		std::cout << ST << name << DEAD_NO_ATCK << target << std::endl;
	else if (EnergyPoints <= 0)
		std::cout << ST << name << CANT_ATTACK << target << std::endl;
	else {
		std::cout << ST << name << ATTACKS << target << CAUSING << AttackDamage << DAMAGE << std::endl;
		EnergyPoints--;
	}
}