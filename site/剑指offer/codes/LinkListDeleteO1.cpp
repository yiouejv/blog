#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

void DeleteNode(Node** pHead, Node* pToBeDelete)
{
	if (pHead == nullptr || *pHead == nullptr || pToBeDelete == nullptr)
		return;

	Node* head = *pHead;
	// 只有一个节点
	if (head->next == nullptr)
	{
		delete pToBeDelete;
		*pHead = nullptr;
	}
	// 有多个节点
	else 
	{
		// 删除尾节点
		if (pToBeDelete->next == nullptr)
		{
			delete pToBeDelete;
			head->next = nullptr;
		}
		// 删除头节点
		else if (pToBeDelete == head)
		{
			*pHead = head->next;
			delete head;
		}
		else
		{
			Node* p = pToBeDelete->next;
			pToBeDelete->value = pToBeDelete->next->value;
			pToBeDelete->next = pToBeDelete->next->next;
			delete p;
		}
	}
}


int main(int argc, char const* argv[])
{
	Node* head = new Node;
	head->value = 0;
	head->next = nullptr;

	Node* p1 = new Node;
	p1->value = 1;
	p1->next = nullptr;
	head->next = p1;

	Node* p2 = new Node;
	p2->value = 2;
	p1->next = p2;
	p2->next = nullptr;

	DeleteNode(&head, p1);
	return 0;
}