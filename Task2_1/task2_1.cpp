#include <iostream>
#include <cstdlib>

int main() {


	//task 1

	/*
	int age;
	std::cout << "Enter your age: \n";
	std::cin >> age;
	if (age >= 12)
		std::cout << "Access approved";
	else
		std::cout << "Access denied";
	*/
	

	//task 2


	/*
	int age, money;
	std::cout << "Enter your age and your money: \n";
	std::cin >> age >> money;
	if (age >= 18 && money >= 50)
		std::cout << "You can buy alcohol";
	else
		std::cout << "You can not buy alcohol";
	*/


	//task 3

	/*
	int cash, card;
	std::cout << "Enter your cash and your card balance: \n";
	std::cin >> cash >> card;
	if (cash >= 81 || card >= 81)
		std::cout << "You can buy something for 81$";
	else
		std::cout << "You can not buy something for 81$";
	*/


	//task 4

	/*
	int a, b, c;
	std::cout << "Enter dimensions of triangle: \n";
	std::cin >> a >> b >> c;

	if ((a + b) > c && (b + c) > a && (a + c) > b)
		std::cout << "It is triangle";
	else
		std::cout << "It is not triangle";
	*/


	//task 5

	/*
	int number;
	std::cout << "Enter a number: \n";
	std::cin >> number;
	if (number == 0)
		std::cout << "Number is zero";
	else if (number == abs(number))
		std::cout << "Number is positive";
	else
		std::cout << "Number is negative";
	
	*/


	//task 6

	/*
	int number;
	std::cout << "Enter a number of month: \n";
	std::cin >> number;
	switch (number) {
	case 1:
		std::cout << "This is January";
		break;
	case 2:
		std::cout << "This is February";
		break;
	case 3:
		std::cout << "This is March";
		break;
	case 4:
		std::cout << "This is April";
		break;
	case 5:
		std::cout << "This is May";
		break;
	case 6:
		std::cout << "This is June";
		break;
	case 7:
		std::cout << "This is July";
		break;
	case 8:
		std::cout << "This is August";
		break;
	case 9:
		std::cout << "This is September";
		break;
	case 10:
		std::cout << "This is October";
		break;
	case 11:
		std::cout << "This is November";
		break;
	case 12:
		std::cout << "This is December";
		break;
	default:
		std::cout << "Incorrect number";
	}
	*/
	

	//task 7
	
	int number;
	std::cout << "Enter a number: \n";
	std::cin >> number;
	switch (number) {
	case 1:
		std::cout << number << "-st";
		break;
	case 2:
		std::cout << number << "-nd";
		break;
	case 3:
		std::cout << number << "-rd";
		break;
	case 4:
		std::cout << number << "-th";
		break;
	case 5:
		std::cout << number << "-th";
		break;
	case 6:
		std::cout << number << "-th";
		break;
	case 7:
		std::cout << number << "-th";
		break;
	case 8:
		std::cout << number << "-th";
		break;
	case 9:
		std::cout << number << "-th";
		break;
	default:
		std::cout << "Incorrect number";
	}
	return 0;
		


}