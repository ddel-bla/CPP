#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define CONSTRUCTOR_A	"Default animal is being constructed"
#define DESTRUCTOR_A 	" type of animal was destructed"
#define COPYCON_A		"Animal copy constructor called"
#define CONSTRUCTED_A	" type of animal is being constructed"
#define ASSIGNMENT		" assignment operator overload called"
#define CONSTRUCTOR		" is constructed"
#define DESTRUCTOR		" was destructed"
#define COPYCON			"Animal copy constructor called"

#define MEOW			"Meow"
#define BARK			"Bark"
#define ANI				"Animal sound"

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string const &type);
		Animal(Animal const &rhs);
		virtual ~Animal();
		Animal &operator=(Animal const &rhs);
		virtual void makeSound() const;
};

#endif