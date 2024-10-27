
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define AMOUNT 5
#define NAME "Khabib"
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
		void give_name(std::string name);

	private:
		std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif