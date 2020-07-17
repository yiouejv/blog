#include <iostream>
using namespace std;



int main(int argc, char const *argv[])
{

	// new 申请内存
	int *p1 = new int;  // c++
	*p1 = 12;  // 写
	cout << *p1 << endl;  // 读
	delete p1;  // delete + 指针

	// 申请并初始化
	int *p2 = new int(123);
	cout << *p2 << endl;
	delete p2;

	// 申请数组空间，返回空间的首地址
	int *p = new int[5];
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 3;
	p[4] = 4;
	cout << p << endl;
	delete[] p;  // 释放数组要加[]
	return 0;
}

