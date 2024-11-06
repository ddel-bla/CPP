#include "../inc/Bureaucrat.hpp"

static void TestIncrement() {
	Bureaucrat Buro1("Buro1", 120);

	std::cout << Buro1;
	Buro1.IncrementGrade();
	std::cout << Buro1;
	Buro1.IncrementGrade();
	std::cout << Buro1;
	Buro1.IncrementGrade();
	std::cout << Buro1 << std::endl;
}

static void TestDecrement() {
	Bureaucrat Buro1("Buro1", 10);

	std::cout << Buro1;
	Buro1.DecrementGrade();
	std::cout << Buro1;
	Buro1.DecrementGrade();
	std::cout << Buro1;
	Buro1.DecrementGrade();
	std::cout << Buro1 << std::endl;
}

static void TestGradeRangeIncrement() {
	Bureaucrat Buro1("Buro1", 140);
	try {
		while (true) {
			std::cout << Buro1;
			Buro1.IncrementGrade();
		}
	} catch (const std::exception &error) {
		std::cerr << Buro1.getName() << error.what() << std::endl;
	}
}

static void TestGradeRangeDecrement() {
	Bureaucrat Buro1("Buro1", 10);
	try {
		while (true) {
			std::cout << Buro1;
			Buro1.DecrementGrade();
		}
	} catch (const std::exception &error) {
		std::cerr << Buro1.getName() << error.what() << std::endl;
	}
}

static void TestTooHighGrade() {
	Bureaucrat Buro1;
	try {
		Bureaucrat Buro1("Buro1", 0);
		while (true) {
			std::cout << Buro1;
			Buro1.IncrementGrade();
		}
	} catch (const std::exception &error) {
		std::cerr << Buro1.getName() << error.what() << std::endl;
	}
}

static void TestTooLowGrade() {
	Bureaucrat Buro1;
	try {
		Bureaucrat Buro1("Buro1", 151);
		while (true) {
			std::cout << Buro1;
			Buro1.DecrementGrade();
		}

	} catch (const std::exception &error) {
		std::cerr << Buro1.getName() << error.what() << std::endl;
	}
}

int main(void) {

	TestIncrement();
	TestDecrement();
	TestGradeRangeIncrement();
	TestGradeRangeDecrement();
	TestTooLowGrade();
	std::cout << std::endl;
	TestTooHighGrade();
	return 0;
}