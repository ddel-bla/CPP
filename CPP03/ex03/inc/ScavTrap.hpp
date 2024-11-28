#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string newname);
		ScavTrap(ScavTrap const &rhs);
		~ScavTrap();

		ScavTrap	&operator=(ScavTrap const &rhs);
		void		guardGate(void);
		void		attack(const std::string &target);
};

#endif