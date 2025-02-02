#include "../inc/Bureaucrat.hpp"

#include "../inc/Form.hpp"

// CONSTRUCTORS / DESTRUCTOR
Bureaucrat::Bureaucrat() : name(DEFAULT), grade(42) {
	std::cout << name << CONSTRUCTOR << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &_name, int _grade) : name(_name) {
	if (_grade < MaxGrade)
		throw(Bureaucrat::GradeTooHighException());
	if (_grade > MinGrade)
		throw(Bureaucrat::GradeTooLowException());
	grade = _grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) {
	std::cout << BUREAUCRAT << name << COPYCON << std::endl;
	*this = cpy;
}

Bureaucrat::~Bureaucrat() { std::cout << name << DESTRUCTOR << std::endl; }

// OPERATOR OVERLOADS
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << BUREAUCRAT << name << ASSIGNMENT << std::endl;
	grade = rhs.grade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	os << "The grade of " << bureaucrat.getName() << " is: " << bureaucrat.getGrade() << std::endl;
	return os;
}

// NESTED CLASSES
const char *Bureaucrat::WrongDecrementException::what() const throw() {
	return WD;
}
const char *Bureaucrat::WrongIncrementException::what() const throw() {
	return WI;
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return GTL;
}
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return GTH;
}

// GETTERS / SETTERS
int Bureaucrat::getGrade() const {
	return grade;
}
std::string const &Bureaucrat::getName() const {
	return name;
}

// FUNCTIONS
void Bureaucrat::IncrementGrade() {
	if (grade <= MaxGrade) throw(Bureaucrat::WrongIncrementException());
	std::cout << BUREAUCRAT << name << INCR << std::endl;
	grade--;
}

void Bureaucrat::DecrementGrade() {
	if (grade >= MinGrade) throw(Bureaucrat::WrongDecrementException());
	std::cout << BUREAUCRAT << name << DECR << std::endl;
	grade++;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
	} catch (const std::exception &error) {
		std::cerr << form.Name() << error.what() << std::endl;
	}
}