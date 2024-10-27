#include <cstdlib>
#include "../inc/Zombie.hpp"

void ZombieHordeTester();

static void InputCheck(int argc, char **argv) {
	(void)argv;
	if (argc != 1) {
		std::cerr << NO_ARG << std::endl;
		exit (1);
	}
}

void ZombieHordeTester() {
	Zombie *horde = zombieHorde(AMOUNT, NAME);

	for (int i = 0; i < AMOUNT; i++) {
		std::cout << i << " ";
		horde[i].announce();
	}
	delete[] horde;
}

int main(int argc, char **argv) {
	InputCheck(argc, argv);
	ZombieHordeTester();
	return (0);
}