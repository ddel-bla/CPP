#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#define HIGH5 " GIVE ME A HIIGHH FIIIVEE!"

#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string newname);
		FragTrap(FragTrap const &rhs);
		~FragTrap();

		FragTrap	&operator=(FragTrap const &rhs);
		void		highFivesGuys(void);
		void		attack(const std::string &target);
};

#endif