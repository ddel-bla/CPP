#include "PmergeMe.hpp"

#include "PmergeMe.hpp"

// Función para verificar si una lista está ordenada
bool Pmerge::checkSortedList(const std::list<int>& lst) {
	if (lst.empty()) return true;

	std::list<int>::const_iterator it = lst.begin();
	std::list<int>::const_iterator next = it;
	++next; 

	while (next != lst.end()) {
		if (*it > *next) {
			return false;
		}
		++it;
		++next;
	}
	return true;
}


// Función para imprimir una lista
void Pmerge::printList(const std::list<int>& lst) {
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// Extrae el último elemento si la lista tiene un número impar de elementos
int Pmerge::extractLastIfOdd(std::list<int>& lst) {
	if (lst.size() % 2 != 0) {
		int lastValue = lst.back();
		lst.pop_back();
		return lastValue;
	}
	return -1;
}

// Llena `pairs` con pares de elementos de `lst`, colocando el mayor como primer elemento de cada par
void Pmerge::createPairsList(const std::list<int>& lst, std::list<std::pair<int, int> >& pairs) {
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
		int first = *it;
		++it;
		int second = *it;

		if (first < second) {
			pairs.push_back(std::make_pair(second, first));
		} else {
			pairs.push_back(std::make_pair(first, second));
		}
	}
}

// Implementación de merge-insertion sort para una lista de pares
void Pmerge::pairInsertionSortList(std::list<std::pair<int, int> >& pairs) {
	if (pairs.size() <= 1) return;

	std::list<std::pair<int, int> > sorted;

	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		std::pair<int, int> key = *it;
		std::list<std::pair<int, int> >::iterator pos = sorted.begin();

		while (pos != sorted.end() && pos->first < key.first) {
			++pos;
		}
		sorted.insert(pos, key);
	}

	pairs = sorted;
}

// Función para encontrar el índice de inserción en una lista ordenada
std::list<int>::iterator Pmerge::findInsertIndexList(std::list<int>& lst, int val) {
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (*it >= val) {
			return it;
		}
	}
	return lst.end();
}

// Insertar `lastValue` en `lst` si `lastValue` es diferente de -1
void Pmerge::insertLastValueIfPresent(std::list<int>& lst, int lastValue) {
	if (lastValue != -1) {
		std::list<int>::iterator it = findInsertIndexList(lst, lastValue);
		lst.insert(it, lastValue);
	}
}

// Función principal para ordenar una lista usando pares
std::list<int> Pmerge::sortList(std::list<int>& lst) {
	std::list<std::pair<int, int> > pairs;
	std::list<int> aux;

	// Si está ordenado, sale
	if (checkSortedList(lst))
		return lst;

	// Extrae el último valor si tiene un número impar de elementos
	int lastValue = extractLastIfOdd(lst);

	// Crear pares con los elementos
	createPairsList(lst, pairs);

	// Ordena los mayores con insertion
	pairInsertionSortList(pairs);

	// Añadir todos los primeros elementos (los mayores) al auxiliar
	for (std::list<std::pair<int, int> >::iterator pair = pairs.begin(); pair != pairs.end(); ++pair) {
		aux.push_back(pair->first);
	}

	// Insertar los segundos elementos de cada par en la posición correspondiente
	for (std::list<std::pair<int, int> >::iterator pair = pairs.begin(); pair != pairs.end(); ++pair) {
		std::list<int>::iterator it = findInsertIndexList(aux, pair->second);
		aux.insert(it, pair->second);
	}

	// Insertar `lastValue` en `aux` si es necesario
	insertLastValueIfPresent(aux, lastValue);
	return aux;
}

// Función para verificar si el vector está ordenado
bool Pmerge::checkSortedVector(const std::vector<int>& vec) {
	for (size_t i = 1; i < vec.size(); ++i) {
		if (vec[i - 1] > vec[i]) {
			return false;
		}
	}
	return true;
}

// Función para imprimir el vector
void Pmerge::printVector(const std::vector<int>& vec) {
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// Función para devolver el último si son impares
int Pmerge::extractLastIfOdd(std::vector<int>& vec) {
	if (vec.size() % 2 != 0) {
		int lastValue = vec.back();
		vec.pop_back();
		return lastValue;
	}
	return -1;
}

// Implementación de merge-insertion sort para un vector de pares
void Pmerge::pairInsertionSort(std::vector<std::pair<int, int> >& pairs) {
	if (pairs.size() <= 1) return;

	std::vector<std::pair<int, int> > sorted;
	sorted.reserve(pairs.size());

	// Insertar todos los pares en `sorted` respetando el orden del primer elemento
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::pair<int, int> key = pairs[i];
		size_t j = i;

		// Desplazar elementos mayores (comparando solo el primer elemento de cada par) hacia la derecha
		while (j > 0 && sorted[j - 1].first > key.first) {
			if (j < sorted.size()) {
				sorted[j] = sorted[j - 1];
			} else {
				sorted.push_back(sorted[j - 1]);
			}
			--j;
		}
		if (j < sorted.size()) {
			sorted[j] = key;
		} else {
			sorted.push_back(key);
		}
	}
	pairs = sorted;
}

// Función para encontrar la posición de inserción de un valor en un rango específico de un vector ordenado
int Pmerge::findInsertIndexVector(const std::vector<int>& vec, int val, int min, int max) {
	while (min < max) {
		int mid = min + (max - min) / 2;  
		
		if (vec[mid] < val) {
			min = mid + 1;
		} else {
			max = mid;
		}
	}
	return min;
}

// Llena `pairs` con pares de elementos de `vec`, colocando el mayor como primer elemento de cada par
void Pmerge::createPairs(const std::vector<int>& vec, std::vector<std::pair<int, int> >& pairs) {
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		int first = *it;
		++it;
		int second = *it;

		if (first < second) {
			pairs.push_back(std::make_pair(second, first));
		} else {
			pairs.push_back(std::make_pair(first, second));
		}
	}
}

// Inserta `lastValue` en `aux` si `lastValue` es diferente de -1
void Pmerge::insertLastValueIfPresent(std::vector<int>& aux, int lastValue) {
	if (lastValue != -1) {
		int index = findInsertIndexVector(aux, lastValue, 0, aux.size() - 1);
		std::vector<int>::iterator it2 = aux.begin();
		std::advance(it2, index);
		aux.insert(it2, lastValue);
	}
}

// Función principal para ordenar el vector usando pares
std::vector<int> Pmerge::sortVector(std::vector<int>& vec) {
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> aux;

	// Si está ordenado sale
	if (checkSortedVector(vec))
		return vec;

	// Extrae el último valor si tiene un número impar de elementos
	int lastValue = extractLastIfOdd(vec);

	// Crear pares con los elementos
	createPairs(vec, pairs);

	// Ordena los mayores con insertion
	pairInsertionSort(pairs);

	// Añadir todos los primeros elementos (los mayores) al vector
	for (std::vector<std::pair<int, int> >::iterator pair = pairs.begin(); pair != pairs.end(); ++pair) {
		aux.push_back(pair->first);
	}
	
	// Insertar los segundos elementos de cada par en la posición correspondiente
	for (std::vector<std::pair<int, int> >::iterator pair = pairs.begin(); pair != pairs.end(); ++pair) {
		int index = findInsertIndexVector(aux, pair->second, 0, aux.size() - 1);
		std::vector<int>::iterator it2 = aux.begin();
		std::advance(it2, index);
		aux.insert(it2, pair->second);
	}

	// Insertar `lastValue` en `aux` si es necesario
	insertLastValueIfPresent(aux, lastValue);
	return aux;
}
