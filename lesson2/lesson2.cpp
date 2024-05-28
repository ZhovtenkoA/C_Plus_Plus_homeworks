#include <iostream>

int main() {


	int number;
	std::cout << "Enter a number of animal: 1.Cat, 2.Dog, 3.Cow: ";
	std::cin >> number;

	switch (number) {

	case 1: { std::cout << "Cat says meow!"; }
		  break;
	case 2: { std::cout << "Dog says bark!"; }
		  break;
	case 3: { std::cout << "Cow says moo!"; }
		  break;

	default: 
		  { std::cout << "incorrect animal"; }

	}


	return 0;
}
