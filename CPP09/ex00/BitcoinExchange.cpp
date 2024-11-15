#include "BitcoinExchange.hpp"

Bitcoin::~Bitcoin() {
	//std::cout << "Bitcoin destructor called" << std::endl;
}

Bitcoin::Bitcoin( void ): bitcoin(0) {
	//std::cout << "Bitcoin constructor called" << std::endl;
}

Bitcoin::Bitcoin(std::string coin, int n) {
	bool foundPoint = false;
	if(coin[0] == '-')
		throw ExceptionNegativedNumber();
	if (coin.empty())
		throw ExceptionInvalidNumber();
	for (size_t i = 0; i < coin.size(); ++i) 
	{
		if (!std::isdigit(static_cast<unsigned char>(coin[i]))) {
			if (coin[i] == '.') {
				if (foundPoint)
					throw ExceptionInvalidNumber();
				foundPoint = true;
			} else
				throw ExceptionInvalidNumber();
		}
	}
	float aux = static_cast<float>(atof(coin.c_str()));
	if(n == 1 && aux <= 1000 && aux >= 0 )
		this->bitcoin = aux;
	else if(n == 0)
		this->bitcoin = aux;
	else if(aux > 1000)
		throw ExceptionLargeNumber();
}

std::ostream& operator<<(std::ostream& stout, const Bitcoin& Bitcoin) {
	stout << Bitcoin.getBitcoin();
	return stout;
}

Bitcoin& Bitcoin::operator=(const Bitcoin &other) {
	//std::cout << "Bitcoin copy assignment operator called" << std::endl;
	this->bitcoin = other.bitcoin;
	return *this;
}

Bitcoin::Bitcoin(const Bitcoin &cp) {
	//std::cout << "Bitcoin copy constructor called" << std::endl;
	*this = cp;
}

float Bitcoin::getBitcoin() const {
	return this->bitcoin;
}

// Cambia la definición de DaysMonth a Bitcoin::Date::DaysMonth
const int Bitcoin::Date::DaysMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Bitcoin::Date::~Date() {
	//std::cout << "Date Destructor called" << std::endl;
}

Bitcoin::Date::Date( void ): year(0), month(0), day(0) {
	//std::cout << "Date Constructor called" << std::endl;
}

Bitcoin::Date::Date(std::string date) {
	if (date.length() != 10)
		throw ExceptionInvalidDate();
	for (int i = 0; i < 10; ++i) {
		if ((i == 4 || i == 7) && date[i] != '-')
			throw ExceptionInvalidDate();
		else if ((i != 4 && i != 7) && !isdigit(date[i]))
			throw ExceptionInvalidDate();
	}
	int _year = atoi(date.substr(0, 4).c_str());
	int _month = atoi(date.substr(5, 2).c_str());
	int _day = atoi(date.substr(8, 2).c_str());
	if (_month == 0 || _month > 12 || _day == 0 || _day > DaysMonth[_month - 1])
		throw ExceptionInvalidDate();
	this->year = _year;
	this->month = _month;
	this->day = _day;
}

bool Bitcoin::Date::operator<(const Date& other) const {
	if (this->year > other.year) {
		return false; }
	if (this->year < other.year) {
		return true; }
	if (this->month > other.month) {
		return false; }
	if (this->month < other.month) {
		return true; }
	return this->day > other.day;
}

// Operador de salida para Bitcoin::Date
std::ostream& operator<<(std::ostream& stout, const Bitcoin::Date& Date) {
	stout << Date.getYear() << "-" << Date.getMonth() << "-" << Date.getDay();
	return stout;
}

Bitcoin::Date& Bitcoin::Date::operator=(const Date &other) {
	//std::cout << "Date copy assignment operator called" << std::endl;
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
	return *this;
}

Bitcoin::Date::Date(const Date &cp) {
	//std::cout << "Date copy constructor called" << std::endl;
	*this = cp;
}

int Bitcoin::Date::getDay() const { return this->day; }
int Bitcoin::Date::getMonth() const { return this->month; }
int Bitcoin::Date::getYear() const { return this->year; }
