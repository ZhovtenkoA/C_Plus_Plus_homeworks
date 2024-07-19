#include <iostream>


template<typename Value>
class Node {
public:
	Value value;
	Node* next = nullptr; 
};



template<typename Value>
class Queue {
private:
	Node<Value>* head =nullptr, * tail = nullptr;
	
public:
	void append(const Value& value);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, const Queue<T>& que);



};















int main() {

	Queue<int> que;
	que.append(1);
	que.append(121);
	que.append(1123);
	std::cout << que;














	return 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& que)
{		
	for (Node<T> *node = que.head; node; node = node->next) {
		out << node->value<< " ";
	}
	return out;
	
}

template<typename Value>
void Queue<Value>::append(const Value& value)
{
	Node<Value>* node = new Node<Value>{value};
	if (!head) {
		head = node;
		tail = node;
		return;
	}

	tail->next = node;
	tail = node;
}
