#include <exception>

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

void TestShrubbery() {
	try {
		Bureaucrat Buro1("Buro1", 130);
		ShrubberyCreationForm shrub1("shrub1");

		std::cout << std::endl;
		Buro1.signForm(shrub1);
		shrub1.execute(Buro1);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cout << error.what() << std::endl;
	}
}

void TestRobotomy() {
	try {
		Bureaucrat Buro1("Buro1", 30);
		RobotomyRequestForm shrub1("shrub1");

		std::cout << std::endl;
		Buro1.signForm(shrub1);
		shrub1.execute(Buro1);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cout << error.what() << std::endl;
	}
}

void TestPardon() {
	try {
		Bureaucrat Buro1("Buro1", 2);
		PresidentialPardonForm Presi1("Presi1");

		std::cout << std::endl;
		Buro1.signForm(Presi1);
		Presi1.execute(Buro1);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cout << error.what() << std::endl;
	}
}

int main(void) {
	TestShrubbery();
	TestRobotomy();
	TestPardon();
	return 0;
}