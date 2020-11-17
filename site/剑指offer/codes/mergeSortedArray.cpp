/*
	有两个排序的数组A1和A2，内存在A1的末尾有足够的空余空间容纳A2. 请实现一个函数，把A2中的所有数字插入到A1中，并且所有的数字的排序的。
*/

#include <iostream>
using namespace std;


void mergeSortedArray(int* arr1, int* arr2, const int length1, const int length2, const int resultLength)
{
	if (arr1 == nullptr)
	{
		return;
	}

	int indexOfArr1 = length1 - 1;
	int indexOfArr2 = length2 - 1;
	int indexOfArrLength = resultLength - 1;
	while (indexOfArr1 >= 0 && indexOfArr2 >= 0)
	{
		if (arr1[indexOfArr1] > arr2[indexOfArr2])
			arr1[indexOfArrLength --] = arr1[indexOfArr1 --];
		else
			arr1[indexOfArrLength --] = arr2[indexOfArr2 --];
	}
	
	while (indexOfArr2 >= 0)
	{
		arr1[indexOfArrLength --] = arr2[indexOfArr2 --];
	}
}


void test(int* arr1, int* arr2, const int* result, const int length1, const int length2, const int resultLength)
{
	mergeSortedArray(arr1, arr2, length1, length2, resultLength);
	if (arr1 == nullptr)
	{
		return;
	}
	for (int i = 0; i < resultLength; i++)
	{
		if (arr1[i] != result[i])
		{
			throw "assert failed";
		}
	}
	cout << "pass" << endl;
}


// 传递两个空指针
void test1()
{
	const int length1 = 0;
	const int length2 = 0;
	const int resultLength = 0;
	int* arr1 = nullptr;
	int* arr2 = nullptr;
	int* result = nullptr;
	test(arr1, arr2, result, length1, length2, resultLength);
}

// arr1为空指针, arr2正常
void test2()
{
	const int length1 = 0;
	const int length2 = 2;
	const int resultLength = 2;
	int* arr1 = nullptr;
	int arr2[length2] = {1, 2};
	int result[resultLength] = {1, 2};
	test(arr1, arr2, result, length1, length2, resultLength);
}

// arr1正常, arr2空指针
void test3()
{
	const int length1 = 2;
	const int length2 = 0;
	const int resultLength = 2;
	int arr1[resultLength] = { 1, 2 };
	int* arr2 = nullptr;
	int result[resultLength] = { 1, 2 };
	test(arr1, arr2, result, length1, length2, resultLength);
}

// arr1正常, arr2正常
void test4()
{
	const int length1 = 2;
	const int length2 = 1;
	const int resultLength = 3;
	int arr1[resultLength] = { 1, 2 };
	int arr2[length2] = { 1 };
	int result[resultLength] = { 1, 1, 2 };
	test(arr1, arr2, result, length1, length2, resultLength);
}

// arr1 有效长度小于 arr2长度
void test5()
{
	const int length1 = 2;
	const int length2 = 3;
	const int resultLength = 5;
	int arr1[resultLength] = { 0, 2 };
	int arr2[length2] = { 1, 3, 5 };
	int result[resultLength] = { 0, 1, 2, 3, 5 };
	test(arr1, arr2, result, length1, length2, resultLength);
}

int main(int argc, const char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
}