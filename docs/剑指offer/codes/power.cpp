#include <iostream>
#include <cassert>
using namespace std;

double power(double base, int expoent)
{
    if (expoent == 0)
        return 1;

    bool flag = false;  // 求倒数
    if (expoent < 0)
    {
        flag = true;
        expoent = -expoent;
    }

    double res = 1.0;
    for (int i = 1; i <= expoent; ++i)
        res *= base;

    if (flag)
    {
        if (res == 0)
            throw "base 0, expoent < 0; InValid Params";
        res = 1 / res;
    }
    return res;
}

void test(char const *testName, int base, int expoent, int expected)
{
    assert(power(base, expoent) == expected);
    cout << testName << " passed" << endl;
}

void test1()
{
    test("test1", 1, 2, 1);
}

void test2()
{
    test("test2", -10, 2, 100);
}

void test3()
{
    test("test3", 0, 2, 0);
}

void test4()
{
    test("test4", 0, 0, 1);
}

void test5()
{
    test("test5", -2, 3, -8);
}

void test6()
{
    test("test6", 0, 1, 0);
}

void test7()
{
    test("test7", 0, -1, 0);
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}