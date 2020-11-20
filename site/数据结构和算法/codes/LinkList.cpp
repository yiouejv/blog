#include<malloc.h>
#include<stdio.h>
#include<iostream>
using namespace std;

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node Node;
typedef struct Node* LinkList;

bool InsertAfterNode(Node* p, int value);

bool InitList(LinkList& L) {
    L = NULL;
    return true;
}

bool IsEmpty(LinkList L) {
    return L == NULL;
}


// 在某个位置插入节点
bool InsertList(LinkList& L, int i, int value) {
    if (i < 0) {
        return false;
    }
    if (i == 0) {
        Node* pNode = (Node*)malloc(sizeof(Node));
        if (pNode == NULL) return false;  // 内存分配失败
        pNode->value = value;
        pNode->next = L;
        L = pNode;
        return true;
    }

    Node* curNode = L;
    int j = 0;
    while (curNode != NULL && j < i - 1) {
        curNode = curNode->next;
        j++;
    }
    return InsertAfterNode(curNode, value);
}

// 在节点之前插入
bool InsertBeforeNode(Node* p, int value) {
    if (p == NULL) return false;

    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) return false;

    node->value = p->value;
    p->value = value;
    node->next = p->next;
    p->next = node;
    return true;
}

// 在节点后面插入
bool InsertAfterNode(Node* p, int value) {
    if (p == NULL) return false;

    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) return false;

    node->value = value;
    node->next = p->next;
    p->next = node;
    return true;
}

Node* DeleteElement(LinkList& L, int value) {
    if (L->value == value) {
        Node* ret = L;
        L = L->next;
        return ret;
    }

    Node* preNode = L;
    Node* curNode = L->next;

    while (curNode != NULL && curNode->value != value) {
        preNode = curNode;
        curNode = curNode->next;
    }
    if (curNode == NULL) {
        return NULL;
    }

    preNode->next = curNode->next;
    return curNode;
}

bool DeleteNode(LinkList& L, Node* p, int& e) {
    if (p == NULL) return false;
    if (L == p) {
        L = p->next;
        e = p->value;
        p->next = NULL;
        free(p);
    }

    Node* preNode = L;
    Node* curNode = L->next;

    while (curNode != NULL && curNode!=p) {
        preNode = curNode;
        curNode = curNode->next;
    }
    if (curNode == NULL) return false;

    preNode->next = curNode->next;
    curNode->next = NULL;
    e = curNode->value;
    free(curNode);
    return true;
}

// 查找元素
bool GetElement(const LinkList &L, int index, int &result) {
    if (index < 0) return false;
    int i = 0;

    Node* curNode = L;
    while (curNode != NULL && i < index) {
        curNode = curNode->next;
        i ++;
    }
    if (curNode == NULL) return false;

    result = curNode->value;
    return true;
}

int main(int argc, char const* argv[])
{
    LinkList L;
    InitList(L);
    InsertList(L, 0, 0);
    InsertList(L, 0, 1);
    InsertList(L, 0, 2);
    InsertList(L, 0, 3);

    InsertBeforeNode(L, 5);
    InsertBeforeNode(L->next, 4);

    InsertAfterNode(L, 4);
    InsertAfterNode(L->next, 3);

    int result;
    for (int i = 0; i < 10; i++) {
        if (GetElement(L, i, result)) {
            cout << "index " << i << ":" << result << endl;
        } else {
           cout << "index " << i << " not exists" << endl;
        }
    }
    return 0;
}