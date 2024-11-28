#include "../inc/DiamondTrap.hpp"

static void InputCheck(int argc, char **argv) {
	(void)argv;
	if (argc != 1) {
		std::cerr << NO_ARG << std::endl;
		exit(1);
	}
}

int main(int argc, char **argv) {
	InputCheck(argc, argv);
	ClapTrap trapA("A");
	ClapTrap trapB("B");
	ScavTrap scavC("C");
	FragTrap fragD("D");

	trapA.attack("B");
	trapB.takeDamage(5);
	trapB.beRepaired(1);
	trapB.takeDamage(10);
	std::cout << std::endl;

	scavC.attack("A");
	trapA.takeDamage(5);
	trapA.attack("D");
	scavC.takeDamage(3);
	scavC.beRepaired(4);
	scavC.guardGate();
	std::cout << std::endl;

	fragD.attack("A");
	fragD.takeDamage(80);
	fragD.beRepaired(10);
	fragD.highFivesGuys();
	std::cout << std::endl;
	std::cout << std::endl;

	DiamondTrap diaTrap("D");
	diaTrap.print();

	return  (0);
}
