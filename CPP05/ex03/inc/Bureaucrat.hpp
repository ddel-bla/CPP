#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include "Defines.hpp"

class AForm;

class Bureaucrat {
	private:
		std::string const name;
		int grade;
	public:
		static const int MinGrade = 150;
		static const int MaxGrade = 1;
		Bureaucrat();
		Bureaucrat(Bureaucrat const &cpy);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &rhs);
		Bureaucrat(std::string const &_name, int _grade);
		std::string const &getName() const;
		int getGrade() const;
		void IncrementGrade();
		void DecrementGrade();
		void signForm(AForm &formName);
		void executeForm(AForm const &form);

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class WrongIncrementException : public std::exception {
			public:
				const char *what() const throw();
		};
		class WrongDecrementException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
