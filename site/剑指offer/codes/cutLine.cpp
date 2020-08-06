#include <iostream>
#include <cassert>
#include <string.h>
using namespace std;

int getCutLineMultiMax(int length)
{
    if (length < 2)
        return 0;

    if (length == 2)
        return 1;

    if (length == 3)
        return 2;

    int* products = new int[length + 1];
    memset(products, 0, (length + 1) * sizeof(4));
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    for (int i = 4; i <= length; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            int product = products[j] * products[i - j];
            if (product > products[i])
            {
                products[i] = product;
            }
        }
    }
    int res = products[length];
    delete[] products;
    return res;
}

void test(const char* testName, int length, int expected)
{
    assert(getCutLineMultiMax(length) == expected);
    cout << testName << " passed" << endl;
}

// 绳子的长度为0, 1
void test1()
{
    test("test1", 1, 0);
}

// 绳子的长度为2
void test2()
{
    test("test2", 2, 1);
}

// 绳子的长度为3
void test3()
{
    test("test3", 3, 2);
}

// 绳子的长度为4
void test4()
{
    test("test4", 4, 4);
}

// 绳子的长度为5
void test5()
{
    test("test5", 5, 6);
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}


