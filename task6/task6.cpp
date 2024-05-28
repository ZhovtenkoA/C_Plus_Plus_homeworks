#include <iostream>
#include <fstream>
#include <string>


int main() {
	//task6_1
	//The user enters two numbers 'x' and 'y'. Write the following expressions in the file:
	//x + y = res
	//x – y = res
	//x * y = res
	/*
	int x, y;
	std::cout << "Enter number x and y: ";
	std::cin >> x >> y;
	std::ofstream file;
	file.open("output.txt");
	file << x << "+" << y << "=" << x + y << "\n" <<
		x << "-" << y << "=" << x - y << "\n" <<
		x << "*" << y << "=" << x * y;
	std::cout << "Results were saved!";
	file.close();
	
	*/


	//task6_2
	//The user enters the name of the text file. If such a file exists, display the number of lines in this file, otherwise display a message that the file was not found.
	/*
	std::string filename;
	std::cout << "Enter filename: ";
	std::getline(std::cin, filename);
	std::ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		std::cout << "The file " << "'" << filename << "' was not found!";
		return 1;
	}
	std::string line;
	int counter = 0;
	while (std::getline(file, line)) {
		counter++;
	}
	std::cout << "There are "<< counter <<" lines!";
	file.close();
	*/

	//task6_3
	//Numbers are entered sequentially from two files. You need to write a sequence of sums of given numbers to the output file.
	/*
		std::ofstream inp1, inp2;
	inp1.open("input1.txt");
	inp1 <<1<< "\n"<<5<<"\n"<<8 << "\n"<<std::endl;
	inp1.close();

	inp2.open("input2.txt");
	inp2 << 15 << "\n" << 1 << "\n" << 5 << "\n" << std::endl;
	inp2.close();

	std::ifstream input1, input2;
	input1.open("input1.txt");
	input2.open("input2.txt");

	if (!input1.is_open() || !input2.is_open()) {
		std::cerr << "One of more file not found!\n";
		return 1;
	}
	std::ofstream output;
	output.open("output2.txt");

	std::string line1, line2;

	while (std::getline(input1, line1) && std::getline(input2, line2)) {
		int number1 = std::stoi(line1);
		int number2 = std::stoi(line2);
		output << number1 + number2 << "\n";
	}
	output.close();
	input1.close();
	input2.close();
	*/

	//task6_4
	//Write to a text file everything that the user enters into the console. For example, limit n rows. The message “Enter maximum number of lines: ” is displayed in the console.
	//The user enters a number and then the specified number of lines(words, sentences, numbers, characters.Be sure to press Enter after each entry).
	/*
		int number_of_lines;
	std::ofstream file;
	std::cout << "Enter maximum number of lines: ";
	std::cin >> number_of_lines;
	file.open("output3.txt");
	for (int i = 0; i <= number_of_lines; i++) {
		if (file.is_open()) {
			std::string line;
			std::getline(std::cin, line);
			file << line << "\n";
		}
	}
	std::cout << "Lines were saved";
	file.close();
	*/

	//task6_5
	//write in binary form the price and weight of the product entered by the user from the console, then read this information from the file and output it to the console

	float price, weight;
	std:: cout << "Enter price: ";
	std::cin >> price;
	std::cout << "Enter weight: ";
	std::cin >> weight;

	std::ofstream input_file("data.bin", std::ios::binary);
	input_file.write((char*)&price, sizeof(price));
	input_file.write((char*)&weight, sizeof(weight));
	input_file.close();

	std::ifstream output_file("data.bin", std::ios::binary);
	if (output_file.is_open()) {
		output_file.read((char*)&price, sizeof(price));
		output_file.read((char*)&weight, sizeof(weight));

		std::cout << "Price: " << price << std::endl;
		std::cout << "Weight: " << weight << std::endl;

		output_file.close();
	}
	else {
		std::cout << "File not found" << std::endl;
	}

	return 0;
}