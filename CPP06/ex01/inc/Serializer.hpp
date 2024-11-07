#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iostream>
#include <stdint.h>
#include "../inc/Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(Serializer const &cpy);
		~Serializer();
		Serializer &operator=(Serializer const &rhs);

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif