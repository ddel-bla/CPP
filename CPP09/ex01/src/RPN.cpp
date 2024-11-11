#include "../inc/RPN.hpp"

RPN::~RPN() {
    //std::cout << "RPN destructor called" << std::endl;
}

RPN::RPN( void ) {
    //std::cout << "RPN constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN &other) {
	//std::cout << "RPN copy assignment operator called" << std::endl;
    this->num = other.num;
	return *this;
}

RPN::RPN(const RPN &cp) {
	//std::cout << "RPN copy constructor called" << std::endl;
	*this = cp;
}

void RPN::pushfrontQueue(int n) {
	this->num.push_front(n);
}

void RPN::pushbackQueue(int n) {
	this->num.push_back(n);
}

void RPN::popfrontQueue() {
	this->num.pop_front();
}

void RPN::popbackQueue() {
	this->num.pop_back();
}

void RPN::printDeque() {
	for (size_t i = 0; i < this->num.size(); ++i)
        std::cout << this->num[i] << std::endl;
}

int RPN::operator[](size_t i) {
    if(this->num.size() <= i)
		throw RPN::ExceptionErr();
	return this->num.at(i);
}

int RPN::getSize() {
	return (num.size());
}

void RPN::aux(RPN& num, int result) {
	num.popfrontQueue();
	num.popfrontQueue();
	num.pushfrontQueue(result);
}

void RPN::calculate(RPN& num, char symbol) {
	if (num.getSize() < 2)
		throw RPN::ExceptionErr();

	int right = num[0];
	int left = num[1];

	switch (symbol) {
		case '+':
			if ((left > 0 && right > std::numeric_limits<int>::max() - left) ||
			    (left < 0 && right < std::numeric_limits<int>::min() - left))
				throw RPN::ExceptionErr();
			aux(num, left + right);
			break;

		case '-':
			if ((left < 0 && right > std::numeric_limits<int>::max() + left) ||
			    (left > 0 && right < std::numeric_limits<int>::min() + left))
				throw RPN::ExceptionErr();
			aux(num, left - right);
			break;
		case '*':
			if (left != 0 && (right > std::numeric_limits<int>::max() / left || right < std::numeric_limits<int>::min() / left))
				throw RPN::ExceptionErr();
			aux(num, left * right);
			break;

		case '/':
			if (right == 0)
				throw RPN::ExceptionErr();
			if (left == std::numeric_limits<int>::min() && right == -1)
				throw RPN::ExceptionErr();
			aux(num, left / right);
			break;

		default:
			throw RPN::ExceptionErr();
	}
}
