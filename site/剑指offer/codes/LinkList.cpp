#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

void AddToTail(Node **pHead, int value)
{
	Node* node = new Node();
	node->value = value;
	node->next = nullptr;

	// 如果head为nullptr, 则追加的元素为第一个元素
	if (*pHead == nullptr)
	{
		*pHead = node;
	}
	else
	{
		Node* cur = *pHead;

		while (cur->next != nullptr)
			cur = cur->next;

		cur->next = node;
	}

}

void IterLink(Node** pHead)
{
	if (*pHead == nullptr)
		return;
	
	Node* cur = *pHead;

	while (cur->next != nullptr)
	{
		cout << cur->value << ' ';
		cur = cur->next;
	}
	cout << cur->value << endl;
}

void RemoveNode(Node** pHead, int value)
{
	// 空链表
	if (pHead == nullptr || *pHead == nullptr)
		return;

	Node* pre = *pHead;
	if (pre->value == value)
	{
		if (pre->next != nullptr)
			*pHead = pre->next;
		else
			*pHead = nullptr;
		return;
	}

	if (pre->next == nullptr)
		return;

	Node* cur = pre->next;
	while (cur != nullptr)
	{
		if (cur->value == value)
		{
			pre->next = cur->next;
			return;
		}
		else
		{
			pre = pre->next;
			cur = pre->next;
		}
	}
}

void TestAddToTail()
{
	Node* head = nullptr;
	AddToTail(&head, 0);
	IterLink(&head);

	AddToTail(&head, 1);
	IterLink(&head);

	AddToTail(&head, 2);
	IterLink(&head);

	AddToTail(&head, 3);
	IterLink(&head);
}

void TestRemoveNode()
{
	Node* head = nullptr;
	RemoveNode(&head, 0);
	IterLink(&head);  // ''

	AddToTail(&head, 0);
	RemoveNode(&head, 0);
	IterLink(&head);  // ''

	AddToTail(&head, 1);
	AddToTail(&head, 2);
	RemoveNode(&head, 1);
	IterLink(&head);  // 2

	AddToTail(&head, 3);
	AddToTail(&head, 4);
	RemoveNode(&head, 3);
	IterLink(&head);  // 2, 4

	AddToTail(&head, 5);
	AddToTail(&head, 6);
	AddToTail(&head, 7);
	IterLink(&head);  // 2, 4, 5, 6, 7
	RemoveNode(&head, 7);
	IterLink(&head);  // 2, 4, 5, 6
}


int main(int argc, const char* argv[])
{
	//TestAddToTail();
	TestRemoveNode();
	return 0;
}


