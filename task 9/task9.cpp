#include <iostream>
#include <string>
#include <Windows.h>
#include "person.h"
#include "customer.h"

//task 9_1


class Flower {
private:
	std::string name;
	int cost;
	int number_of_leaves;
public:
	Flower(std::string name, int cost, int number_of_leaves) : name{ name }, cost{ cost }, number_of_leaves{ number_of_leaves } {};
	std::string get_name() const {
		return name;
	}
	int get_cost() const {
		return cost;
	}
	int get_number_of_leaves() const {
		return number_of_leaves;
	}

	void set_name(std::string name) {
		this->name = name;
	}
	void set_cost(int cost) {
		this->cost = cost;
	}
	void set_number_of_leaves(int number_of_leaves) {
		this->number_of_leaves = number_of_leaves;
	}

	bool count_leaves() {
		if (number_of_leaves > 4) return true;
		else return false;
	}

	std::string to_string()const {
		std::string result = "name: " + name + "cost: " + std::to_string(cost) + "Number of leaves: " + std::to_string(number_of_leaves);
		return result;
	}

	



};
std::ostream& operator<<(std::ostream& out, const Flower& flower) {
	out<<flower.to_string();

	return out;
}


//task 9_2 class Person

std::ostream& operator<<(std::ostream& out, const Person& person) {
	out << person.to_string();
	return out;
}

//task 9_2 class Customer

std::ostream& operator<<(std::ostream& out, const Customer& customer) {
	out << customer.to_string();
	return out;
}



int main() {
	SetConsoleOutputCP(1251);
	/*
	Flower flower1("Flower1", 50, 7);
	std::cout<<flower1.get_cost()<<'\n';
	flower1.set_cost(100);
	std::cout << flower1.get_cost()<<"\n"<<flower1.count_leaves()<<'\n';
	std::cout << flower1;
	*/
	/*
	Person person("Max", 39);
	person.set_age(99);
	std::cout << person.get_name() << "\n" << person.get_age()<<'\n';
	std::cout << person;
	*/
	
	Customer customer("Anna", 28, 1500, 3000);
	std::cout << customer<<std::endl;
	std::cout << customer.all_money() << std::endl;
	customer.set_card_amount(10000);
	std::cout << customer.enough_age(5000) << std::endl;
	std::cout << customer.enough_money(25000) << std::endl;
	std::cout << customer.all_money() << std::endl;
	

	return 0;
}