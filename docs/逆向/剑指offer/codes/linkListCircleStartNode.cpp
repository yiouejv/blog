//linkListCircleStartNode.cpp
#include <iostream>
using namespace std;


struct Node
{
    int value;
    Node* next = nullptr;
};

Node* linkListCircleStartNode(Node** pHead)
{
    if (pHead == nullptr || *pHead == nullptr)
        return nullptr;

    Node* head = *pHead;

    if (head->next == nullptr || head->next->next == nullptr)
        return nullptr;

    // 判断是否存在环
    Node* p1 = head->next;
    Node* p2 = head->next->next;

    while (p1 != nullptr && p2 != nullptr && p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    if (p1 == nullptr)  // 不存在环
        return nullptr;

    // 判断环的长度
    int circleLength = 1;
    p1 = p1->next;
    while (p1 != p2)
    {
        p1 = p1->next;
        circleLength++;
    }

    // 再利用两个指针找到环的入口
    Node* pBefore = head;
    Node* pAfter = head;
    for (int i = 0; i < circleLength; ++i)
        pAfter = pAfter->next;

    while (pBefore != pAfter)
    {
        pBefore = pBefore->next;
        pAfter = pAfter->next;
    }
    return pBefore;
}

// 功能测试
// 
// 1->2->3->4->5->6->3
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
    p6->next = p3;
    Node* listCircleStartNode = linkListCircleStartNode(&head);
}

// 无环
// 
// 1->2->3->4->5->6
void test2()
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
    Node* listCircleStartNode = linkListCircleStartNode(&head);
}

// 无环
// 
// 1->2
void test3()
{
    Node* head = new Node;
    head->value = 1;

    Node* p1 = new Node;
    p1->value = 2;
    head->next = p1;
    Node* listCircleStartNode = linkListCircleStartNode(&head);
}

// 有环
// 
// 1->1
void test4()
{
    Node* head = new Node;
    head->value = 1;

    Node* p1 = new Node;
    p1->value = 1;
    head->next = p1;
    p1->next = head;
    Node* listCircleStartNode = linkListCircleStartNode(&head);
}

// 无环
// 
// 1
void test5()
{
    Node* head = new Node;
    head->value = 1;

    Node* listCircleStartNode = linkListCircleStartNode(&head);
}

// 功能测试
// 
// 1->2->3->4->5->6->4
void test6()
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
    p6->next = p4;
    Node* listCircleStartNode = linkListCircleStartNode(&head);
}

int main(int argc, char const* argv[])
{
    // test();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    return 0;
}