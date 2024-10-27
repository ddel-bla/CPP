#ifndef WEAPON_HPP
#define WEAPON_HPP

#define ATTACK " attacks with their "
#define C_CLUB "crude spiked club"
#define O_CLUB "some other type of club"
#define NO_WEAPON " doesn't have weapon yet, but you can see it"
#define NO_ARG "This program doesn't take arguments"

#include <iostream>

class Weapon {
	public:
		Weapon(void);
		~Weapon(void);
		Weapon(std::string type);
		std::string &GetType(void);
		void SetType(std::string type);

	private:
		std::string _type;
};

#endif