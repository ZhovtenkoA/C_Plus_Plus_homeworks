#include <iostream>

int main() {

	float real_number;
	std::cout << "Enter a real number: ";
	std::cin >> real_number;
	std::cout << "ceil: " << ceil(real_number) << "\n"
		<< "floor: " << floor(real_number) << "\n"
		<< "integer: " << (int)real_number;



	return 0;
}