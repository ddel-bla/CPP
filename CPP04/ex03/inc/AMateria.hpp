#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class ICharacter;

class AMateria {
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(AMateria const &cpy);
		AMateria &operator=(AMateria const &rhs);
		virtual ~AMateria();

		AMateria(std::string const &type);
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif