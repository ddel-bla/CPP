#include "../inc/easyfind.hpp"

int main() {
	std::vector<int> vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	std::cout << "Vector:" << std::endl;
	std::cout << "Distance from the start: " << easyfind(vector, 2) << std::endl;

	std::list<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	std::cout << "List:" << std::endl;
	std::cout << "Distance from the start: " << easyfind(list, 30) << std::endl;

    std::string text = "Hello, world!";
    std::cout << "Distance from the start: " << easyfind(text, 'w') << std::endl;

	std::cout << "Error:" << std::endl;
	std::cout << easyfind(vector, 8) << std::endl;
	std::cout << easyfind(list, -30) << std::endl;
	std::cout << easyfind(text, 'x') << std::endl;
	return 0;
}