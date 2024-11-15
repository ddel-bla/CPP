#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <climits>
#include <stdexcept>
#include <cstdlib>

class Pmerge {
public:
	Pmerge() {}
	Pmerge(const Pmerge&) {}
	~Pmerge() {}
	Pmerge &operator=(const Pmerge&) { return *this; }

	static std::vector<int> sortVector(std::vector<int>& vec);
	static std::list<int> sortList(std::list<int>& lst);

	static void printVector(const std::vector<int>& vec);
	static void printList(const std::list<int>& lst);

private:
	// Funciones para vectores
	static bool checkSortedVector(const std::vector<int>& vec);
	static int findInsertIndexVector(const std::vector<int>& vec, int val, int min, int max);
	static void pairInsertionSort(std::vector<std::pair<int, int> >& pairs);
	static void createPairs(const std::vector<int>& vec, std::vector<std::pair<int, int> >& pairs);
	static int extractLastIfOdd(std::vector<int>& vec);
	static void insertLastValueIfPresent(std::vector<int>& aux, int lastValue);

	// Funciones para listas
	static bool checkSortedList(const std::list<int>& lst);
	static std::list<int>::iterator findInsertIndexList(std::list<int>& lst, int val);
	static void pairInsertionSortList(std::list<std::pair<int, int> >& pairs);
	static void createPairsList(const std::list<int>& lst, std::list<std::pair<int, int> >& pairs);
	static int extractLastIfOdd(std::list<int>& lst);
	static void insertLastValueIfPresent(std::list<int>& aux, int lastValue);
};

#endif
