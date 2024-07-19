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
    Node<Value>* head = nullptr, * tail = nullptr;

public:
    void append(const Value& value);

    void Pop();

    template<typename T>
    friend std::ostream& operator<<(std::ostream& out, const Queue<T>& que);

    ~Queue();


    template<typename T>
    class Iterator : public std::iterator <std::input_iterator_tag, T> {

        Node<T>* node;
        Iterator(Node<T>*node);

    public:

        Iterator(const Iterator& it);

        bool operator != (const Iterator& it) const;
        T& operator * () const;
        Iterator& operator ++ ();

        friend Queue;


    };

    Iterator<Value> begin();
    Iterator<Value> end();
    Iterator<const Value> begin() const;
    Iterator<const Value> end() const;


};



template<typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& que)
{
    for (Node<T>* node = que.head; node; node = node->next) {
        out << node->value << " ";
    }
    return out;

}

template<typename Value>
void Queue<Value>::append(const Value& value)
{
    Node<Value>* node = new Node<Value>{ value };
    if (!head) {
        head = node;
        tail = node;
        return;
    }

    tail->next = node;
    tail = node;
}

template<typename Value>
void Queue<Value>::Pop()
{
    if (!head) return;


    Node<Value>* node = head;
    head = head->next;
    if (!head) tail = nullptr;
    delete node;
}

template<typename Value>
Queue<Value>::~Queue()
{

    tail = nullptr;
    while (head)
    {

        Node<Value>* temp = head;
        head = head->next;
        delete temp;


    }

}



template<typename Value>
Queue<Value>::Iterator<Value> Queue<Value>::begin()
{
    return Iterator<Value>(head);
}

template<typename Value>
Queue<Value>::Iterator<Value> Queue<Value>::end() {
    return Iterator<Value>(nullptr);
}


template<typename Value>
Queue<Value>::Iterator<const Value> Queue< Value>::begin() const {
    return Iterator< const Value>(head);
}

template<typename Value>
Queue<Value>::Iterator<const Value> Queue<Value>::end() const {
    return Iterator<const Value>(nullptr);
}


int main() {

    Queue<int> que;
    que.append(1);
    que.append(121);
    que.append(1123);
    
    for (int item : que) std::cout << item << " ";


    return 0;
}







template<typename Value>
template<typename T>
Queue<Value>::Iterator<T>::Iterator(Node<T>* node): node(node){}



template<typename Value>
template<typename T>
Queue<Value>::Iterator<T>::Iterator(const Iterator& it): node(it.node){}



template<typename Value>
template<typename T>
bool Queue<Value>::Iterator<T>::operator!=(const Iterator& it) const
{
    return node != it.node;
}


template<typename Value>
template<typename T>
T& Queue<Value>::Iterator<T>::operator*() const
{
    return node->value;
}




template<typename Value>
template<typename T>
Queue<Value>::Iterator<T>& Queue<Value>::Iterator<T>::operator++()
{
    node = node->next;
    return *this;
}


