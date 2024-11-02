#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(Cat const &rhs);
		virtual ~Cat();
		Cat &operator=(Cat const &rhs);
		virtual void makeSound() const;
};

#endif