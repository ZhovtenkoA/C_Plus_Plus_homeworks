#pragma once
#include <iostream>
#include <string>
#include "human.h"

class  Customer : public Human
{
	int cash_amount;
	int card_amount;

public:

	Customer(std::string name, int age, int cash_amount, int card_amount);

	void set_name(std::string name);
	void set_age(int age);
	void set_cash_amount(int cash_amount);
	void set_card_amount(int card_amount);

	std::string get_name() const;
	int get_age()const;
	int get_cash_amount()const;
	int get_card_amount()const;

	std::string to_string()const;

	bool enough_money(int price);
	bool enough_age(int price);
	int all_money();


};

