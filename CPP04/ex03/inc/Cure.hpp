#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define HEALS		" heals "
#define WOUNDS		"'s wounds *"

class Cure : public AMateria {
	public:
		Cure();
		Cure(Cure const &cpy);
		Cure &operator=(Cure const &rhs);
		~Cure();
		
		Cure(std::string const &type);
		std::string const &getType() const;	 // Returns the materia type
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif