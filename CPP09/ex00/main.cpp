#include "BitcoinExchange.hpp"

int fk_space(std::string str, int i, int size, int csv) {
	while((i < size) && ((str[i] == 32) || (str[i] == csv)))
		i++;
	return i;
}

void ft_parser_data(std::string str, int csv, std::string &first, std::string &second) {
	int size = str.size();
	int i = 0, start;

	i = fk_space(str, i, size, csv);
	start = i;
	while (i < size && str[i] != ' ' && str[i] != csv)
		i++;
	first = str.substr(start, i - start);
	
	i = fk_space(str, i, size, csv);
	second = str.substr(i);
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		std::cerr << "Error: cannot open data file" << std::endl;
		return 1; 
	}
	std::ifstream	fd1("./data.csv");
	std::ifstream	fd2(argv[1]);
	if(!fd1.is_open() || !fd2.is_open()) {
		std::cerr << "Error: cannot open data file" << std::endl;
		return 1;
	}
	std::string str;
	std::map<Bitcoin::Date, Bitcoin> BddMap;
	std::string dateStr, valueStr;
	std::getline(fd1, str);
	while (std::getline(fd1, str)) {
		ft_parser_data(str, ',', dateStr, valueStr);
		try {
			Bitcoin::Date fecha1(dateStr);
			Bitcoin coin1(valueStr, 0);
			BddMap.insert(std::make_pair(fecha1, coin1));
		}
		catch (const Bitcoin::Date::ExceptionInvalidDate& e) {
			std::cout << e.what() << " => " << dateStr << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	fd1.close();

	std::getline(fd2, str);
	while (std::getline(fd2, str)) {
		ft_parser_data(str, '|', dateStr, valueStr);
		try {
			Bitcoin::Date fecha2(dateStr);
			Bitcoin coin2(valueStr, 1);
			std::map<Bitcoin::Date, Bitcoin>::iterator it = BddMap.lower_bound(fecha2);
			std::cout << fecha2 << " => " << coin2 << " = " << 
			(it->second.getBitcoin() * coin2.getBitcoin()) << std::endl;
		}
		catch (const Bitcoin::Date::ExceptionInvalidDate& e) {
			std::cout << e.what() << " => " << dateStr << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	fd2.close();
	return 0;
}
