#include <iostream>

int main() {
	//task4_1
	//The size of the size array is entered into the console. Create an array of the given size and write zeros in it. Output the array to the console.
	/*
	const int MAX_SIZE = 100;
	int size;
	std::cout << "Enter a size of array: " << std::endl;
	std::cin >> size;
	if (size > MAX_SIZE) {
		std::cerr << "Size too big\n";
		return 1;
	}
	int arr[MAX_SIZE] = {};
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	
	*/

	//task4_2
	//The size of the size array is entered into the console. Create an array of the given size and write elements from 1 to size inclusive in it. Output the array to the console.
	/*
	const int MAX_SIZE = 100;
	int size;
	std::cout << "Enter a size of array: " << std::endl;
	std::cin >> size;
	if (size > MAX_SIZE) {
		std::cerr << "Size too big\n";
		return 1;
	}
	int arr[MAX_SIZE];
	for (int i = 1; i <= size; i++) {
		arr[i] = i;
		std::cout << arr[i] << " ";
	}
	
	*/

	//task4_3
	//The user enters the size of the array into the console, and then each element of the array. Create and output to the console a new array with elements twice as large as in the entered array.
	/*
	const int MAX_SIZE = 100;
	int size;
	std::cout << "Enter a size of array: " << std::endl;
	std::cin >> size;
	if (size > MAX_SIZE) {
		std::cerr << "Size too big\n";
		return 1;
	}
	int arr[MAX_SIZE];
	std::cout << "Enter array: ";
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
	std::cout << "Your array: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] * 2 << " ";
	}
	std::cout << std::endl;
	*/

	//task4_4
	//The user enters the size of the first array into the console, and then each element of the first array. Similarly, the second array is entered. Output to the console the pairwise sum of the elements of two arrays (that is, another array, the first element of which is the sum of the first element from the first and second arrays), if their size is the same, or output a longer array in another case.
	
	const int MAX_SIZE = 100;
	int size1, size2;
	std::cout << "Enter a size of array1 and array 2: " << std::endl;
	std::cin >> size1>>size2;
	if (size1 > MAX_SIZE || size2> MAX_SIZE) {
		std::cerr << "Size too big\n";
		return 1;
	}
	int arr1[MAX_SIZE];
	int arr2[MAX_SIZE];

	std::cout << "Enter array1: ";
	for (int i = 0; i < size1; i++) {
		std::cin >> arr1[i];
	}
	std::cout << "Enter array2: ";
	for (int i = 0; i < size2; i++) {
		std::cin >> arr2[i];
	}

	std::cout << "Biggest array: ";
	if (size1 > size2) {
		for (int i = 0; i < size1; i++) {
			std::cout << arr1[i] << " ";
		}
		std::cout << std::endl;
	}
	else if (size1 < size2) {
		for (int i = 0; i < size2; i++) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;
	}

	else {
		std::cout << "Sum of arrays: ";
		for (int i = 0; i < size1; i++) {

			std::cout << arr1[i] + arr2[i] << " ";
		}
		std::cout <<std::endl;

	}

	

	std::cout << "Your array1: ";
	for (int i = 0; i < size1; i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Your array2: ";
	for (int i = 0; i < size2; i++) {
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;
	
	

	//task4_5
	//The size of the array is entered from the console. Create an array of the given size with random elements and output it to the console.
	/*
	srand(time(0));
	const int MAX_SIZE = 100;
	int size;
	std::cout << "Enter a size of array: " << std::endl;
	std::cin >> size;
	if (size > MAX_SIZE) {
		std::cerr << "Size too big\n";
		return 1;
	}
	int arr[MAX_SIZE];

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 90 + 10;
	}
	std::cout << "Your array: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	*/
	/*/
		srand(time(0));
	const int MAX_SIZE = 100;
	int lines, columns;
	int matrix[MAX_SIZE][MAX_SIZE];
	std::cout << "Enter matrix lines and columns: ";
	std::cin >> lines >> columns;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			//std::cin >> matrix[i][j];
			matrix[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/


	return 0;
}