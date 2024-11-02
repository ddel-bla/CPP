#include "../inc/Brain.hpp"

Brain::Brain() : IdeaIndex(0) { std::cout << "Default Brain" << CONSTRUCTOR << std::endl; }

Brain::Brain(Brain const &rhs) {
	std::cout << "Brain" << COPYCON << std::endl;
	*this = rhs;
}

Brain::~Brain() { std::cout << "Brain" << DESTRUCTOR << std::endl; }

/*
deep copy
duplicate the entire object
thread safe copies
ensures that the object hierarchy is stays the same
shallow -> only top level attributes are copied
*/
Brain &Brain::operator=(Brain const &rhs) {
	std::cout << "Brain" << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		IdeaIndex = rhs.IdeaIndex;
		for (int i = 0; i < IdeaIndex; i++) 
			ideas[i] = rhs.ideas[i];
		for (int i = IdeaIndex; i < IDEAS; i++) 
			ideas[i].clear();
	}
	return *this;
}

