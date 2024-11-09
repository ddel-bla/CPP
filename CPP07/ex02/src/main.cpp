
#include "../inc/Array.hpp"
#include <iostream>

int main() {
	try {
		// Prueba 1: Crear un array vacío y verificar su tamaño
		Array<int> emptyArray;
		std::cout << "Empty array size: " << emptyArray.size() << std::endl;

		// Prueba 2: Crear un array con tamaño específico y verificar el acceso
		Array<int> intArray(3);
		intArray[0] = 42;
		intArray[1] = 21;
		intArray[2] = 84;
		std::cout << "intArray[0]: " << intArray[0] << ", intArray[1]: " << intArray[1] << ", intArray[2]: " << intArray[2] << std::endl;

		// Prueba 3: Verificar copia y operador de asignación
		Array<int> copyArray = intArray;
		intArray[0] = 100;  
		// Cambiar el original no debe afectar la copia
		std::cout << "copyArray[0]: " << copyArray[0] << ", intArray[0]: " << intArray[0] << std::endl;

		// Prueba 4: Acceso fuera de los límites
		try {
			std::cout << intArray[3] << std::endl;  
		} catch (const std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
	} catch (const std::exception& error) {
		std::cout << "Caught exception: " << error.what() << std::endl;
	}

	return 0;
}
