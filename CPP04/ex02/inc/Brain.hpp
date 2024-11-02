#ifndef BRAIN_HPP
#define BRAIN_HPP

#define IDEAS 100

#include <cstdlib>
#include <iostream>

#include "AAnimal.hpp"

class Brain {
	private:
		int IdeaIndex;
	protected:
		std::string ideas[IDEAS];
	public:
		Brain();
		Brain(Brain const &rhs);
		~Brain();
		Brain &operator=(Brain const &rhs);
};

#endif