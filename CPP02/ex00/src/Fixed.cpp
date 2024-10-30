#include "../inc/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixed(0) {
	std::cout << CONSTRUCTOR << std::endl;
}

Fixed::Fixed(Fixed const &number) {
	std::cout << COPY << std::endl;
	*this = number;
}

Fixed::~Fixed() { 
	std::cout << DESTRUCTOR << std::endl;
}

Fixed &Fixed::operator=(Fixed const &number) {
	std::cout << COPYASSIGN << std::endl;
	if (this != &number) 
		this->_fixed = number.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw) {
	std::cout << SETRAWBITS << std::endl;
	_fixed = raw;
}

int Fixed::getRawBits(void) const {
	std::cout << GETRAWBITS << std::endl;
	return (_fixed);
}
