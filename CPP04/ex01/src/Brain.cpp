#include "../inc/Brain.hpp"

Brain::Brain() : IdeaIndex(0) { std::cout << "Default Brain" << CONSTRUCTOR << std::endl; }

Brain::Brain(Brain const &rhs) {
	std::cout << "Brain" << COPYCON << std::endl;
	*this = rhs;
}

Brain::~Brain() { std::cout << "Brain" << DESTRUCTOR << std::endl; }

Brain &Brain::operator=(Brain const &rhs) {
	std::cout << "Brain" << ASSIGNMENT << std::endl;
    if (this != &rhs) {
        IdeaIndex = rhs.IdeaIndex;
        for (int i = 0; i < IDEAS; i++) { // Copiar todos los elementos del array
            ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < IDEAS) {
		ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < IDEAS) {
		return ideas[index];
	}
	return "";
}
