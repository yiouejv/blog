// tailKNode

#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next = nullptr;
};

Node* tailKNode(Node **pHead, int k)
{
    if (pHead == nullptr || *pHead == nullptr || k <= 0)
        return nullptr;

    Node* head = *pHead;
    Node* preNode = head;
    Node* kNode = preNode;

    for (int i = 0; i < k - 1; ++i)
    {
        kNode = kNode->next;
        if (kNode == nullptr)
            return nullptr;
    }

    while (kNode->next != nullptr)
    {
        preNode = preNode->next;
        kNode = kNode->next;
    }
    return preNode;
}


// 功能测试
void test()
{
    Node* head = new Node;
    head->value = 1;

    Node* p1 = new Node;
    p1->value = 2;
    head->next = p1;

    Node* p2 = new Node;
    p2->value = 2;
    p1->next = p2;

    Node* p3 = new Node;
    p3->value = 3;
    p2->next = p3;

    Node* p4 = new Node;
    p4->value = 4;
    p3->next = p4;

    Node* p5 = new Node;
    p5->value = 5;
    p4->next = p5;

    Node* p6 = new Node;
    p6->value = 6;
    p5->next = p6;
    Node* kNode = tailKNode(&head, 3);
}

// k 大于 链表的长度
void test1()
{
    Node* head = new Node;
    head->value = 1;

    Node* p1 = new Node;
    p1->value = 2;
    head->next = p1;
    Node* kNode = tailKNode(&head, 3);
}

// k 等于链表的长度
void test2()
{
    Node* head = new Node;
    head->value = 1;

    Node* p1 = new Node;
    p1->value = 2;
    head->next = p1;
    Node* kNode = tailKNode(&head, 2);
}


int main(int argc, char const* argv[])
{
    // test();
    // test1();
    test2();
    return 0;
}