#include "TargetGenerator.hpp"

void TargetGenerator::learnTargetType(ATarget * obj)
{
	if (obj)
		_book[obj->getName()] = obj;
}

void TargetGenerator::forgetTargetName(std::string const & name)
{
	if (_book.find(name) != _book.end())
	{
		delete _book[name];
		_book.erase(_book.find(name));
	}
}

ATarget * TargetGenerator::createTarget(std::string const & name)
{
	ATarget * tmp = NULL;
	if (_book.find(name) != _book.end())
		tmp = _book[name];
	return tmp;
}
