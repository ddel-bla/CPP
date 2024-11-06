#include "../inc/AForm.hpp"

// CONSTRUCTORS / DESTRUCTOR
AForm::AForm() : AFormName(DEFORM), isSigned(false), gradeSign(42), gradeExec(42) {
	std::cout << AFormName << CONSTRUCTOR << std::endl;
}

AForm::AForm(std::string const &_AFormName, bool _isSigned, const int _gradeSign, const int _gradeExec)
	: AFormName(_AFormName), isSigned(_isSigned), gradeSign(_gradeSign), gradeExec(_gradeExec) {
	if (_gradeSign < MaxGrade) {
		throw(AForm::AFormGradeTooHighException());
	}
	if (_gradeSign > MinGrade) {
		throw(AForm::AFormGradeTooLowException());
	}
}

AForm::AForm(AForm const &cpy)
	: AFormName(cpy.AFormName), isSigned(cpy.isSigned), gradeSign(cpy.gradeSign), gradeExec(cpy.gradeExec) {
	std::cout << AFormName << COPYCON << std::endl;
	*this = cpy;
}

AForm::~AForm() { std::cout << AFormName << DESTRUCTOR << std::endl; }

// OPERATOR OVERLOADS
AForm &AForm::operator=(AForm const &rhs) {
	std::cout << FORM << AFormName << ASSIGNMENT << std::endl;
	isSigned = rhs.isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &os, AForm &AForm) {
	os << "The grade of " << AForm.Name() << " is: " << AForm.getGradeSign();
	if (AForm.getIsSigned() == false) os << " is not";
	os << " signed" << std::endl;
	return os;
}

// NESTED CLASSES
const char *AForm::AFormGradeTooLowException::what() const throw() {
	return F_GTL;
}
const char *AForm::AFormGradeTooHighException::what() const throw() {
	return F_GTH;
}
const char *AForm::AFormCannotBeSignedExecption::what() const throw() {
	return FCBS;
}
const char *AForm::AFormIsAlreadySignedExecption::what() const throw() {
	return FIAS;
}
const char *AForm::AFormRobotomyFailedException::what() const throw() {
	return RFE;
}
const char *AForm::AFormCannotExecuteException::what() const throw() {
	return CEE;
}
const char *AForm::AFormCreationFailedException::what() const throw() {
	return FCF;
}
const char *AForm::AFormIsNullException::what() const throw() {
	return ISNULL;
}

// GETTERS / SETTERS
int AForm::getGradeSign() const {
	return gradeSign;
}
int AForm::getGradeExec() const {
	return gradeExec;
}
std::string const &AForm::Name() const {
	return AFormName;
}
bool AForm::getIsSigned() const {
	return isSigned;
}

// FUNCTIONS
void AForm::beSigned(Bureaucrat &bureaucrap) {
	if (getIsSigned() == true)
		throw(AForm::AFormIsAlreadySignedExecption());
	if (bureaucrap.getGrade() > gradeSign)
		throw(AForm::AFormCannotBeSignedExecption());
	std::cout << BUREAUCRAT << bureaucrap.getName() << SIGNED << AFormName << std::endl;
	isSigned = true;
}
