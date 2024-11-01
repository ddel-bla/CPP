#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

#define NO_ARG			"This program doesn't take arguments"
#define CONSTRUCTOR		" default constructor called"
#define COPY			"Copy constructor called"
#define CONSTRUCTED		" was constructed"
#define DESTRUCTOR		" default destructor called"
#define ASSIGNMENT		"Assignment operator called"
#define CT 				"\033[1;34mClapTrap \033[0;39m"
#define ST 				"\033[1;34mScavTrap \033[0;39m"
#define FT				"\033[1;34mFragTrap \033[0;39m"
#define GUARD 			" is now in Gatekeeper mode"

#define CANT_REPAIR		" is already dead and cannot be repaired"
#define NO_ENERGY		" has no energy points to be repaired"
#define REPAIRED		" was repaired. Hit points: "

#define DEAD_NO_ATCK	" is dead and cannot attack "
#define CANT_ATTACK		" has no energy points to attack "
#define ATTACKS			" attacks "
#define CAUSING			" causing "
#define DAMAGE			" damage"

#define DEAD			" is already dead"
#define HITPOINTS_LEFT	" attacked. Hit points left: "
#define DEATH			" was attacked and died"

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &rhs);
		~ClapTrap();

		ClapTrap	&operator=(ClapTrap const &rhs);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	protected:
		std::string name;
		int			HitPoints;
		int			EnergyPoints;
		int			AttackDamage;
};

#endif
