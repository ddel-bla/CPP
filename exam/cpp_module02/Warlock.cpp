#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!\n";
}

std::string const & Warlock::getName() const
{
	return _name;
}

std::string const & Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(std::string const & title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am "<< _name << ", " << _title << "!\n";
}

void Warlock::learnSpell(ASpell * spell)
{
	if (spell)
		_book[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string name)
{
	if (_book.find(name) != _book.end())
	{
		delete _book[name];
		_book.erase(_book.find(name));
	}
}
void Warlock::launchSpell(std::string name, ATarget const & target)
{
	if (_book.find(name) != _book.end())
		_book[name]->launch(target);
}
