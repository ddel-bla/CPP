#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << DT << CONSTRUCTOR << std::endl;
	name = "Diamond";
	ClapTrap::name = name + "_clap_name";
	
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 30;

	//HitPoints = FragTrap::HitPoints;
	//EnergyPoints = ScavTrap::EnergyPoints;
	//AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::DiamondTrap(std::string const &newname)
	: name(newname) {
	std::cout << DT << name << CONSTRUCTOR << std::endl;
	ClapTrap::name = name + "_clap_name";
	
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 30;

	//HitPoints = FragTrap::HitPoints;
	//EnergyPoints = ScavTrap::EnergyPoints;
	//AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &rhs)
	: ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs), name(rhs.name) {
	std::cout << DT << COPY << std::endl;
	*this = rhs;
}

DiamondTrap::~DiamondTrap() {
	std::cout << DT << name << DESTRUCTOR << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		name = rhs.name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << DT << name << " is " << CT << name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);

}

void	DiamondTrap:: print(void)
{
	std::cout << "Name: \t\t"		<< name 			<< std::endl;
	std::cout << "ClapName:\t" 		<< ClapTrap::name	<< std::endl;
	std::cout << "HP: \t\t" 		<< HitPoints 		<< std::endl;
	std::cout << "EP: \t\t" 		<< EnergyPoints		<< std::endl;
	std::cout << "Dmg: \t\t" 		<< AttackDamage		<< std::endl;
}