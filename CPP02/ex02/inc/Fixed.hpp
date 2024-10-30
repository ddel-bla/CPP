#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

#define ASINT		" as integer"
#define FLOAT_CALL	"Float constructor called"
#define INT_CALL	"Int constructor called"
#define CONSTRUCTOR	"Default constructor called"
#define COPY		"Copy constructor called"
#define COPYASSIGN	"Copy assignment operator called"
#define DESTRUCTOR	"Destructor called"
#define GETRAWBITS	"getRawBits member function called"
#define SETRAWBITS	"setRawBits member function called"

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const &number);
		Fixed(int const number);
		Fixed(float const number);
		~Fixed(void);
		Fixed	&operator=(Fixed const &number);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int 				_fixed;
		static const int	_fractional = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed_num);

#endif