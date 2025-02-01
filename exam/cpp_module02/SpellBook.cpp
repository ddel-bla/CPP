
#include "SpellBook.hpp"

void SpellBook::learnSpell(ASpell* obj)
{
	if (obj)
		_book[obj->getName()] = obj;
}

void SpellBook::forgetSpell(std::string const & name)
{
	if (_book.find(name) != _book.end())
	{
		delete _book[name];
		_book.erase(_book.find(name));
	}
}

ASpell * SpellBook::createSpell(std::string const & name)
{
	ASpell * tmp = NULL;
	if (_book.find(name) != _book.end())
		tmp = _book[name];
	return tmp;
}

