/*
	数组和指针的区别
*/
#include <iostream>
using namespace std;

int GetSize(int data[])
{
	return sizeof(data);
}

int main(int argc, const char* argv[])
{
	int data1[] = {1, 2, 3, 4, 5};
	int size1 = sizeof(data1);  // 数组大小，数组长度5

	int* data2 = data1;
	int size2 = sizeof(data2);  // 指针大小 32位4字节，64位8字节

	int size3 = GetSize(data1); // 
	cout << size1 << endl << size2 << endl << size3 << endl;
	return 0;
}
