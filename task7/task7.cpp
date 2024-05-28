#include <iostream>
#include <string>

//task7_1
//Create a function (method) that will accept an integer and return half of it.

int half_integer(int number) {
    int new_number;
    new_number = number / 2;
    std::cout << "integer: " << number << std::endl;
    std::cout << "half_integer: " << new_number << std::endl;
    return new_number;
}

//task7_2
//Create a function that will output the message "Hello, c++!" to the console

void helo_c() {
    std::cout << "Hello, c++!"<< std::endl;
}

//task7_3
//Create a function that will accept the username and output a greeting to the console.

void hello_username() {
    std::string username;
    std::cout << "Enter your name: " << std::endl;
    std::cin >> username;
    std::cout << "Hello " << username << std::endl;
}


//task7_4
//Create a function that will accept two numbers and return the maximum.

int return_maximal(int number1, int number2) {
    if (number1 > number2) {
        std::cout << number1 << std::endl;
        return number1;
    }
    else if (number1 < number2) {
        std::cout << number2 << std::endl;
        return number2;
    }
}

//task7_5
//Create functions for input and output of the array from the console. Also create a function that will output the array in reverse order.

void my_array(int array[], int size) {
    std::cout << "Enter array elements:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    std::cout << "My array: ";
    for (int i = 0; i < size; i++) {
        std::cout<< array[i]<<" ";
    }
}
void reverse_array(int array[], int size) {
    std::cout << "Enter array elements:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    std::cout << "My reverse array: ";
    for (int i = size-1; i >= 0; i--) {
        std::cout << array[i] << " ";
    }
}


//task7_6
//Create a function that will return the minimum element of the array.

int min_element(int array[], int size) {
    std::cout << "Enter array elements:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    int min = array[0];
    std::cout << "Min value of array: ";
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    std::cout << min << " ";
    return min;
}

//task7_7
//Create two functions with the same name. The first will accept an integer and return true if the number is even. The second function will take a string and return true if the length of this string is an even number.

int is_even(int number) {
    if (number % 2 == 0) {
        std::cout << "True";
        return true;
    }
}

bool is_even(std::string& str) {
    if (str.length() % 2 == 0) {
        std::cout << "True";
        return true;
    }
}

//task7_8
//

void doubleByReference(int& number) {
    number *= 2;
}

void doubleByPointer(int* pointer) {
    *pointer *= 2;
}



//task7_9
//

void sum_mul(int number1, int number2, int& sum, int& mul) {
    sum = number1 + number2;
    mul = number1 * number2;
}


//task7_10 structures
//

struct Person {
    std::string name;
    int age;
    float height;
};

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



//task7_11 structures
//
struct Car {
    double fuelAmount;      // Amount of fuel in liters
    double fuelConsumption; // Fuel consumption in liters per 100 km
};

bool canReachDestination(const Car& car, double distance) {
    double fuelRequired = (car.fuelConsumption / 100.0) * distance;
    return car.fuelAmount >= fuelRequired;
}

    int main() {
        //half_integer(10);
        //helo_c();
        //hello_username();
        //return_maximal(100, 200);
        /*
        std::cout << "Enter the size of the array: ";
        int size;
        std::cin >> size;
        int* array = new int[size];

        //my_array(array, size);
        reverse_array(array, size);
        delete[] array;
        */

        /*
        std::cout << "Enter the size of the array: ";
        int size;
        std::cin >> size;
        int* array = new int[size];
        //my_array(array, size);
        min_element(array, size);
        delete[] array;
        */
        /*
        is_even(2);
        std::string str = "nam";
        is_even(str);
        */
        /*
        int sum = 10;
        int mul = 10;
        sum_mul(2, 2, sum, mul);
        std::cout << "Sum^ " << sum << '\n' << "Mul: " << mul;
        */
        /*
        int number = 10;
        int& number2 = number;
        func(number2);
        */
        /*
        Person person;

        std::cout << "Enter name: ";
        write_name(person);

        std::cout << "Enter age: ";
        write_age(person);

        std::cout << "Enter height: ";
        write_height(person);

        std::cout << "Person details:" << std::endl;
        read_name(person);
        read_age(person);
        read_height(person);
        */
        /*
        Car myCar;

        std::cout << "Enter the amount of fuel in the car (in liters): ";
        std::cin >> myCar.fuelAmount;
        std::cout << "Enter the fuel consumption of the car (in liters per 100 km): ";
        std::cin >> myCar.fuelConsumption;

        double distance;
        std::cout << "Enter the distance to travel (in km): ";
        std::cin >> distance;

        if (canReachDestination(myCar, distance)) {
            std::cout << "The car can reach the destination." << std::endl;
        }
        else {
            std::cout << "The car cannot reach the destination." << std::endl;
        }
        */


        int number = 5;
        std::cout << "Initial value: " << number << std::endl;

        // Double the value using the function that takes a reference
        doubleByReference(number);
        std::cout << "After doubleByReference: " << number << std::endl;

        // Double the value using the function that takes a pointer
        doubleByPointer(&number);
        std::cout << "After doubleByPointer: " << number << std::endl;

    return 0;
}