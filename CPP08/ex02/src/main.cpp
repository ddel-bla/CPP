#include "../inc/MutantStack.hpp"

#define ELEMENT 42

void findAnElement() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(556);
	mstack.push(125);
	mstack.push(362);
	mstack.push(664);
	mstack.push(283);
	mstack.push(496);
	mstack.push(622);
	mstack.push(201);
	mstack.push(583);
	mstack.push(159);
	mstack.push(670);
	mstack.push(351);
	mstack.push(556);
	mstack.push(682);
	mstack.push(97);
	mstack.push(524);
	mstack.push(403);
	mstack.push(198);
	mstack.push(650);
	mstack.push(288);
	mstack.push(529);
	mstack.push(606);
	mstack.push(119);
	mstack.push(409);
	mstack.push(613);
	mstack.push(255);
	mstack.push(688);
	mstack.push(71);
	mstack.push(536);
	mstack.push(212);
	mstack.push(385);
	mstack.push(667);
	mstack.push(83);
	mstack.push(2);
	mstack.push(484);
	mstack.push(623);
	mstack.push(179);
	mstack.push(539);
	mstack.push(42);
	mstack.push(678);
	mstack.push(119);
	mstack.push(480);
	mstack.push(502);
	mstack.push(675);
	mstack.push(737);
	mstack.push(403);
	mstack.push(198);
	mstack.push(650);
	mstack.push(288);
	mstack.push(529);
	mstack.push(606);
	mstack.push(119);
	mstack.push(409);
	mstack.push(613);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "StackSize: " << mstack.size() << std::endl;
	std::cout << SEARCHING_FOR << ELEMENT << std::endl << std::endl;
	static int index = 0;
	for (; it != ite; it++) {
		std::cout << CHECKING_AT << index << std::endl;
		if (*it == ELEMENT) {
			std::cout << std::endl << ELEM << *it << FOUND_AT << index << std::endl << std::endl;
			break;
		}
		index++;
		std::cout << NO_MATCH_AT << index << std::endl << ITERATING << std::endl;
	}
	std::stack<int> s(mstack);
}

#include <list>

void subject_list() {
    std::list<int> mstack; // Usa std::list en lugar de MutantStack

    mstack.push_back(5); // Equivalente a push()
    mstack.push_back(17);
    std::cout << "StackTop: " << mstack.back() << std::endl; // Equivalente a top()
    mstack.pop_back(); // Equivalente a pop()
    std::cout << "StackSize: " << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

void subject() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "StackTop: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "StackSize: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int main(void) {
	findAnElement();
	//subject();
	//subject_list();

	return 0;
}