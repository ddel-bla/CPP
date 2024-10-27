
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define DESTROY " is destroyed"
#define BRAIN ": BraiiiiiiinnnzzzZ..."
#define NO_ARG "This program doesn't take arguments"

#include <iostream>

class	Zombie {
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);

	private:
		std::string _name;
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif