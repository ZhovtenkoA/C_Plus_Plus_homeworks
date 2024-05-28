#include <iostream>
#include <string>

int main() {
	/*
	int number;

	std::cout << "Enter a number";
	std::cin >> number;
		for (int i = 1; i <= number; i += 1) {
		std::cout <<i << "^2=" << pow(i, 2) << "\n";
	}
	*/

	


	std::string command;
	while (true) {
		std::cout << "Enter a comand (star, point, coma, end): \n";
		std::getline(std::cin, command);
		if (command == "star")
			std::cout << "*\n";
		else if (command == "point")
			std::cout << ".\n";
		else if (command == "coma")
			std::cout << ",\n";
		else
			break;


	}







	return 0;
}