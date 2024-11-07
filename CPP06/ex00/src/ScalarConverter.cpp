#include "../inc/ScalarConverter.hpp"

// CONSTRUCTORS / DESTRUCTOR 
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &cpy) { *this = cpy; }
ScalarConverter::~ScalarConverter() {}

// OPERATOR OVERLOADS
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	if (this != &rhs) *this = rhs;
	return *this;
}

// NESTED CLASSES
const char *ScalarConverter::WrongInputException::what() const throw() {
	return WRONGINPUT;
}
const char *ScalarConverter::ArgCountException::what() const throw() {
	return ARGCOUNT;
}

// FUNCTIONS
void ScalarConverter::convert(std::string &input) {
	std::string trimmedInput = trimSpace(input, " ");
	if (type == CHAR)
		ScalarConverter::convertChar(trimmedInput);
	if (type == INF)
		ScalarConverter::convertInfinity(trimmedInput);
	if (type == NUMBER)
		ScalarConverter::convertNumber(trimmedInput);
}

void ScalarConverter::convertChar(std::string &input) {
	std::cout << PCHAR << static_cast<char>(input[0]) << std::endl;
	std::cout << PINT << static_cast<int>(input[0]) << std::endl;
	std::cout << PFLOAT << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << F << std::endl;
	std::cout << PDOUBLE << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
}

void ScalarConverter::convertInfinity(std::string &input) {
	std::cout << PCHAR << IMPOSSIBLE << std::endl;
	std::cout << PINT << IMPOSSIBLE << std::endl;
	if (input.compare(NAN) == 0 || input.compare(NANF) == 0) {
		std::cout << PFLOAT << std::numeric_limits<float>::quiet_NaN() << F << std::endl;
		std::cout << PDOUBLE << std::numeric_limits<double>::quiet_NaN() << std::endl;
	} else {
		std::cout << PFLOAT << std::numeric_limits<float>::infinity() << F << std::endl;
		std::cout << PDOUBLE << std::numeric_limits<double>::infinity() << std::endl;
	}
}

void ScalarConverter::convertNumber(std::string &input) {
	double number;
	if (input[input.size() - 1] == 'f') input.erase(input.size() - 1);
	std::istringstream iss(input);
	iss >> number;
	if (number > 32 && 127 > number)
		std::cout << PCHAR << static_cast<char>(number) << std::endl;
	else
		std::cout << PCHAR << NONDISPL << std::endl;
	ScalarConverter::convertInt(number);
	ScalarConverter::convertFloat(number);
	ScalarConverter::convertDouble(number);
}

void ScalarConverter::convertInt(double &number) {
	if (std::numeric_limits<int>::max() < number || -std::numeric_limits<int>::max() > number)
		std::cout << PINT << IMPOSSIBLE << std::endl;
	else
		std::cout << PINT << static_cast<int>(number) << std::endl;
}

void ScalarConverter::convertFloat(double &number) {
	if (static_cast<double>(std::numeric_limits<float>::max()) < number || -static_cast<double>(std::numeric_limits<float>::max()) > number)
		std::cout << PFLOAT << IMPOSSIBLE << std::endl;
	else
		std::cout << PFLOAT << std::fixed << std::setprecision(1) << static_cast<float>(number) << F << std::endl;
}

void ScalarConverter::convertDouble(double &number) {
	if (std::numeric_limits<double>::max() < number || -std::numeric_limits<double>::max() > number)
		std::cout << PDOUBLE << IMPOSSIBLE << std::endl;
	else
		std::cout << PDOUBLE << std::fixed << std::setprecision(1) << number << std::endl;
}
