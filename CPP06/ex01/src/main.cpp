#include "../inc/Serializer.hpp"

int main() {
	uintptr_t raw;
	
	Data *dataToSerialize = new Data;
	Data *deserializedData;

	dataToSerialize->str = "Texto para sin serializar.";
	dataToSerialize->c = 'x';
	dataToSerialize->i = 42;
	std::cout << "     PRE-DATA" << std::endl;
	std::cout << dataToSerialize->str << std::endl;
	std::cout << dataToSerialize->c << std::endl;
	std::cout << dataToSerialize->i << std::endl;
	std::cout << std::endl;

	raw = Serializer::serialize(dataToSerialize);
	std::cout << "     SERIALIZED" << std::endl;
	std::cout << raw << std::endl;
	std::cout << std::endl;

	deserializedData = Serializer::deserialize(raw);
	std::cout << "     POST-DATA" << std::endl;
	std::cout << deserializedData->str << std::endl;
	std::cout << deserializedData->c << std::endl;
	std::cout << deserializedData->i << std::endl;

	delete dataToSerialize;
	return 0;
}
