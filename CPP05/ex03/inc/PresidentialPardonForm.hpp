#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string target;
	public:
		static const int signReq = 25;
		static const int execReq = 5;

		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &formTarget);
		PresidentialPardonForm(PresidentialPardonForm const &cpy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
		~PresidentialPardonForm();
		virtual void execute(Bureaucrat const &executor) const;
};

#endif
