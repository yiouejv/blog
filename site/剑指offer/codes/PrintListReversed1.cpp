#include <iostream>
#include <stack>
using namespace std;

#if 1
struct Node
{
	int value;
	Node* next;
};

void AddToTail(Node** pHead, int value)
{
	Node* node = new Node();
	node->value = value;
	node->next = nullptr;

	if (*pHead == nullptr)
		*pHead = node;
	else
	{
		Node* curNode = *pHead;

		while (curNode->next != nullptr)
			curNode = curNode->next;

		curNode->next = node;
	}
}

void PrintLinkReversed(Node* Head)
{
	stack<Node*> nodes;
	Node* cur = Head;

	while (cur != nullptr)
	{
		nodes.push(cur);
		cur = cur->next;
	}

	while (!nodes.empty())
	{
		cur = nodes.top();
		cout << cur->value << ' ';
		nodes.pop();
	}
	cout << endl;
}

void test()
{
	Node* head = nullptr;
	PrintLinkReversed(head);
}

void test1()
{
	Node* head = nullptr;
	AddToTail(&head, 1);
	PrintLinkReversed(head);
}

void test2()
{
	Node* head = nullptr;
	AddToTail(&head, 1);
	AddToTail(&head, 2);
	AddToTail(&head, 3);
	AddToTail(&head, 4);
	PrintLinkReversed(head);
}

int main(int argc, const char* argv[])
{
	test();
	test1();
	test2();
	return 0;
}
#endif