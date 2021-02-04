#include <iostream>
#include <cassert>
using namespace std;

//=============================== 方法1: 递归  =========================
long Fibo1(unsigned int n)
{
    if (n <= 1)
        return n;
    return Fibo1(n - 1) + Fibo1(n - 2);
}

//=============================== 方法1: 循环  =========================
long Fibo2(unsigned int n)
{
    if (n <= 1)
        return n;

    int FiboOne = 0;
    int FiboTwo = 1;
    int FiboN = 0;

    for (size_t i = 2; i <= n; i++)
    {
        FiboN = FiboOne + FiboTwo;
        FiboOne = FiboTwo;
        FiboTwo = FiboN;
    }
    return FiboN;
}

void test1()
{
    assert(Fibo1(0) == 0);
    assert(Fibo1(1) == 1);
    assert(Fibo1(2) == 1);
    assert(Fibo1(3) == 2);
    assert(Fibo1(4) == 3);
    assert(Fibo1(5) == 5);
    assert(Fibo1(6) == 8);
    assert(Fibo1(7) == 13);
    assert(Fibo1(8) == 21);
    assert(Fibo1(9) == 34);
    assert(Fibo1(10) == 55);
}

void test2()
{
    assert(Fibo2(0) == 0);
    assert(Fibo2(1) == 1);
    assert(Fibo2(2) == 1);
    assert(Fibo2(3) == 2);
    assert(Fibo2(4) == 3);
    assert(Fibo2(5) == 5);
    assert(Fibo2(6) == 8);
    assert(Fibo2(7) == 13);
    assert(Fibo2(8) == 21);
    assert(Fibo2(9) == 34);
    assert(Fibo2(10) == 55);
    Fibo2(100);
}

int main(int argc, char const argv[])
{
    test1();
    test2();
    return 0;
}