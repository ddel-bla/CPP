#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	InitSpellBook();
}

MateriaSource::MateriaSource(AMateria *materia) {
	if (materia != NULL) {
		spellbook[0] = materia;
		for (int i = 1; i < SLOTS; i++) spellbook[i] = NULL;
	} else
		InitSpellBook();
}

MateriaSource::MateriaSource(MateriaSource const &cpy) {
	InitSpellBook();
	*this = cpy;
}

MateriaSource::~MateriaSource() {
	DeleteSpellBook();
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < SLOTS; i++) {
			if (spellbook[i] != NULL) delete spellbook[i];
			if (rhs.spellbook[i] != NULL)
				spellbook[i] = rhs.spellbook[i]->clone();
			else
				spellbook[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::InitSpellBook() {
	for (int i = 0; i < SLOTS; i++) spellbook[i] = NULL;
}

void MateriaSource::DeleteSpellBook() {
	for (int i = 0; i < SLOTS; i++) delete spellbook[i];
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < SLOTS; i++) {
		if (spellbook[i] != NULL && spellbook[i]->getType().compare(type) == 0) {
			std::cout << type << M_CREATED << std::endl;
			return spellbook[i]->clone();
		}
	}
	std::cout << type << NOTFOUND << std::endl;
	return NULL;
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (materia != NULL) {
		for (int i = 0; i < SLOTS; i++) {
			if (spellbook[i] == NULL) {
				spellbook[i] = materia;
				return;
			}
		}
	} else
		std::cout << ISNULL << std::endl;
	std::cout << BOOKFULL << std::endl;
}
