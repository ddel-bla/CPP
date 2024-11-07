#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <ctime>

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#define CREATED	" was randomly created."
#define IS		" pointer is identified as: "
#define REF		" reference is from class: "
#define BADCAST "bad casting, identification failed."
#define BADREF	"bad reference, casting failed."

class Base;

class Identify {
	public:
		Identify();
		Identify(Identify const &cpy);
		~Identify();
		Identify &operator=(Identify const &rhs);
		Base *generate(void);
		void identify(Base *p);
		void identify(Base &p);
};

#endif