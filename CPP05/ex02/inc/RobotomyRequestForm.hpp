#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
	public:
		static const int signReq = 72;
		static const int execReq = 45;

		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &formTarget);
		RobotomyRequestForm(RobotomyRequestForm const &cpy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
		~RobotomyRequestForm();
		virtual void execute(Bureaucrat const &executor) const;
};

#endif
