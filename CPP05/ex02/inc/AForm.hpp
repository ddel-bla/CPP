#ifndef AForm_HPP
#define AForm_HPP

#include <cstdlib>
#include <exception>

#include "Bureaucrat.hpp"
#include "Defines.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const AFormName;
		bool isSigned;
		const int gradeSign;
		const int gradeExec;
	public:
		static const int MinGrade = 150;
		static const int MaxGrade = 1;
		AForm();
		AForm(std::string const &_AFormName, bool _isSigned, const int _gradeSign, const int _gradeExec);
		AForm(AForm const &cpy);
		virtual ~AForm();
		AForm &operator=(AForm const &rhs);
		int getGradeSign() const;
		int getGradeExec() const;
		std::string const &Name() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat &bureaucrap);
		virtual void execute(Bureaucrat const &executor) const = 0;
		class AFormGradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class AFormGradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class AFormCannotBeSignedExecption : public std::exception {
			public:
				const char *what() const throw();
		};
		class AFormIsAlreadySignedExecption : public std::exception {
			public:
				const char *what() const throw();
		};
		class AFormCannotExecuteException : public std::exception {
			public:
				const char *what() const throw();
		};
		class AFormRobotomyFailedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm &AForm);

#endif