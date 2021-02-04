/*
	请实现一个函数, 把字符串中的每个空格替换成"%20". 例如, 输入"We are happy.", 则输出"We%20are%20happy."
	解法一：进行原地替换并且保证输入的字符串后面有足够多的内存。
*/
#include <iostream>
using namespace std;


void array_back_two(char* string, int length, int start, int offset)
{
	for (int i = length; i > start; i--)
	{
		string[i + 2] = string[i];
	}
}

void blank_replace(char* string)
{
	int length = 0;
	while (string[length] != '\0')
	{
		length += 1;
	}
	length++;

	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			string[i] = '%';
			array_back_two(string, length, i, 2);  //i之后的元素往后挪两位
			string[i + 1] = '2';
			string[i + 2] = '0';
		}
		i += 1;
	}
}

void print_string(char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		cout << string[i];
		i += 1;
	}
	cout << endl;
}

void test(char* string, char* result)
{
	blank_replace(string);
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] != result[i])
		{
			throw "assert failed";
		}
		i += 1;
	}
}

void test1()
{
	char string[10] = "";
	char result[] = "";
	test((char*)string, (char*)result);
}

void test2()
{
	char string[30] = "We are happy.";
	char result[] = "We%20are%20happy.";
	test((char*)string, (char*)result);
}

void test3()
{
	char string[10] = " ";
	char result[] = "%20";
	test((char*)string, (char*)result);
}

void test4()
{
	char string[10] = "123 ";
	char result[] = "123%20";
	test((char*)string, (char*)result);
}

void test5()
{
	char string[20] = " 123 ";
	char result[] = "%20123%20";
	test((char*)string, (char*)result);
}

int main(int argc, const char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
