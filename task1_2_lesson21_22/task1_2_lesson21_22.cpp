#include <iostream>
#include <vector>
#include <sstream>
#include <string>



//task 1_1
template<typename T>
T arraySum(const T* arr, int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}


//task 1_2
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& element : vec) {
        os << element << " ";
    }
    return os;
}


//task 1_3 stack + 2_1
template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    void push(const T& item) {
        data.push_back(item);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    T& top() {
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    typename std::vector<T>::iterator begin() {
        return data.begin();
    }

    typename std::vector<T>::iterator end() {
        return data.end();
    }

    typename std::vector<T>::const_iterator cbegin() const {
        return data.cbegin();
    }

    typename std::vector<T>::const_iterator cend() const {
        return data.cend();
    }
};



//task 1_4 pair
template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(const T1& firstValue, const T2& secondValue) : first(firstValue), second(secondValue) {}

    std::string toString() const {
        std::ostringstream oss;
        oss << "(" << first << ", " << second << ")";
        return oss.str();
    }
};

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const Pair<T1, T2>& pair) {
    os << pair.toString();
    return os;
}





//task 2_2
template <typename T>
class Array {
private:
    T* container;
    size_t size;

public:
    Array(size_t arraySize) : size(arraySize) {
        container = new T[size];
    }

    Array(const std::initializer_list<T>& elements) : size(elements.size()) {
        container = new T[size];
        std::copy(elements.begin(), elements.end(), container);
    }

    ~Array() {
        delete[] container;
    }

    T& operator[](size_t index) {
        return container[index];
    }

    const T& operator[](size_t index) const {
        return container[index];
    }

    bool operator==(const Array<T>& other) const {
        if (size != other.size)
            return false;

        for (size_t i = 0; i < size; ++i)
            if (container[i] != other.container[i])
                return false;

            return true;
    }

    bool operator!=(const Array<T>& other) const {
        return !(*this == other);
    }

    Array<T> operator+(const Array<T>& other) const {
        Array<T> result(size + other.size);

        std::copy(container, container + size, result.container);
        std::copy(other.container, other.container + other.size, result.container + size);

        return result;
    }

    T* begin() {
        return container;
    }

    T* end() {
        return container + size;
    }

    const T* begin() const {
        return container;
    }

    const T* end() const {
        return container + size;
    }
};








int main() {
    /*
     
    //task 1_1
    int intArr[] = { 1, 2, 3, 4, 5 };
    double doubleArr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    int intSum = arraySum(intArr, 5);
    double doubleSum = arraySum(doubleArr, 5);

    std::cout << "Sum of integers: " << intSum << std::endl;
    std::cout << "Sum of doubles: " << doubleSum << std::endl;
    */

    //task 1_2
    /*
    std::vector<int> intVec = { 1, 2, 3, 4, 5 };
    std::vector<double> doubleVec = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    std::cout << "Int vector: " << intVec << std::endl;
    std::cout << "Double vector: " << doubleVec << std::endl;
    */




    //task 1_3 stack
    /*
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Stack size: " << intStack.size() << std::endl;
    std::cout << "Top element: " << intStack.top() << std::endl;

    intStack.pop();
    std::cout << "Stack size after pop: " << intStack.size() << std::endl;

    intStack.clear();
    std::cout << "Stack size after clear: " << intStack.size() << std::endl;
    std::cout << "Is stack empty? " << (intStack.empty() ? "Yes" : "No") << std::endl;
    */




    //task 1_4 pair

    /*

    Pair<int, double> pair1(1, 2.2);
    Pair<std::string, char> pair2("Hello", 'A');

    std::cout << pair1 << std::endl;
    std::cout << pair2 << std::endl;
    */

    
    //task 2_1
    /*
    
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Using a regular iterator: ";
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Using a const iterator: ";
    for (auto it = stack.cbegin(); it != stack.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    */

    //task 2_2


    Array<int> arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    // Проходження всіма елементами масиву за допомогою звичайного ітератора
    std::cout << "Using a regular iterator: ";
    for (auto it = arr1.begin(); it != arr1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Проходження всіма елементами масиву за допомогою константного ітератора
    std::cout << "Using a const iterator: ";
    for (auto it = arr1.begin(); it != arr1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    Array<int> arr2({ 4, 5, 6 });

    // Об'єднання двох масивів
    Array<int> arr3 = arr1 + arr2;

    std::cout << "Combined array: ";
    for (auto it = arr3.begin(); it != arr3.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Порівняння двох масивів
    std::cout << "Arrays are ";
    if (arr1 == arr2) {
        std::cout << "equal";
    }
    else {
        std::cout << "not equal";
    }
    std::cout << std::endl;



    return 0;
}