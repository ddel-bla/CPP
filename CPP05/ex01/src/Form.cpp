#include "../inc/Form.hpp"

// CONSTRUCTORS / DESTRUCTOR
Form::Form() : formName(DEFORM), isSigned(false), gradeSign(42), gradeExec(42) {
	std::cout << formName << CONSTRUCTOR << std::endl;
}

Form::Form(std::string const &_formName, bool _isSigned, const int _gradeSign, const int _gradeExec)
	: formName(_formName), isSigned(_isSigned), gradeSign(_gradeSign), gradeExec(_gradeExec) {
	if (_gradeSign < MaxGrade) {
		throw(Form::FormGradeTooHighException());
	}
	if (_gradeSign > MinGrade) {
		throw(Form::FormGradeTooLowException());
	}
}

Form::Form(Form const &cpy)
	: formName(cpy.formName), isSigned(cpy.isSigned), gradeSign(cpy.gradeSign), gradeExec(cpy.gradeExec) {
	std::cout << formName << COPYCON << std::endl;
	*this = cpy;
}

Form::~Form() { std::cout << formName << DESTRUCTOR << std::endl; }

// OPERATOR OVERLOADS
Form &Form::operator=(Form const &rhs) {
	std::cout << FORM << formName << ASSIGNMENT << std::endl;
	isSigned = rhs.isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &os, Form &form) {
	os << "The grade of " << form.Name() << " is: " << form.getGradeSign();
	if (form.getIsSigned() == false) os << " is not";
	os << " signed" << std::endl;
	return os;
}

// NESTED CLASSES
const char *Form::FormGradeTooLowException::what() const throw() {
	return F_GTL;
}
const char *Form::FormGradeTooHighException::what() const throw() {
	return F_GTH;
}
const char *Form::FormCannotBeSignedExecption::what() const throw() {
	return FCBS;
}
const char *Form::FormIsAlreadySignedExecption::what() const throw() {
	return FIAS;
}

// GETTERS / SETTERS
int Form::getGradeSign() const {
	return gradeSign;
}
int Form::getGradeExec() const {
	return gradeExec;
}
std::string const &Form::Name() const {
	return formName;
}
bool Form::getIsSigned() const {
	return isSigned;
}

// FUNCTIONS
void Form::beSigned(Bureaucrat &bureaucrap) {
	if (getIsSigned() == true) throw(Form::FormIsAlreadySignedExecption());
	if (bureaucrap.getGrade() > gradeSign) throw(Form::FormCannotBeSignedExecption());
	std::cout << BUREAUCRAT << bureaucrap.getName() << SIGNED << formName << std::endl;
	isSigned = true;
}
