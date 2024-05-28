#include <iostream>


void greetings(const std::string &name) {

	std::cout << "Hello " << name << "!";

}

void create_array(int* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << "\n";
	}

	

}

struct Book {
	std::string name;
	int price;
};




int main() {


	Book mybook{ "abc", 10 };
	std::cout << mybook.name << "  " << mybook.price;
	//greetings("Ivan");
	//int array[10];
	//create_array(array, 10);

	return 0;
}