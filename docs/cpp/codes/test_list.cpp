#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int v;
	char c;
};

struct Node2
{
	int v;
	char c;

	Node2(int v, char c)
	{
		this->v = v;
		this->c = c;
	}

	bool operator ==(const Node2& node) const
	{
		if (node.v == this->v && node.c == this->c)
			return true;
		return false;
	}

	bool operator <(const Node2& node) const
	{
		if (this->v < node.v)
			return true;
		return false;
	}
};


void printNode(Node& node)
{
	cout << "node.v: " << node.v << " node.c: " << node.c << endl;
}

void printNode2(Node2& node)
{
	cout << "node.v: " << node.v << " node.c: " << node.c << endl;
}

void constructedFunction()
{
	// 初始化为5个0
	list<Node> ls(5);
	for_each(ls.begin(), ls.end(), printNode);

	// 初始化为5个Node
	Node node = { 127, 'a' };
	list<Node> ls1(5, node);
	for_each(ls1.begin(), ls1.end(), printNode);

	// 用ls1 构造ls2
	list<Node> ls2(ls1);
	for_each(ls2.begin(), ls2.end(), printNode);

	// 用迭代器去构造list
	list<Node>::iterator iter = ls.begin();
	list<Node> ls3(++iter, ls.end());  // 取ls的第二个到最后一个
	for_each(ls3.begin(), ls3.end(), printNode);
}


void sizeResize()
{
	list<Node> ls(5);
	cout << "ls size: " << ls.size() << endl;
	cout << "ls empty: " << ls.empty() << endl;

	ls.resize(0);
	cout << "ls size: " << ls.size() << endl;
	cout << "ls empty: " << ls.empty() << endl;
}

void pushInsert()
{
	Node node1 = { 12, 'a' };
	Node node2 = { 13, 'b' };
	Node node3 = { 14, 'c' };

	list<Node> ls;
	ls.push_front(node1);
	ls.push_front(node2);
	ls.push_back(node3);
	//for_each(ls.begin(), ls.end(), printNode);


	list<Node>::iterator iter = ls.begin();
	iter++;
	ls.insert(iter, node3);  // 在第二个位置插入一个node3
	// for_each(ls.begin(), ls.end(), printNode);

	ls.insert(iter, 3, node2);  // 在第三个位置插入3个node2
	//for_each(ls.begin(), ls.end(), printNode);

	list<Node> ls2;
	list<Node>::iterator iter2 = ls2.begin();
	ls2.insert(iter2, iter, ls.end());  // 插入ls1的一段
	for_each(ls2.begin(), ls2.end(), printNode);
}

void reaseRemoveUniqueClear()
{
	list<Node2> ls;
	ls.push_back(Node2(12, 'a'));
	ls.push_back(Node2(13, 'b'));
	ls.push_back(Node2(14, 'c'));
	// for_each(ls.begin(), ls.end(), printNode2);

	// 头删除
	// ls.pop_front();
	// for_each(ls.begin(), ls.end(), printNode2);

	// 尾删除
	// ls.pop_back();
	// for_each(ls.begin(), ls.end(), printNode2);

	// 清空链表
	// ls.clear();
	// for_each(ls.begin(), ls.end(), printNode2);

	// 删除某一个中间元素
	// list<Node2>::iterator iter = ls.begin();
	// iter ++;
	// ls.erase(iter);
	// for_each(ls.begin(), ls.end(), printNode2);
	// ls.erase(iter, ls.end());
	// for_each(ls.begin(), ls.end(), printNode2);

	// 删除所有和参数相同的元素
	// ls.push_back(Node2(14, 'c'));
	// ls.push_back(Node2(14, 'c'));
	// for_each(ls.begin(), ls.end(), printNode2);
	// cout << "------------------" << endl;
	// ls.remove(Node2(14, 'c'));  // 结构体需要重载一下 == 运算符
	// for_each(ls.begin(), ls.end(), printNode2);

	// 删除重复的元素
	ls.push_back(Node2(14, 'c'));
	ls.push_back(Node2(14, 'c'));
	ls.unique();
	for_each(ls.begin(), ls.end(), printNode2);
}

void merge()
{
	list<Node2> ls;
	ls.push_back(Node2(12, 'a'));
	ls.push_back(Node2(13, 'b'));
	ls.push_back(Node2(14, 'c'));

	list<Node2> ls2;
	ls2.push_back(Node2(10, 'a'));
	ls2.push_back(Node2(11, 'b'));
	ls2.push_back(Node2(15, 'c'));

	ls.merge(ls2);
	for_each(ls.begin(), ls.end(), printNode2);
}

void sortReverse()
{
	list<Node2> ls;
	ls.push_back(Node2(13, 'a'));
	ls.push_back(Node2(12, 'b'));
	ls.push_back(Node2(14, 'c'));
	ls.sort();
	for_each(ls.begin(), ls.end(), printNode2);
	ls.reverse();
	for_each(ls.begin(), ls.end(), printNode2);
}

void find()
{
	list<Node2> ls;
	ls.push_back(Node2(13, 'a'));
	ls.push_back(Node2(12, 'b'));
	ls.push_back(Node2(14, 'c'));
	list<Node2>::iterator iter = find(ls.begin(), ls.end(), Node2(12, 'b'));
	for (; iter != ls.end(); iter++)
	{
		cout << "value: " << iter->v << endl;
	}
}

int main(int argc, char const* argv[])
{
	// constructedFunction();
	// sizeResize();
	// pushInsert();
	// reaseRemoveUniqueClear();
	// merge();
	// sortReverse();
	find();
	return 0;
}