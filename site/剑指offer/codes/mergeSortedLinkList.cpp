// mergeSortedLinkList.cpp
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next = nullptr;
};


Node* mergeSortedLinkList(Node** pHead1, Node** pHead2)
{
    if (pHead1 == nullptr && pHead2 == nullptr)
        return nullptr;

    if (*pHead1 == nullptr)
        return *pHead2;

    if (*pHead2 == nullptr)
        return *pHead1;

    Node* head1 = *pHead1;
    Node* head2 = *pHead2;
    Node* resultHead = nullptr;
    Node* resultCurNode = nullptr;

    while (head1 != nullptr && head2 != nullptr)
    {
        Node* node = new Node;

        if (head1->value < head2->value)
        {
            node->value = head1->value;
            head1 = head1->next;
        }
        else
        {
            node->value = head2->value;
            head2 = head2->next;
        }

        if (resultHead == nullptr)
        {
            resultHead = node;
            resultCurNode = node;
        }
        else
        {
            resultCurNode->next = node;
            resultCurNode = node;
        }
    }

    while (head1 != nullptr)
    {
        Node* node = new Node;
        node->value = head1->value;
        resultCurNode->next = node;
        resultCurNode = node;
        head1 = head1->next;
    }

    while (head2 != nullptr)
    {
        Node* node = new Node;
        node->value = head2->value;
        resultCurNode->next = node;
        resultCurNode = node;
        head2 = head1->next;
    }
    return resultHead;
}

// 功能测试
void test()
{
    Node* head1 = new Node;
    head1->value = 1;

    Node* p1 = new Node;
    p1->value = 3;
    head1->next = p1;

    Node* p2 = new Node;
    p2->value = 5;
    p1->next = p2;

    Node* p3 = new Node;
    p3->value = 7;
    p2->next = p3;


    Node* head2 = new Node;
    head2->value = 2;

    Node* p4 = new Node;
    p4->value = 4;
    head2->next = p4;

    Node* p5 = new Node;
    p5->value = 6;
    p4->next = p5;

    Node* p6 = new Node;
    p6->value = 8;
    p5->next = p6;
    Node* mergeSortedLink = mergeSortedLinkList(&head1, &head2);
}

// 只传一个链表
void test1()
{
    Node* head1 = new Node;
    head1->value = 1;

    Node* p1 = new Node;
    p1->value = 3;
    head1->next = p1;

    Node* p2 = new Node;
    p2->value = 5;
    p1->next = p2;

    Node* p3 = new Node;
    p3->value = 7;
    p2->next = p3;

    Node* head2 = nullptr;
    Node* mergeSortedLink = mergeSortedLinkList(&head1, &head2);
}


// 一个链表只有一个节点
void test2()
{
    Node* head1 = new Node;
    head1->value = 1;

    Node* p1 = new Node;
    p1->value = 3;
    head1->next = p1;

    Node* p2 = new Node;
    p2->value = 5;
    p1->next = p2;

    Node* p3 = new Node;
    p3->value = 7;
    p2->next = p3;

    Node* head2 = new Node;
    head2->value = 2;
    Node* mergeSortedLink = mergeSortedLinkList(&head1, &head2);
}



int main(int argc, char const* argv[])
{
    test();
    test1();
    test2();
    return 0;
}