#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() 
	: name("ClapTrap"), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << CT << name << CONSTRUCTOR << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
	: name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << CT << name << CONSTRUCTED << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &rhs) {
	std::cout << CT << COPY << std::endl;
	*this = rhs;
}

ClapTrap::~ClapTrap() {
	std::cout << CT << name << DESTRUCTOR << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		name = rhs.name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (HitPoints <= 0)
		std::cout << CT << name << DEAD_NO_ATCK << target << std::endl;
	else if (EnergyPoints == 0)
		std::cout << CT << name << CANT_ATTACK << target << std::endl;
	else {
		std::cout << CT << name << ATTACKS << target << CAUSING << AttackDamage << DAMAGE << std::endl;
		EnergyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (HitPoints <= 0)
		std::cout << CT << name << DEAD << std::endl;
	else if (HitPoints > (long)amount) {
		HitPoints -= amount;
		std::cout << CT << name << HITPOINTS_LEFT << HitPoints << std::endl;
	} else {
		HitPoints = 0;
		std::cout << CT << name << DEATH << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (HitPoints <= 0)
		std::cout << CT << name << CANT_REPAIR << std::endl;
	else if (EnergyPoints <= 0) {
		std::cout << CT << name << NO_ENERGY << std::endl;
	} else {
		HitPoints += amount;
		EnergyPoints--;
		std::cout << CT << name << REPAIRED << HitPoints << std::endl;
	}
}
