#include <iostream>

int main() {
	//task 5_1
	//Output to the console the addresses of the variables from task '1. Data types'.
	/*
	int age = 29;
	float price = 59.99;
	int a = 20, b = 10;

	std::cout << "age adress; " << &age << "\nPrice adress: " << &price << "\na adress: " <<
		&a << "\nb adress: " << &b;
	*/

	//task 5_2
	//Dynamically create an integer and output its address and value to the console.
	/*
	int number = 10;
	int* p = new int(10);
	std::cout << p << std::endl;
	std::cout << *p << std::endl;
	*/
	
	//task 5_3
	//The size of the size array is entered into the console. Dynamically create an array of the given size and write zeros into it. Traversal of the array should be implemented using indexes.
	/*
	int size;
	std::cout << "enter a size of array: ";
	std::cin >> size;
	int* array = new int[size] {};

	for (int i = 0; i < size; i++) {
		std::cout << array[i]<<' ';
	}
	*/

	//task 5_4
	//The user enters the size of the array into the console. Create an array of the given size with random elements. Display the addresses of all elements of the array in the console. Create the array dynamically. The traversal of the array should be implemented using the addresses of the array elements.
	/*
	srand(time(0));
	int size;
	std::cout << "enter a size of array: ";
	std::cin >> size;
	int* array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
		std::cout << &array[i] << '\n';
	}
	delete[] array;
	*/

	//task5_5
	//The user enters the size of the array into the console, and then each element of the array. Output to the console an array with elements twice as large as in the entered array. Create the array dynamically. The traversal of the array should be implemented using the addresses of the array elements.
	/*
	int size;
	std::cout << "enter a size of array: ";
	std::cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin>> *(array + i);
	}

	for (int i = 0; i < size; i++) {	
		std::cout << *(array + i) *2 << ' ';
	}

	delete[] array;
	*/

	//task 5_6
	//The user enters the size of the array into the console, and then each element of the array. Output the smallest element from the array and its address to the console. Create the array dynamically. The traversal of the array should be implemented using the addresses of the array elements.

	srand(time(0));
	int size;
	std::cout << "enter a size of array: ";
	std::cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin>> *(array + i);
	}
	int min= array[0];
	for (int i = 0; i < size; i++) {
		int min = array[i];
		if (array[i] < min) {
			min = array[i];
		}
		
	}
	std::cout <<"Min value: " << min<<"\nadress: "<<&min;
	delete[] array;
	
	return 0;
}