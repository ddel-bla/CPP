#pragma once
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class SpellBook
{
	private:
		std::map < std::string , ASpell * > _book;
	public:
		void learnSpell(ASpell* obj);
		void forgetSpell(std::string const & name);
		ASpell * createSpell(std::string const & name);
};
