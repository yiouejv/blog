// deleteDuplication
// 删除有序链表里重复的节点
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next = nullptr;
};

void deleteDuplication(Node** pHead)
{
    if (pHead == nullptr || *pHead == nullptr)
        return;

    Node* head = *pHead;
    // 只有一个节点
    if (head->next == nullptr)
        return;

    // 两个节点
    Node* preNode = head;
    Node* curNode = head->next;

    if (curNode->next == nullptr)
    {
        if (curNode->value == preNode->value)
        {
            head->next = nullptr;
            delete curNode;
            return;
        }
    }

    // 多个节点
    while (curNode->next != nullptr)
    {
        if (preNode->value == curNode->value)
        {
            Node* waitDelete = curNode->next;
            curNode->value = curNode->next->value;
            curNode->next = curNode->next->next;
            delete waitDelete;
        }
        else 
        {
            preNode = preNode->next;
            curNode = preNode->next;
        }
    }

    if (preNode->value == curNode->value)
    {
        preNode->next = nullptr;
        delete curNode;
    }
}

// 空指针
void test1()
{
    Node* pnull = nullptr;
    deleteDuplication(&pnull);
}

// 只有一个节点
void test2()
{
    Node* head = new Node;
    head->value = 1;
    deleteDuplication(&head);
}

void test3()
{
    Node* head = new Node;
    head->value = 1;
    Node* p1 = new Node;
    p1->value = 2;
    head->next = p1;
    deleteDuplication(&head);  // 两个节点，和头节点不重复

    p1->value = 1;
    deleteDuplication(&head);  // 两个节点，和头节点重复
}

// 多个节点
void test4()
{
    Node* head = new Node;
    head->value = 1;
    Node* p2 = new Node;
    p2->value = 2;
    head->next = p2;

    Node* p3 = new Node;
    p3->value = 3;
    p2->next = p3;

    Node* p4 = new Node;
    p4->value = 3;
    p3->next = p4;  // 重复节点尾节点
    deleteDuplication(&head);
}

void test5()
{
    // 多个重复节点
    Node* head = new Node;
    head->value = 1;

    Node* p1 = new Node;
    p1->value = 2;
    head->next = p1;

    Node* p2 = new Node;
    p2->value = 2;
    p1->next = p2;

    Node* p3 = new Node;
    p3->value = 2;
    p2->next = p3;

    Node* p4 = new Node;
    p4->value = 3;
    p3->next = p4;

    Node* p5 = new Node;
    p5->value = 3;
    p4->next = p5;

    Node* p6 = new Node;
    p6->value = 4;
    p5->next = p6;
    deleteDuplication(&head);
}

int main(int argc, char const* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}