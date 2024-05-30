#include "human.h"

Human::Human(std::string name, int age) : name{ name }, age{ age }
{}

void Human::set_name(std::string name)
{
	this->name = name;
}

void Human::set_age(int age) {
	this->age = age;
}

std::string Human::get_name() const {
	return name;
}
int Human::get_age() const {
	return age;
}