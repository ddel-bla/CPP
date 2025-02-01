#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget 
{
	private:
		std::string _name;
	public:
		ATarget(std::string name);
		virtual ~ATarget();
		std::string const & getName() const;
		virtual ATarget * clone() const = 0;
		void getHitBySpell(ASpell const & spell) const;
};