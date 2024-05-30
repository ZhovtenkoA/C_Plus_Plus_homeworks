#include "person.h"

Person::Person(std::string name, int age) :Human{name, age}
{}
int Person::get_age()const {
	return age;
}
std::string Person::get_name()const {
	return name;
}

void Person:: set_name(std::string name) {
	this->name = name;
}
void Person::set_age(int age) {
	this->age = age;
}

std::string Person::to_string() const{
	std::string result = "Name: " + name + " Age: " + std::to_string(age);
	return result;
}


