template<class T>
class Stack
{
public:
    Stack();
    Stack(T capacity);
    ~Stack();
    T top();
    void push(T n);
    T pop();
    bool empty();
private:
    int _capacity = 32;
    T* _items = new T[32]{ 0 };
    int _top = -1;
};



template<class T>
Stack<T>::Stack() {}

template<class T>
Stack<T>::Stack(const T capacity) {
    if (capacity <= 0) {
        throw("capacity can't less than zero!");
    }
    this->_items = new T[capacity] {0};
    this->_capacity = capacity;
}

template<class T>
Stack<T>::~Stack() {}

template<class T>
T Stack<T>::top() {
    if (this->empty()) {
        throw("stack is empty!");
    }
    return this->_items[this->_top];
}

template<class T>
void Stack<T>::push(T n) {
    if (this->_top >= this->_capacity) {
        throw("stack is full");
    }
    this->_top++;
    this->_items[this->_top] = n;
}

template<class T>
T Stack<T>::pop() {
    if (this->empty()) {
        throw("stack is empty!");
    }
    T ret = this->_items[this->_top];
    this->_items[this->_top] = 0;
    this->_top--;
    return ret;
}

template<class T>
bool Stack<T>::empty() {
    return this->_top <= -1;
}
