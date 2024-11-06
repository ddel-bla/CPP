#include <exception>

#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

void TestMakeForm() {
	Bureaucrat Bur1("Bur1", 1);
	Intern Int1;
	AForm *shrubberyCreation = NULL;
	AForm *robotomyRequest = NULL;
	AForm *presidentalPardon = NULL;

	try {
		shrubberyCreation = Int1.makeForm("shrubbery creation", "home");
		robotomyRequest = Int1.makeForm("robotomy request", "idiotTasks");
		presidentalPardon = Int1.makeForm("presidental pardon", "TVA");
	} catch (const std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	Bur1.signForm(*shrubberyCreation);
	Bur1.executeForm(*shrubberyCreation);
	std::cout << std::endl;
	Bur1.signForm(*robotomyRequest);
	Bur1.executeForm(*robotomyRequest);
	std::cout << std::endl;
	Bur1.signForm(*presidentalPardon);
	Bur1.executeForm(*presidentalPardon);
	std::cout << std::endl << std::endl;
	delete presidentalPardon;
	delete robotomyRequest;
	delete shrubberyCreation;
}

void TestMakeMoreForm() {
	Bureaucrat Bur1("Bur1", 1);
	Intern Int1;
	AForm *shrubberyCreation = NULL;
	AForm *robotomyRequest = NULL;
	AForm *presidentalPardon = NULL;
	AForm *iDontExist = NULL;

	try {
		shrubberyCreation = Int1.makeForm("shrubbery creation", "home");
		robotomyRequest = Int1.makeForm("robotomy request", "idiotTasks");
		presidentalPardon = Int1.makeForm("presidental pardon", "TVA");
		std::cout << std::endl << std::endl;
		iDontExist = Int1.makeForm("dontexist", "nope");
		std::cout << std::endl << std::endl;
	} catch (const std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	Bur1.signForm(*shrubberyCreation);
	Bur1.executeForm(*shrubberyCreation);
	std::cout << std::endl;
	Bur1.signForm(*robotomyRequest);
	Bur1.executeForm(*robotomyRequest);
	std::cout << std::endl;
	Bur1.signForm(*presidentalPardon);
	Bur1.executeForm(*presidentalPardon);
	std::cout << std::endl;
	try {
		if (iDontExist == NULL)
			throw(AForm::AFormIsNullException());
		Bur1.signForm(*iDontExist);
		Bur1.executeForm(*iDontExist);
	} catch (const std::exception &error) {
		std::cout << "iDontExist" << error.what() << std::endl << std::endl;
	}
	delete iDontExist;
	delete presidentalPardon;
	delete robotomyRequest;
	delete shrubberyCreation;
}

int main(void) {
	TestMakeForm();
	TestMakeMoreForm();
	return 0;
}