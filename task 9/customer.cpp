#include "customer.h"

Customer::Customer(std::string name, int age, int cash_amount, int card_amount): Human{name, age}, cash_amount{cash_amount}, card_amount{card_amount}
{}

void Customer::set_name(std::string name)
{
	this->name = name;
}

void Customer::set_age(int age) {
	this->age = age;
}


void Customer::set_cash_amount(int cash_amount) {
	this->cash_amount = cash_amount;
}
void Customer::set_card_amount(int card_amount) {
	this->card_amount = card_amount;
}

std::string Customer::get_name() const {
	return name;
}
int Customer::get_age() const {
	return age;
}
int Customer::get_cash_amount() const {
	return cash_amount;
}
int Customer::get_card_amount() const {
	return card_amount;
}

std::string Customer::to_string()const {
	std::string result = "Name: " + name + ", Age: " + std::to_string(age) + ", Cash amount: " + std::to_string(cash_amount) + ", Card amount: " + std::to_string(card_amount); 
	return result;
}

bool Customer::enough_money(int price) {
	if (cash_amount > price || card_amount > price) {
		std::cout << "You can buy this"<<std::endl;
		return true;
	}
	else {
		std::cout << "You can not buy this" << std::endl;
		return false;
	}

}
bool Customer::enough_age(int price) {
	if ((cash_amount > price || card_amount > price) && age>18){
		std::cout << "You can buy this" << std::endl;
	return true;
}
	else {
		std::cout << "You can not buy this" << std::endl;
		return false;
	}

}
int Customer::all_money() {
	int summary = cash_amount + card_amount;
	return summary;
}
