#include "ATarget.hpp"

ATarget::ATarget(std::string type) : _type(type)
{
}

ATarget::~ATarget()
{
}

std::string const & ATarget::getName() const
{
	return _type;
}

void ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!\n";
}
