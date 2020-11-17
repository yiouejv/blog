/*
	面试题3: 找出数组中重复的数字
	在一个长度为n的数组里的所有数字都在0~n-1的范围内。
	数组中某些数字是重复的，但是不知道有几个数字是重复的了，也不知道数字重复了几次。
	请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3},那么对应的输出重复的数字2或者3。

*/
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int find_one_repeat(int nums[], int length)
{
	if (nums == nullptr || length < 1)
	{
		return -1;
	}
	for (int i = 0; i < length; i++)
	{
		while (nums[i] != i)
		{
			if (nums[ nums[i] ] == nums[i])
			{
				return nums[i];
			}
			swap(nums[i], nums[nums[i]]);
		}
	}
	return -1;
}

// 题目用例
void test1()
{
	int nums[7] = { 2, 3, 1, 0, 2, 5, 3 };
	int res = find_one_repeat(nums, sizeof(nums) / sizeof(int));
	if (res != 2)
	{
		cout << res << endl;
		throw "assert failed";
	}
}

// 重复的数字是数组中最小的数字
void test2()
{
	int nums[] = { 2, 1, 3, 1, 4 };
	int res = find_one_repeat(nums, sizeof(nums) / sizeof(int));
	if (res != 1)
	{
		cout << res << endl;
		throw "assert failed";
	}
}

// 重复的数字是数组中最大的数字
void test3()
{
	int nums[] = { 2, 4, 3, 1, 4 };
	int res = find_one_repeat(nums, sizeof(nums) / sizeof(int));
	if (res != 4)
	{
		cout << res << endl;
		throw "assert failed";
	}
}

// 数组中存在多个重复的数字
void test4()
{
	int nums[] = { 2, 4, 4, 1, 4 };
	int res = find_one_repeat(nums, sizeof(nums) / sizeof(int));
	if (res != 4)
	{
		cout << res << endl;
		throw "assert failed";
	}
}

// 没有重复的数字
void test5()
{
	int nums[] = { 2, 1, 3, 0, 4 };
	int res = find_one_repeat(nums, sizeof(nums) / sizeof(int));
	if (res != -1)
	{
		cout << res << endl;
		throw "assert failed";
	}
}

// 没有重复的数字
void test6()
{
	int nums[] = { 2, 1, 3, 5, 4 };
	int res = find_one_repeat(nums, sizeof(nums) / sizeof(int));
	if (res != -1)
	{
		cout << res << endl;
		throw "assert failed";
	}
}

// 无效的输入
void test7()
{
	int *nums = nullptr;
	int res = find_one_repeat(nums, sizeof(nums) / sizeof(int));
	if (res != -1)
	{
		cout << res << endl;
		throw "assert failed";
	}
}

int main(int argc, const char* argv[])
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