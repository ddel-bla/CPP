#include "../inc/phonebook.hpp"

int AddNewContact(PhoneBook *contacts, int max) {
	static int i;
	int error = 0;

	contacts[i].SetContactIndex(i + 1);
	if (i >= 8) {
		i = 0;
		max = 8;
	}
	if (contacts[i].GetContactDetails() == 1)
		error = 1;
	else if (max != 8 && error == 0) {
		i++;
		max++;
	} else if (error == 0)
		i++;
	return max;
}

void FindContactToPrint(PhoneBook *contacts, int max) {
	if (max == 0)
		std::cout << NO_CONTACT;
	else {
		std::cout << std::endl;
		std::cout << CONTACTS << std::endl;
		std::cout << " " << PIPE << CONTACT_FN << PIPE << CONTACT_LN << PIPE << CONTACT_NN << PIPE
				  << std::endl;
		for (int k = 0; k < max; k++) PrintBook(contacts, k);
		std::cout << std::endl;
		PrintContactDetails(contacts, max);
	}
}
