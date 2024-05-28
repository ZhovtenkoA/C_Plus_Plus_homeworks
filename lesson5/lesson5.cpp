#include <iostream>
#include <fstream>
#include <string>

int main() {

	/*
		int integer = 10;
	double d;
	std::cout << &integer << '\n' << &d<<'\n';
	int* pointer_int = &integer;
	double* pointer_d = &d;
	std::cout << pointer_int << '\n' << pointer_d<<'\n';
	int** pointer2 = &pointer_int;
	std::cout << **pointer2 << '\n';
	*/


	/*
	* 	std::ofstream file;
	file.open("file.txt");
	file << "hello w!";

	file.close();
	*/

	std::ifstream file;

	file.open("file.txt");
	if (file.is_open()) {
		std::string text;
		int number = 10;
		bool value = true;

		std::getline(file, text);
		file >> number >> value;


		file.close();
	}
	else {
		std::cout << "File not found";
	}









	return 0;
}