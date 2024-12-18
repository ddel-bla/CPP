#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &rhs);
		virtual ~Cat();
		Cat &operator=(Cat const &rhs);
		virtual void makeSound() const;
};

#endif