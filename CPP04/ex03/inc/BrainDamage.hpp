#ifndef BRAINDAMAGE_HPP
#define BRAINDAMAGE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"


#define CAUSING		" causing "
#define DAMAGE		" emotional damage!"

class BrainDamage : public AMateria {
	public:
		BrainDamage();
		BrainDamage(BrainDamage const &cpy);
		BrainDamage &operator=(BrainDamage const &rhs);
		~BrainDamage();

		BrainDamage(std::string const &type);
		std::string const &getType() const;
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif