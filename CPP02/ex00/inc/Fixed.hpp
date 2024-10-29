#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
		Fixed &operator=(Fixed const &number);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _fixed;
		static const int _fractional = 8;
};

#endif