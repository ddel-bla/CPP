#include "../inc/ScavTrap.hpp"

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
	ClapTrap trapC(trapB);
	ScavTrap scavD("D");

	trapA.attack("B");
	trapB.takeDamage(5);
	trapB.beRepaired(1);
	trapC.attack("B");
	trapB.takeDamage(10);
	std::cout << std::endl;

	scavD.attack("A");
	trapA.takeDamage(5);
	trapA.attack("D");
	scavD.takeDamage(3);
	scavD.beRepaired(4);
	scavD.guardGate();
	std::cout << std::endl;

	return  (0);
}
