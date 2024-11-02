#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define INVENTORY_SIZE 4

#define ITEM		"Item slot #"
#define FULL		"Inventory is full."
#define ENULL		"The equipment is NULL."
#define CHARCON		"Character is constructed"
#define IIDXW		"The inventory index is wrong."
#define UNEQ		" has been unequipped."
#define ADDED		" has been added to the inventory"
#define MISSING		" is not found in the inventory."
#define HASONE		" is already present in the inventory."

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria *inventory[INVENTORY_SIZE];
		AMateria *SavedPointer[INVENTORY_SIZE];
	public:
		Character();
		Character(Character const &cpy);
		Character(std::string const &name);
		~Character();

		Character &operator=(Character const &rhs);
		std::string const &getName() const;
		void InitInventory();
		void InitSavedPointers();
		void SavePointer(int idx);
		void DeleteSavedPointers();
		void DeleteInventory();
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif