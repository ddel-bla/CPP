#include "RPN.hpp"

RPN::~RPN()
{
    //std::cout << "RPN destructor called" << std::endl;
}

RPN::RPN( void )
{
    //std::cout << "RPN constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN &other)
{
	//std::cout << "RPN copy assignment operator called" << std::endl;
    this->num = other.num;
	return *this;
}

RPN::RPN(const RPN &cp)
{
	//std::cout << "RPN copy constructor called" << std::endl;
	*this = cp;
}

void RPN::pushfrontQueue(int n)
{
	this->num.push_front(n);
}

void RPN::pushbackQueue(int n)
{
	this->num.push_back(n);
}

void RPN::popfrontQueue()
{
	this->num.pop_front();
}

void RPN::popbackQueue()
{
	this->num.pop_back();
}

void RPN::printDeque()
{
	for (size_t i = 0; i < this->num.size(); ++i)
        std::cout << this->num[i] << std::endl;
}

int RPN::operator[](size_t i) 
{
    if(this->num.size() <= i)
		throw RPN::ExceptionErr();
	return this->num.at(i);
}

int RPN::getSize()
{
	return (num.size());
}