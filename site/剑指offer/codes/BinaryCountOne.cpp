#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// =============================================== 方法1:  (n - 1) & n 消除二进制中最后一个1
int countBinaryOne(int n)
{
	int count = 0;
	while (n != 0)
	{
		count++;
		n &= (n - 1);
		if (n == 0)
			break;
	}
	return count;
}

// =============================================== 方法2: 判断二进制每一位是否是1
int countBinaryOne2(int n)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((n & (1 << i)) == (1 << i))
		{
			count++;
		}
	}
	return count;
}

void test(const char* testName, int n, int expected)
{
	assert(countBinaryOne2(n) == expected);
	cout << testName << " passed" << endl;
}

void test1()
{
	test("test1", 9, 2);
}

void test2()
{
	test("test2", 0, 0);
}

void test3()
{
	test("test3", 4, 1);
}

void test4()
{
	test("test4", 11, 3);
}

int main(int argc, char const* argv[])
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}