#include <iostream>
#include <cassert>
#include <string>
using namespace std;

struct Node {
	int value;
	Node* pNext;
	Node* pSibling = nullptr;
};

void copyNode(Node* pHead);
void sibling(Node* pHead);
Node* subList(Node* pHead);


Node* complexListClone(Node* pHead)
{
	copyNode(pHead);
	sibling(pHead);
	return subList(pHead);
}


void copyNode(Node* pHead)
{
	Node* cur = pHead;

	while (cur != nullptr)
	{
		Node* pNode = new Node;
		pNode->value = cur->value;
		pNode->pNext = cur->pNext;
		cur->pNext = pNode;
		cur = pNode->pNext;
	}
}

void sibling(Node* pHead)
{
	if (pHead == nullptr)
		return;

	Node* pHeadCur = pHead;
	Node* pCloneCur = pHead->pNext;

	while (pHeadCur != nullptr)
	{
		if (pHeadCur->pSibling != nullptr)
			pCloneCur->pSibling = pHeadCur->pSibling->pNext;

		pHeadCur = pHeadCur->pNext->pNext;
		if (pHeadCur != nullptr)
			pCloneCur = pHeadCur->pNext;
	}
}

Node* subList(Node* pHead)
{
	if (pHead == nullptr)
		return nullptr;

	Node* pClone = pHead->pNext;
	Node* pHeadCur = pHead;
	Node* pCloneCur = pClone;

	while (pCloneCur->pNext != nullptr)
	{
		pHeadCur->pNext = pCloneCur->pNext;
		pHeadCur = pCloneCur->pNext;

		pCloneCur->pNext = pHeadCur->pNext;
		pCloneCur = pHeadCur->pNext;
	}
	return pClone;
}

int main(int argc, char const* argv[])
{
	Node* pHead = new Node();
	pHead->value = 1;

	Node* pNode2 = new Node();
	pNode2->value = 2;

	Node* pNode3 = new Node();
	pNode3->value = 3;

	pHead->pNext = pNode2;
	pHead->pSibling = pNode3;

	pNode2->pNext = pNode3;
	pNode2->pSibling = pNode3;
	Node* ret = complexListClone(pHead);
	return 0;
}