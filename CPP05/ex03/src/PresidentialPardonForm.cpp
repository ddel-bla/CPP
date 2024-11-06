#include "../inc/PresidentialPardonForm.hpp"

// CONSTRUCTORS / DESTRUCTOR
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", false, PresidentialPardonForm::signReq, PresidentialPardonForm::execReq),
	  target("Robotomy_target") {
	std::cout << AForm::Name() << CONSTRUCTOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy) : AForm(cpy) {
	target = cpy.target;
	std::cout << AForm::Name() << " " << target  << COPYCON << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &formTraget)
	: AForm("PresidentialPardonForm", false, PresidentialPardonForm::signReq, PresidentialPardonForm::execReq),
	 target(formTraget) {
	std::cout << AForm::Name() << " " << target << COPYCON << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << AForm::Name() << " " << target << DESTRUCTOR << std::endl;
}

// OPERATOR OVERLOADS
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs) {
		target = rhs.target;
		AForm::operator=(rhs);
	}
	std::cout << AForm::Name() << ASSIGNMENT << std::endl;
	return *this;
}

// FUNCTIONS
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw(AFormIsAlreadySignedExecption());
	if (executor.getGrade() > PresidentialPardonForm::execReq)
		throw(AFormCannotExecuteException());
	std::cout << AForm::Name() << " " << target << PARDONED << std::endl;
}
