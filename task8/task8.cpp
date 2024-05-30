#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>


//task 8_1

class Person {
public:
    std::string name;
    int age;
    float height;


    Person() {
        std::cout << "Default\n";
    }
    Person(std::string name, int age, float height) {
        this->name = name;
        this->age = age;
        this->height = height;
    }

    std::string to_string() const {
        std::string result = "Name: " + name + ", age: " + std::to_string(age) + ", height: " + std::to_string(height);

        return result;
    }
    void write_name(Person& p) {
        std::cin >> p.name;
    }

    void write_age(Person& p) {
        std::cin >> p.age;
    }

    void write_height(Person& p) {
        std::cin >> p.height;
    }

    void read_name(Person& p) {
        std::cout << "Name: " << p.name << std::endl;
    }

    void read_age(Person& p) {
        std::cout << "Age: " << p.age << std::endl;
    }

    void read_height(Person& p) {
        std::cout << "Height: " << p.height << std::endl;
    }
};



class Car {
public:
    double fuelAmount;      
    double fuelConsumption; 

    bool canReachDestination(double fuelAmount, double distance) {
        double fuelRequired = (fuelConsumption / 100.0) * distance;
        return fuelAmount >= fuelRequired;
    }
};



//taks 8_2

class Array {
private:
    int* container;  
    int size;       
public:
    Array(int size) {
        this->size = size;
        container = new int[size]; 
    }

    ~Array() {
        delete[] container;  
    }

    void insert(int value, int index) {
        if (index < size) {
            container[index] = value;  
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << container[i] << " ";  
        }
        std::cout << std::endl;
    }
};


//task8_4

class RationalNumber {
public:
    int numerator;
    int denominator;

    RationalNumber() : numerator(0), denominator(1) {}

    RationalNumber(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    RationalNumber operator+(const RationalNumber& other) const {
        int resultNumerator = numerator * other.denominator + other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        return RationalNumber(resultNumerator, resultDenominator);
    }

    RationalNumber operator-(const RationalNumber& other) const {
        int resultNumerator = numerator * other.denominator - other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        return RationalNumber(resultNumerator, resultDenominator);
    }

    RationalNumber operator*(const RationalNumber& other) const {
        int resultNumerator = numerator * other.numerator;
        int resultDenominator = denominator * other.denominator;
        return RationalNumber(resultNumerator, resultDenominator);
    }

    RationalNumber operator/(const RationalNumber& other) const {
        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;
        return RationalNumber(resultNumerator, resultDenominator);
    }

    bool operator==(const RationalNumber& other) const {
        return numerator * other.denominator == denominator * other.numerator;
    }

    bool operator>(const RationalNumber& other) const {
        return numerator * other.denominator > denominator * other.numerator;
    }

    bool operator<(const RationalNumber& other) const {
        return numerator * other.denominator < denominator * other.numerator;
    }
};


std::ostream& operator<<(std::ostream& out, const RationalNumber& rational) {
    out << rational.numerator << "/" << rational.denominator;
    return out;
}







int main() {
	SetConsoleOutputCP(1251);
    /*
    Person person;
    std::cout << "Enter name: ";
    person.write_name(person);
    std::cout << "Enter age: ";
    person.write_age(person);
    std::cout << "Enter height: ";
    person.write_height(person);
    std::cout << "Person details:" << std::endl;
    person.read_name(person);
    person.read_age(person);
    person.read_height(person);
    std::cout<< person.to_string();
    */
    /*
    Car car;
    car.fuelAmount = 10;
    car.fuelConsumption = 2;

    std::cout<< car.canReachDestination(11, 50);
    */
    /*
    Array myArray(3);  

    myArray.insert(10, 0);  
    myArray.insert(20, 1);  
    myArray.insert(30, 2);  

    myArray.print();
    */
  
    RationalNumber r1(1, 2);
    RationalNumber r2(3, 4);

    std::cout << "r1: " << r1 << std::endl;
    std::cout << "r2: " << r2 << std::endl;

    RationalNumber sum = r1 + r2;
    std::cout << "Sum: " << sum << std::endl;

    RationalNumber difference = r1 - r2;
    std::cout << "Difference: " << difference << std::endl;

    RationalNumber product = r1 * r2;
    std::cout << "Product: " << product << std::endl;

    RationalNumber quotient = r1 / r2;
    std::cout << "Quotient: " << quotient << std::endl;

    bool isEqual = r1 == r2;
    std::cout << "Is r1 equal to r2? " << (isEqual ? "Yes" : "No") << std::endl;

    bool isGreater = r1 > r2;
    std::cout << "Is r1 greater than r2? " << (isGreater ? "Yes" : "No") << std::endl;

    bool isLess = r1 < r2;
    std::cout << "Is r1 less than r2? " << (isLess ? "Yes" : "No") << std::endl;



	return 0;
}
