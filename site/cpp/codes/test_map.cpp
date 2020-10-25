#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


void print(pair<int, char> p)
{
	cout << p.first << ' ' << p.second << endl;
}

int main(int argc, char const* argv[])
{
	typedef pair<int, char> in_pair;
	pair< map<int, char>::iterator, bool > p;

	map<int, char> dic;
	dic.insert(pair<int, char>(1, 'a'));
	p = dic.insert(in_pair(2, 'b'));
	cout << "insert 2, b result: " << p.second << endl;
	p = dic.insert(in_pair(2, 'b'));
	cout << "insert 2, b result: " << p.second << endl;  // 冲突插入失败

	for_each(dic.begin(), dic.end(), print);
	
	cout << dic.count(2) << endl;
	return 0;
}