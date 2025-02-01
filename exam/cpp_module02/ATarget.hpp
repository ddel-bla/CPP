#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget 
{
	private:
		std::string _type;
	public:
		ATarget(std::string type);
		virtual ~ATarget();
		std::string const & getName() const;
		virtual ATarget * clone() const = 0;
		void getHitBySpell(ASpell const & spell) const;
};