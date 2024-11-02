#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define SLOTS 4
#define ISNULL			"Materia is NULL."
#define BOOKFULL		"The spellbook is full"
#define NOTFOUND		" materia is not available."
#define M_CREATED		" materia has been created."

class MateriaSource : public IMateriaSource {
	private:
		AMateria *spellbook[SLOTS];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &cpy);
		MateriaSource &operator=(MateriaSource const &rhs);
		virtual ~MateriaSource();

		MateriaSource(AMateria *m);
		void InitSpellBook();
		void DeleteSpellBook();
		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
};

#endif