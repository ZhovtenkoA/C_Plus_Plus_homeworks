#include <iostream>

int main() {


	const int MAX_SIZE = 100;
	int array[MAX_SIZE];
	int size;
	srand(time(0));

	std::cout << "Enter size of array: ";
	std::cin >> size;
	if (size > MAX_SIZE) {
		std::cerr << "Incorrect size ";
		return 1;
	}
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
		std::cout << array[i] << " ";

	}

	long long mul = 1;

	for (int i = 0; i < size; i++) {
		mul *= array[i];
		
	}
	std::cout << "\nMul: " << mul;



	




	return 0;
}