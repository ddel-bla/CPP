#include "../inc/Fixed.hpp"

Fixed::Fixed() {
	std::cout << CONSTRUCTOR << std::endl;
}

Fixed::Fixed(Fixed const &number) {
	std::cout << COPY << std::endl;
	*this = number;
}

Fixed::Fixed(int const number) {
	std::cout << INT_CALL << std::endl;
	_fixed = number << _fractional;
}

Fixed::Fixed(float const number) {
	std::cout << FLOAT_CALL << std::endl;
	_fixed = roundf(number * (1 << _fractional));
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

int Fixed::getRawBits(void) const {
	std::cout << GETRAWBITS << std::endl;
	return (_fixed);
}

void Fixed::setRawBits(int const raw) {
	std::cout << SETRAWBITS << std::endl;
	_fixed = raw;
}

int Fixed::toInt(void) const {
	return (_fixed >> _fractional);
}

float Fixed::toFloat(void) const {
	return (float(_fixed) / (1 << _fractional));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed_num) {
	return (os << fixed_num.toFloat());
}
