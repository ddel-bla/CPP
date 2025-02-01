#include "ATarget.hpp"

ATarget::ATarget(std::string name) : _name(name)
{
}

ATarget::~ATarget()
{
}

std::string const & ATarget::getName() const
{
	return _name;
}

void ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << _name << " has been " << spell.getEffects() << "!\n";
}
