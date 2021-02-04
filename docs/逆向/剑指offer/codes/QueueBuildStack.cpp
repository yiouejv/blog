#include <iostream>
#include <queue>
#include <exception>
using namespace std;

template <typename T>
class Stack
{
public:
    Stack(void);
    ~Stack(void);

    T pop();
    void push(const T& value);
private:
    queue<T> queue1;
    queue<T> queue2;
};

template <typename T>
Stack<T>::Stack()
{

}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
void Stack<T>::push(const T& value)
{
    // 往元素多的队列里入队
    if (queue1.size() > queue2.size())
        queue1.push(value);
    else
        queue2.push(value);
}

template <typename T>
T Stack<T>::pop()
{
    // 元素多队列一直出队到元素少的队列里, 直到队列元素为1
    T v;
    if (queue1.size() > queue2.size())
    {
        while (queue1.size() > 1)
        {
            v = queue1.front();
            queue1.pop();
            queue2.push(v);
        }
        v = queue1.front();
        queue1.pop();
    }
    else
    {
        while (queue2.size() > 1)
        {
            v = queue2.front();
            queue2.pop();
            queue1.push(v);
        }
        v = queue2.front();
        queue2.pop();
    }
    return v;
}

void assert(bool b)
{
    static int i = 0;
    if (b)
    {
        cout << "assert passed " << ++i << endl;
    }
    else
        throw exception("assert failed");
}

void test()
{
    Stack<int> stack;
    stack.push(1);
    assert(stack.pop() == 1);

    stack.push(2);
    stack.push(3);
    assert(stack.pop() == 3);
    assert(stack.pop() == 2);

    stack.push(2);
    stack.push(3);
    assert(stack.pop() == 3);
    stack.push(4);
    assert(stack.pop() == 4);
    assert(stack.pop() == 2);
}

int main(int argc, char const argv[])
{
    test();
    return 0;
}