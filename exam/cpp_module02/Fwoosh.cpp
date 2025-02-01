
#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "turned into a critter")
{
}

Fwoosh::~Fwoosh()
{
}

ASpell * Fwoosh::clone() const
{
	return (new Fwoosh());
}
