#ifndef BRAIN_HPP
#define BRAIN_HPP

#define IDEAS 100

#include <cstdlib>
#include <iostream>

#include "Animal.hpp"

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

		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};

#endif