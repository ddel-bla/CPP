#include <cstdlib>
#include <sstream>

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

#define ARRAY_LENGTH 10

static void subject() {
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl;

	delete cat;
	delete dog;

	std::cout << std::endl;
}

static void deepTest() {

	Brain originalBrain;
	originalBrain.setIdea(0, "Inicial");

	Brain copiedBrain = originalBrain;
	std::cout << "* Original: " << originalBrain.getIdea(0) << std::endl;
	std::cout << "* Copied  : " << copiedBrain.getIdea(0) << std::endl;
	originalBrain.setIdea(0, "Modificada");
	std::cout << "* Original: " << originalBrain.getIdea(0) << std::endl;
	std::cout << "* Copied  : " << copiedBrain.getIdea(0) << std::endl;
}

static void Zoo() {
	Animal *animals[ARRAY_LENGTH];
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = ARRAY_LENGTH - 1; i > -1; i--) 
		delete animals[i];
}

int main(void) {
	Zoo();
	deepTest();
	std::cout << std::endl;
	subject();
	return 0;
}
