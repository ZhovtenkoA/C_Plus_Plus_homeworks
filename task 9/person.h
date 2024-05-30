#pragma once
#include <iostream>
#include <string>
#include "human.h"
class Person : public Human
{

public:
	Person(std::string name, int age);
	void set_name(std::string name);
	void set_age(int age);
	std::string get_name() const;
	int get_age()const;

	std::string to_string()const;

};

