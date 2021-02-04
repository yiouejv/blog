/*
	请实现一个函数, 把字符串中的每个空格替换成"%20". 例如, 输入"We are happy.", 则输出"We%20are%20happy."
	解法二
*/
#include <iostream>
using namespace std;


void blank_replace(char* string)
{
	if (string == nullptr)
		return;

	int stringLength = 0,
		blankCount = 0,
		newStringLength = 0;
	int i = 0;

	while (string[i] != '\0')
	{
		stringLength += 1;

		if (string[i] == ' ')
		{
			blankCount += 1;
		}

		i += 1;
	}

	newStringLength = stringLength + blankCount * 2;
	int indexOfOriginal = stringLength;
	int indexOfNew = newStringLength;

	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] != ' ')
		{
			string[indexOfNew --] = string[indexOfOriginal];
		}
		else
		{
			string[indexOfNew --] = '0';
			string[indexOfNew --] = '2';
			string[indexOfNew --] = '%';
		}
		--indexOfOriginal;
	}
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

#if 1
int main(int argc, const char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
#endif