#pragma once
#include <iostream>
#include <string>
class Human
{
public:
	std::string name;
	int age;

	Human(std::string name, int age);
	void set_name(std::string name);
	void set_age(int age);
	std::string get_name() const;
	int get_age()const;
};

