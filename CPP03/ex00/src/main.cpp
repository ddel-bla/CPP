#include "../inc/ClapTrap.hpp"

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

	trapA.attack("Jose");
	trapA.takeDamage(5);
	trapA.beRepaired(1);
	trapA.takeDamage(10);
	trapA.attack("Luis");
	std::cout << std::endl;

	trapB.attack("Pepe");
	trapB.attack("Andrés");
	trapB.beRepaired(4);
	std::cout << std::endl;

	trapC.attack("Ramón");
	std::cout << std::endl;
	return  (0);
}
