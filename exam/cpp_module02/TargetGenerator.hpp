#pragma once
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
		std::map < std::string , ATarget * > _book;
	public:
		void learnTargetType(ATarget * obj);
		void forgetTargetName(std::string const & name);
		ATarget * createTarget(std::string const & name);
};
