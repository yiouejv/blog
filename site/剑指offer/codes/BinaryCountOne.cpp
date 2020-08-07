#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// =============================================== 
int countBinaryOne(int n)
{
	int count = 0;
	while (n != 0)
	{
		count ++;
		n &= (n - 1);
		if ( n == 0 )
			break;
	}
	return count;
}

void test(const char* testName, int n, int expected)
{
	assert(countBinaryOne(n) == expected);
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

int main(int argc, char const *argv[])
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}