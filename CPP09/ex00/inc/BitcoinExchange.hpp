#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

class Bitcoin
{
	private:
		float bitcoin;
	public:
		~Bitcoin(void);
		Bitcoin(void);
		Bitcoin(std::string bitcoin, int n);
		Bitcoin(const Bitcoin &cp);
		Bitcoin& operator=(const Bitcoin &other);
		float getBitcoin() const;

		class ExceptionInvalidNumber: public std::exception {
			virtual const char* what() const throw() {
				return "Error: invalid number.";
			}
		};

		class ExceptionNegativedNumber: public std::exception {
			virtual const char* what() const throw() {
				return "Error: not a positive number.";
			}
		};

		class ExceptionLargeNumber: public std::exception {
			virtual const char* what() const throw() {
				return "Error: too large a number.";
			}
		};
};

class Date
{
	private:
		int year;
		int month;
		int day;
		static const int DaysMonth[12];
	public:
		~Date(void);
		Date(void);
		Date(const Date &cp);
		Date(std::string date);
		Date& operator=(const Date &other);
		bool operator<(const Date& other) const;
		int getMonth() const;
		int getYear() const;
		int getDay() const;

		class ExceptionInvalidDate: public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Error: bad input";
			}
		};
};

std::ostream& operator<<(std::ostream& stout, const Date& Date);

std::ostream& operator<<(std::ostream& stout, const Bitcoin& Bitcoin);

#endif