#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define SHOOT			" shoots an icebolt at "
#define AST				" *"

class Ice : public AMateria {
	public:
		Ice();
		Ice(Ice const &cpy);
		Ice &operator=(Ice const &rhs);
		~Ice();
		
		Ice(std::string const &type);
		std::string const &getType() const;	 // Returns the materia type
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif