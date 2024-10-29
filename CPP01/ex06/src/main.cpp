#include "../inc/Harl.hpp"

int main(int argc, char **argv) {
	Harl makeHarl;

	if (argc != 2){
		std::cerr << "[ " << INVALID << " ]" << std::endl;
		return (1);
	}
	makeHarl.complain(std::string(argv[1]));
	return (0);
}
