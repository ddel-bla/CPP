#include "../inc/Form.hpp"

void TestFormSigning() {
	std::cout << std::endl;
	try {
		Bureaucrat Buro1("Buro1", 42);
		Form Form2("Form2", false, 42, 1);
		Buro1.signForm(Form2);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}
}

void TestAlreadySigned() {
	std::cout << std::endl;
	try {
		Bureaucrat Buro1("Buro1", 42);
		Bureaucrat Buro2("Buro2", 42);
		Form Form2("Form2", false, 42, 1);
		Buro1.signForm(Form2);
		Buro2.signForm(Form2);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}
}

void TestRequirement() {
	std::cout << std::endl;
	try {
		Form Form1("Form1", false, -10, 1);
		Form Form2("Form2", false, 14, 1);
		Bureaucrat Buro1("Buro1", 42);
		Bureaucrat Buro2("Buro2", 42);

		Buro1.signForm(Form2);
		Buro2.signForm(Form1);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}
}

int main(void) {
	TestFormSigning();
	TestAlreadySigned();
	TestRequirement();
	return 0;
}
