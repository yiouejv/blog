#include <iostream>
using namespace std;

struct Node  // c++结构体是一个特殊的类
{
	int m;
	void func()
	{
		cout << "hello world" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Node a;
	a.func();
	return 0;
}