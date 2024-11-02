#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#define CONSTRUCTOR_WA	"Default WrongAnimal is constructed"
#define DESTRUCTOR_WA	" type of WrongAnimal was destructed"
#define COPYCON_W		"WrongAnimal copy constructor called"
#define CONSTRUCTED_WA	" type of WrongAnimal is being constructed"
#define ASSIGNMENT_W	" assignment operator overload called"
#define CONSTRUCTOR_W	" is constructed"
#define DESTRUCTOR_W	" was destructed"
#define COPYCON_WA		" copy constructor called"

#define WMEOW			"WrongMeow sound"
#define WBARK			"WrongBark sound"
#define WANI			"WrongAnimal sound"

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &rhs);
		~WrongAnimal();
		WrongAnimal &operator=(WrongAnimal const &rhs);
		void makeSound() const;
		virtual std::string getType() const;
};

#endif