#include <iostream>
#include <cassert>
#include <string.h>
#include <math.h>
using namespace std;

// number 代表的字符数组模拟数字+1
bool increame(char* number, int length)
{
    if (number == nullptr)
        return false;

    auto add_1 = [number](int i)
    {
        if (number[i] == '0')
            number[i] = '1';
        else if (number[i] == '1')
            number[i] = '2';
        else if (number[i] == '2')
            number[i] = '3';
        else if (number[i] == '3')
            number[i] = '4';
        else if (number[i] == '4')
            number[i] = '5';
        else if (number[i] == '5')
            number[i] = '6';
        else if (number[i] == '6')
            number[i] = '7';
        else if (number[i] == '7')
            number[i] = '8';
        else if (number[i] == '8')
            number[i] = '9';
        else if (number[i] == '9')
            number[i] = '0';
    };

    int i = length - 1;
    add_1(i);

    while (i - 1 >= 0 && number[i] == '0')
        add_1(--i);

    return true;
}

// 打印
void printNumber(const char* number)
{
    int i = 0;

    while (number[i] != '\0')
        cout << number[i++];

    cout << ' ';
}

void printNumberOfMaxDigital(int n)
{
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    memset(number, '0', n * sizeof(char));
    number[n] = '\0';

    while (increame(number, n))
    {
         printNumber(number);

        // 判断是否终止
        bool _break = true;
        for (int i = 0; i < n; ++i)
        {
            if (number[i] != '9')
            {
                _break = false;
                break;
            }
        }
        if (_break) break;
    }
    cout << endl;
    delete[] number;
}

int main(int argc, char const* argv[])
{
    printNumberOfMaxDigital(1);

    //printNumberOfMaxDigital(2);
    //printNumberOfMaxDigital(3);
    //printNumberOfMaxDigital(4);
    // printNumberOfMaxDigital(32);
    return 0;
}