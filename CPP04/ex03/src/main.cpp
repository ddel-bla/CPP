#include "../inc/BrainDamage.hpp"
#include "../inc/Character.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/MateriaSource.hpp"

static void OverKill() {
	IMateriaSource* src = new MateriaSource();
	ICharacter* project = new Character("project");
	ICharacter* brain = new Character("brain");
	ICharacter* me = new Character("me");
	AMateria* tmp;
	int i = 0, d = 0;

	while (i < INVENTORY_SIZE && d < SLOTS) {
		src->learnMateria(new Ice());
		tmp = src->createMateria("ice");
		project->equip(tmp);
		i++, d++;
		if (i >= INVENTORY_SIZE || d >= SLOTS) break;
		src->learnMateria(new Cure());
		tmp = src->createMateria("cure");
		project->equip(tmp);
		i++, d++;
		if (i >= INVENTORY_SIZE || d >= SLOTS) break;
		src->learnMateria(new BrainDamage());
		tmp = src->createMateria("braindamage");
		project->equip(tmp);
		i++, d++;
		if (i >= INVENTORY_SIZE || d >= SLOTS) break;
		src->learnMateria(new Ice());
		tmp = src->createMateria("ice");
		project->equip(tmp);
		i++, d++;
		if (i >= INVENTORY_SIZE || d >= SLOTS) break;
		src->learnMateria(new Ice());
		tmp = src->createMateria("ice");
		project->equip(tmp);
		i++, d++;
		if (i >= INVENTORY_SIZE || d >= SLOTS) break;
	}

	project->use(0, *brain);
	project->use(1, *brain);
	project->use(2, *me);
	project->use(3, *me);
	project->use(4, *me);

	delete me;
	delete brain;
	delete project;
	delete src;
}

static void TestUnEquip() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* EquipMaster = new Character("EquipMaster");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	EquipMaster->equip(tmp);
	tmp = src->createMateria("cure");
	EquipMaster->equip(tmp);
	ICharacter* brain = new Character("brain");
	EquipMaster->use(0, *brain);
	EquipMaster->unequip(1);
	EquipMaster->use(1, *brain);

	delete brain;
	delete EquipMaster;
	delete src;
}

static void TestForMissingItem() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* MissingItem = new Character("MissingItem");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	MissingItem->equip(tmp);
	tmp = src->createMateria("cure");
	MissingItem->equip(tmp);
	ICharacter* brain = new Character("brain");
	MissingItem->use(2, *brain);
	MissingItem->use(3, *brain);
	delete brain;
	delete MissingItem;
	delete src;
}

static void TestForWrongIndex() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* WrongIndex = new Character("WrongIndex");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	WrongIndex->equip(tmp);
	tmp = src->createMateria("cure");
	WrongIndex->equip(tmp);
	ICharacter* brain = new Character("brain");
	WrongIndex->use(-3, *brain);
	WrongIndex->use(8, *brain);
	delete brain;
	delete WrongIndex;
	delete src;
}

static void TestForWrongSpells() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* WrongSpells = new Character("WrongSpells");
	AMateria* tmp;
	tmp = src->createMateria("NotIce");
	WrongSpells->equip(tmp);
	tmp = src->createMateria("NotCure");
	WrongSpells->equip(tmp);
	ICharacter* brain = new Character("brain");
	WrongSpells->use(0, *brain);
	WrongSpells->use(1, *brain);
	delete brain;
	delete WrongSpells;
	delete src;
}

static void subject() {
	IMateriaSource* src = new MateriaSource();
 	src->learnMateria(new Ice());
 	src->learnMateria(new Cure());
 	
	ICharacter* me = new Character("me");
 	
	AMateria* tmp;
 	tmp = src->createMateria("ice");
 	me->equip(tmp);
 	tmp = src->createMateria("cure");
 	me->equip(tmp);
 	ICharacter* bob = new Character("bob");
 	me->use(0, *bob);
 	me->use(1, *bob);
 	delete bob;
 	delete me;
 	delete src;
}

int main(void) {
	TestForWrongIndex();
	TestForMissingItem();
	TestUnEquip();
	OverKill();
	TestForWrongSpells();
	std::cout << std::endl;
	subject();
	
	return 0;
}