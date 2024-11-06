#include "../inc/ShrubberyCreationForm.hpp"

// CONSTRUCTORS / DESTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", false, ShrubberyCreationForm::signReq, ShrubberyCreationForm::execReq),
	  target("Shrubbery_target") {
	std::cout << AForm::Name() << CONSTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : AForm(cpy) {
	target = cpy.target;
	std::cout << AForm::Name() << COPYCON << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &formTarget)
	: AForm("ShrubberyCreationForm", false, ShrubberyCreationForm::signReq, ShrubberyCreationForm::execReq),
	  target(formTarget + "_shrubbery") {
	std::cout << AForm::Name() << " " << target << COPYCON << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << AForm::Name() << " " << target << DESTRUCTOR << std::endl;
}

// OPERATOR OVERLOADS
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		target = rhs.target;
		AForm::operator=(rhs);
	}
	std::cout << AForm::Name() << ASSIGNMENT << std::endl;
	return *this;
}

// FUNCTIONS
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::string tree =
		"           ####\n"
		"         ### ####\n"
		"        ##  MY  ##\n"
		"        ##  TREE ##\n"
		"         ## ಠ⁠‿⁠ಠ #\n"
		"          #######\n"
		"            ###\n"
		"            ###\n"
		"            ###\n"
		"____________###____________\n";

	if (getIsSigned() == false)
		throw(AFormIsAlreadySignedExecption());
	if (executor.getGrade() > ShrubberyCreationForm::execReq)
		throw(AFormCannotExecuteException());
	std::ofstream fout(target.c_str());
	if (!fout)
		throw std::runtime_error(CANTOPEN);
	fout << tree;
	std::cout << GROOT << std::endl;
}
