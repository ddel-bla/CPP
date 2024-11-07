#include "../inc/Identify.hpp"

// CONSTRUCTORS / DESTRUCTOR
Identify::Identify() {}
Identify::Identify(Identify const &cpy) { *this = cpy; }
Identify::~Identify() {}

// OPERATOR OVERLOADS
Identify &Identify::operator=(Identify const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

// FUNCTIONS
static void gmessage(char id) { std::cout << id << CREATED << std::endl; }
static void imessage(char id) { std::cout << id << IS << id << std::endl; }
static void rmessage(char id) { std::cout << id << REF << id << std::endl; }

Base *Identify::generate(void) {
	int i = std::rand() % 3;

	if (i % 3 == 0)
		return gmessage('A'), new A();
	else if (i % 3 == 1)
		return gmessage('B'), new B();
	else if (i % 3 == 2)
		return gmessage('C'), new C();
	return NULL;
}

void Identify::identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL)
		imessage('A');
	else if (dynamic_cast<B *>(p) != NULL)
		imessage('B');
	else if (dynamic_cast<C *>(p) != NULL)
		imessage('C');
	else
		std::cout << BADCAST << std::endl;
}

void Identify::identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		return rmessage('A');
	} catch (std::exception &error) {}
	try {
		(void)dynamic_cast<B &>(p);
		return rmessage('B');
	} catch (std::exception &error) {}
	try {
		(void)dynamic_cast<C &>(p);
		return rmessage('C');
	} catch (std::exception &error) {}
	std::cout << BADREF << std::endl;
}
