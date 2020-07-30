#include <iostream>
#include <stack>
#include <exception>
using namespace std;

template <typename T>
class Queue
{
public:
    Queue(void);
    ~Queue(void);

    void appendTail(const T& val);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
Queue<T>::Queue()
{

}

template <typename T>
Queue<T>::~Queue()
{

}


template <typename T>
void Queue<T>::appendTail(const T& val)
{
    stack1.push(val);
}

template <typename T>
T Queue<T>::deleteHead()
{
    if (stack2.size() <= 0)
    {
        if (stack1.size() <= 0)
            throw exception("Queue is empty");

        while (stack1.size() > 0)
        {
            T top = stack1.top();
            stack2.push(top);
            stack1.pop();
        }
    }
    T top = stack2.top();
    stack2.pop();
    return top;
}

void assert(bool b)
{
    static int count = 0;
    if (b)
        cout << "assert passed " << ++count << endl;
    else
        throw exception("assert failed");
}

void test()
{
    Queue<int> queue;
    queue.appendTail(1);
    assert(queue.deleteHead() == 1);

    queue.appendTail(2);
    queue.appendTail(3);
    assert(queue.deleteHead() == 2);
    assert(queue.deleteHead() == 3);

    queue.appendTail(4);
    queue.appendTail(5);
    assert(queue.deleteHead() == 4);
    queue.appendTail(6);
    queue.appendTail(7);
    assert(queue.deleteHead() == 5);
    assert(queue.deleteHead() == 6);
    assert(queue.deleteHead() == 7);
}

int main()
{
    test();
    return 0;
}