#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &cpy);
		~Intern();
		Intern &operator=(Intern const &rhs);
		AForm *makeForm(std::string const &formName, std::string const &target) const;
};

#endif