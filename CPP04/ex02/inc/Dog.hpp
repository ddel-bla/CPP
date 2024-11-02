#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain *brain;
	public:
		Dog();
		Dog(Dog const &rhs);
		virtual ~Dog();
		Dog &operator=(Dog const &rhs);
		virtual void makeSound() const;
};

#endif