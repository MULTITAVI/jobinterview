#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void check_rule(std::basic_string<char> &str);

int main() {

	std::vector<std::basic_string<char>> str_arr;

	std::cout << "Enter your text:\n\nEnter . to complete typing:\n\n";

	for (std::basic_string<char> line; std::getline(std::cin, line, '.'); ) {
		if (line == "\n")
			break;

		str_arr.push_back(line);
		//std::cout << std::endl << line << std::endl;
	}

	std::for_each(str_arr.begin(), str_arr.end(), check_rule);

	std::cout << "Fixed one" << std::endl << std::endl;

	std::for_each(str_arr.begin(), str_arr.end(), [](const std::basic_string<char> line) {std::cout << line; });

	std::cout << std::endl << std::endl << "The longest sentence:" << std::endl << std::endl;
	std::cout << *std::max_element(str_arr.begin(), str_arr.end());

	return 0;
}

void check_rule(std::basic_string<char> &str) {
	if (str.front() != ' ')
		str.insert(0, " ");

	str.insert(str.end(), '.');
}