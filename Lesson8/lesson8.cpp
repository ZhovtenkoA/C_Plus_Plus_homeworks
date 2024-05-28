#include <iostream>
#include <string>
#include <Windows.h>



class Contacts {
public:
	std::string* contacts_list;
	int size;
	int index = 0;
	Contacts(int size) {
		this->size = size;
		contacts_list = new std::string[size];
	}

	void add_contact(std::string number) {
		contacts_list[index] = number;
		index++;


	}

	void view_contacts() {

		for (int i = 0; i < index; i++)
			std::cout <<"Contact" << i<<": " << contacts_list[i] << "\n";
	}

	~Contacts() {
		delete[] contacts_list;
	}
};







int main() {
	SetConsoleOutputCP(1251);
	/*
	Contacts contact(5);
	contact.add_contact("009999954");
	contact.add_contact("00988849954");
	contact.view_contacts();
	*/



}