#ifndef FORM_HPP
#define FORM_HPP

#include <exception>

#include "Bureaucrat.hpp"
#include "Defines.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const formName;
		bool isSigned;
		const int gradeSign;
		const int gradeExec;
	public:
		static const int MinGrade = 150;
		static const int MaxGrade = 1;
		// OPERATOR OVERLOADS
		Form();
		Form(std::string const &_formName, bool _isSigned, const int _gradeSign, const int _gradeExec);
		Form(Form const &cpy);
		~Form();
		Form &operator=(Form const &rhs);
		// GETTERS / SETTERS
		int getGradeSign() const;
		int getGradeExec() const;
		std::string const &Name() const;
		bool getIsSigned() const;
		// FUNCTIONS
		void beSigned(Bureaucrat &bureaucrap);
		// NESTED CLASSES
		class FormGradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class FormGradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class FormCannotBeSignedExecption : public std::exception {
			public:
				const char *what() const throw();
		};
		class FormIsAlreadySignedExecption : public std::exception {
			public:
				const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &os, Form &form);

#endif