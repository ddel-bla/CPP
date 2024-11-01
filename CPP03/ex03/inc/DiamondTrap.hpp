#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &rhs);
		~DiamondTrap();

		DiamondTrap	&operator=(DiamondTrap const &rhs);
		void		whoAmI(void);
		void		attack(const std::string &target);

	private:
		std::string _name;
};

#endif