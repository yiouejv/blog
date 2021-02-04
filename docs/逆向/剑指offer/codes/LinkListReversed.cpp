// LinkListReversed.cpp
// 链表反转

#include <iostream>
#include <cassert>
using namespace std;


struct Node
{
    int value;
    Node* next = nullptr;
};

Node * LinkListReversed(Node** pHead)
{
    if (pHead == nullptr || *pHead == nullptr)
        return nullptr;

    Node* head = *pHead;
    // 只有一个头节点，直接返回
    if (head->next == nullptr)  
        return head;

    Node* preNode = head;
    Node* curNode = head->next;
    Node* tempNode = curNode->next;
    // 只有两个节点
    if (curNode -> next == nullptr)
    {
        curNode->next = head;
        head->next = nullptr;
        return curNode;
    }

    while (curNode != nullptr)
    {
        curNode->next = preNode;
        if (preNode == head) preNode->next = nullptr;
        preNode = curNode;
        curNode = tempNode;
        if (curNode == nullptr) return preNode;
        tempNode = curNode->next;
    }
    return nullptr;
}


// 测试空指针
void test()
{
    Node* head = nullptr;
    Node* reversedHead = LinkListReversed(&head);
    assert(reversedHead == nullptr);
    cout << "test passed" << endl;
}

// 测试单节点
void test1()
{
    Node* head = new Node;
    head->value = 1;
    Node* reversedHead = LinkListReversed(&head);
    assert(reversedHead == head);
    cout << "test1 passed" << endl;
}

// 测试两个节点
void test2()
{
    Node* head = new Node;
    head->value = 1;

    Node* p1 = new Node;
    p1->value = 2;
    head->next = p1;
    Node* reversedHead = LinkListReversed(&head);
    assert(reversedHead->value == 2);
    assert(reversedHead->next->value == 1);
    cout << "test2 passed" << endl;
}

// 测试三个节点
void test3()
{
    Node* head = new Node;
    head->value = 1;

    Node* p1 = new Node;
    p1->value = 2;
    head->next = p1;

    Node* p2 = new Node;
    p2->value = 3;
    p1->next = p2;

    Node* reversedHead = LinkListReversed(&head);
    assert(reversedHead->value == 3);
    assert(reversedHead->next->value == 2);
    assert(reversedHead->next->next->value == 1);
    assert(reversedHead->next->next->next == nullptr);
    cout << "test3 passed" << endl;
}

int main(int argc, char const *argv[])
{
    test();
    test1();
    test2();
    test3();

    return 0;
}
