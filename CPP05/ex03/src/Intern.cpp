#include "../inc/Intern.hpp"

// CONSTRUCTORS / DESTRUCTOR

Intern::Intern() { std::cout << "Intern" << CONSTRUCTOR << std::endl; }

Intern::Intern(Intern const &cpy) {
	(void)cpy;
	std::cout << "Intern" << COPYCON << std::endl;
}

Intern::~Intern() { std::cout << "Intern" << DESTRUCTOR << std::endl; }

// OPERATOR OVERLOADS
Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	std::cout << "Intern" << ASSIGNMENT << std::endl;
	return *this;
}

// FUNCTIONS
AForm *Intern::makeForm(std::string const &formName, std::string const &target) const {
	int caseId;
	AForm *form = NULL;

	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidental pardon"};

	for (caseId = -1; caseId < 3; caseId++)
		if (formName == forms[caseId]) break;
	switch (caseId) {
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << DUMB << formName;
			throw(AForm::AFormCreationFailedException());
	}
	return form;
}
