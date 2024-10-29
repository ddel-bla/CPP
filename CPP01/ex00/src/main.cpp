#include <cstdlib>
#include "../inc/Zombie.hpp"

static void InputCheck(int argc, char **argv) {
	(void)argv;
	if (argc != 1) {
		std::cerr << NO_ARG << std::endl;
		exit(1);
	}
}

int main(int argc, char **argv) {
	InputCheck(argc, argv);

	// STACK
	Zombie stack1("ZombieOnStack1");
	Zombie stack2("ZombieOnStack2");
	Zombie stack3("ZombieOnStack3");
	stack1.announce();
	stack2.announce();
	stack3.announce();
	std::cout << std::endl;

	// HEAP
	Zombie* heap1 = newZombie("ZombieOnHeap1");
	Zombie* heap2 = newZombie("ZombieOnHeap2");
	Zombie* heap3 = newZombie("ZombieOnHeap3");
	heap1->announce();
	heap2->announce();
	heap3->announce();
	delete heap3;
	delete heap2;
	delete heap1;
	std::cout << std::endl;

	// CHUMP STACK
	randomChump("StackChump");
	std::cout << std::endl;
	return (0);
}