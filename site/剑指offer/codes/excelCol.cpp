#include <iostream>
#include <string.h>
#include <cassert>
#include <math.h>
using namespace std;

int getExcelCol(const char* col, int length)
{
    if (col == nullptr || length <= 0)
        throw "InValid Params";

    int sum = 0;
    int p = 0;
    for (int i = length - 2; i >= 0; i--)
    {
        sum += (pow(26, p++) * (col[i] - 64));
    }
    return sum;
}


void test(const char* testName, const char* col, int length, int expected)
{
    assert(getExcelCol(col, length) == expected);
    cout << testName << " passed" << endl;
}

void test1()
{
    const char col[] = {'A'};
    test("test1", col, 2, 1);
}

void test2()
{
    const char col[] = {'A', 'A'};
    test("test2", col, 3, 27);
}

void test3()
{
    const char col[] = {'A', 'B'};
    test("test3", col, 3, 28);
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();
    return 0;
}