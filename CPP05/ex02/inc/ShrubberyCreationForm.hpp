#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
	public:
		static const int signReq = 145;
		static const int execReq = 137;

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &formTarget);
		ShrubberyCreationForm(ShrubberyCreationForm const &cpy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm();
		virtual void execute(Bureaucrat const &executor) const;
};

#endif
