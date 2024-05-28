#include <iostream>
#include <string>

int main() {


	//task 3_1
	//The user types text into the console until they enter an empty string. Display everything that the user enters, but twice.
	/*
	std::string line = " ";
	while (line != "") {
		std::cout << "Write something and recieve echo: \n";
		std::getline(std::cin, line);
		std::cout << line << '\n' << line<<'\n';
	}
	*/

	//task 3_2
	//The number n is entered into the console. Output the message “Hello, world!” to the console n times
	/*
	std::string message = "Hello world!\n";
	int n = 0;
	std::cout << "Enter a number\n";
	std::cin >> n;
	for(int i = 0; i < n; i++) 
	{
		std::cout << message;
	}
	*/

	//task 3_3
	//The number n is entered into the console. Output all numbers from 1 to n inclusively to the console.
	/*
	int n = 0;
	std::cout << "Enter a number\n";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		std::cout << i<<" ";
	}
	*/
	
	//task 3_4
	//A positive integer is entered into the console. Output all even numbers from 1 to this number (inclusive).
	/*
	int n = 0;
	std::cout << "Enter a number\n";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{ if (i%2==0)
		std::cout << i << " ";
	
	}
	*/

	//task 3_5
	//A positive integer 'n' is entered into the console. Output the given number n times to the console.
	/*
	int n = 0;
	std::cout << "Enter a number\n";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cout << n << " ";
	
	}
	*/

	//task 3_6
	//Enter two positive integers 'width' and 'height' into the console. Output a rectangle with given width and height to the console.
	/*
	int width, height;
	std::cout << "Enter a width and height\n";
	std::cin >> width>> height;
	for (int i = 1; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			std::cout << "#";
		}
		std::cout << "#"<<"\n";
	
	}
	*/

	//task 3_7
	//An integer n is entered into the console and then n integers are entered. Output the largest number that was entered (not including n).
	/*
	int n, number;
	int max_number = 0;
	std::cout << "Enter a number of cycles\n";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter a number" << '(' << n - i << " left)\n";
		std::cin >> number;
		if (number > max_number)
			max_number = number;
	}
	std::cout <<"Max number: " << max_number;
	*/


	//task 3_8
	// An integer n is entered into the console. Output to the console all numbers from 1 to n, except for those numbers that are evenly divisible by 3. If a number is encountered that is evenly divisible by 13, exit the loop.

	int n = 0;
	std::cout << "Enter a number\n";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0) {
			continue;
		}
		if (i % 13 == 0) {
			break;
		}
		std::cout << i << " ";
			
	}
	return 0;
}