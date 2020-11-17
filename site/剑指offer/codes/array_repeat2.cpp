/*
	在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组种至少有一个数字是重复的。 
	请找出数组中任意一个重复的数字，但不能修改输入的数组。
	例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}, 那么对应的输出是重复的数字2或者3。
*/
#include <iostream>
using namespace std;


int count_range(int nums[], int length, int start, int stop)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (nums[i] >= start && nums[i] <= stop)
		{
			count++;
		}
	}
	return count;
}

int find_one_repeat(int nums[], int length, int start, int stop)
{
	if (nums == nullptr)
	{
		return -1;
	}

	int mid = (start + stop) / 2;
	int count = count_range(nums, length, start, mid);
	if ( stop - start == 1)
	{
		if (count > 1)
		{
			return start;
		}
		else
		{
			count = count_range(nums, length, mid+1, stop);
			if (count > 1)
			{
				return stop;
			}
			else
			{
				return -1;
			}
		}
	}
	if (count > mid - start + 1)
	{
		return find_one_repeat(nums, length, start, mid);
	}
	else
	{
		return find_one_repeat(nums, length, mid + 1, stop);
	}
	return -1;
}

void test(int nums[], int length, int target)
{
	int res = find_one_repeat(nums, length, 1, length);
	cout << res << endl;
	if (res != target)
	{
		throw "assert failed";
	}
}

// 测试题目用例
void test1()
{
	int nums[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int length = sizeof(nums) / sizeof(int);
	test(nums, length, 3);
}

// 测试重复数组最小元素
void test2()
{
	int nums[] = { 1, 1, 5, 4, 3, 2, 6, 7 };
	int length = sizeof(nums) / sizeof(int);
	test(nums, length, 1);
}

// 测试重复数组最大元素
void test3()
{
	int nums[] = { 1, 3, 2, 4, 5, 5 };
	int length = sizeof(nums) / sizeof(int);
	test(nums, length, 5);
}

// 测试数组多个重复元素
void test4()
{
	int nums[] = { 1, 3, 2, 4, 5, 5, 6, 2 };
	int length = sizeof(nums) / sizeof(int);
	test(nums, length, 2);
}

// 测试空数组
void test5()
{
	int* nums = nullptr;
	int length = sizeof(nums) / sizeof(int);
	test(nums, length, -1);
}

// 测试不包含重复数字
void test6()
{
	int nums[] = { 1, 2, 3, 4, 5 };
	int length = sizeof(nums) / sizeof(int);
	test(nums, length, -1);
}


int main(int argc, const char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}