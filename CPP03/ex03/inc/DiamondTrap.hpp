#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &rhs);
		~DiamondTrap();

		DiamondTrap	&operator=(DiamondTrap const &rhs);
		void		whoAmI(void);
		void		attack(const std::string &target);
		void		print(void);
	private:
		std::string name;
};

#endif