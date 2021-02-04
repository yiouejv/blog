#include <iostream>
using namespace std;

namespace stu
{
	void sort()
	{
		cout << "stu" << endl;
	}
}

void sort()
{
	cout << "stu1" << endl;
}


int main(int argc, char const *argv[])
{
	stu::sort();
	sort();
	return 0;
}

