#include <iostream>
#include <fstream>
#include <string>




int main() {
	/*
		std::ofstream file;

	file.open("filename");

	file << "Hello file";
	
	*/
	/*
		std::ifstream file;
	file.open("filename");
	if (!file.is_open()) {
		std::cout << "File not found\n";
		return 1;
	}

	std::string str;
	std::getline(file, str);

	std::cout << str;
	*/
	std::ifstream file;

	std::string filename;

	std::cout << "Enter file name";
	std::cin >> filename;


	file.open(filename);

	if (!file.is_open()) {
		std::cout << "File not found\n";
		return 1;
	}
	std::string str;
	std::getline(file, str);

	file.close();



	std::ofstream file2;

	file2.open(filename + "new");
	file2 << str;


	file2.close();





	return 0;
}