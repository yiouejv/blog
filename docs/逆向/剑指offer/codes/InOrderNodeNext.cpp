#include <iostream>
#include <exception>
using namespace std;

#if 1
struct Node
{
    int value;
    Node* leftTree;
    Node* rightTree;
    Node* parentNode;
};

Node* BuildCore
(
    int* startPre, int* endPre,
    int* startIn, int* endIn
)
{
    // 前序遍历第一个值拿到根节点的值
    Node* root = new Node();
    root->value = *startPre;

    if (startPre == endPre)
    {
        if (startIn == endIn && *startPre == *startIn)
            return root;
        throw std::exception("Invalid Input");
    }

    // 在中序遍历中的找到根节点的值
    int* rootValueIn = startIn;
    while (rootValueIn <= endIn && *rootValueIn != *startPre)
        ++rootValueIn;

    if (*rootValueIn != *startPre)
        throw std::exception("Invalid Input");

    int startInLength = rootValueIn - startIn;

    if (startInLength > 0)
    {
        root->leftTree = BuildCore(startPre + 1, startPre + startInLength,
            startIn, rootValueIn - 1);
        root->leftTree->parentNode = root;
    }
    if (endIn - rootValueIn > 0)
    {
        root->rightTree = BuildCore(startPre + startInLength + 1, endPre,
            rootValueIn + 1, endIn);
        root->rightTree->parentNode = root;
    }
    return root;
}

Node* BuildTree(int* pre, int* in, int length)
{
    if (pre == nullptr || in == nullptr || length <= 0)
        return nullptr;
    return BuildCore(pre, pre + length - 1, in, in + length - 1);
}

Node* InOrderNodeNextValue(Node* pNode)
{
    if (pNode == nullptr)
        return nullptr;

    Node * p = nullptr;
    // 如果该节点存在右子树，则下一个节点为右子树的最左子节点
    if (pNode->rightTree != nullptr)
    {
        p = pNode->rightTree;
        while (p->leftTree != nullptr)
            p = p->leftTree;
        return p;
    }
    // 如果该节点不存在右子树，则一直往上找, 如果节点是它父节点的左子节点, 那么下一个节点为它的父节点
    else
    {
        p = pNode;
        while (p->parentNode != nullptr && p->parentNode->leftTree != p)
            p = p->parentNode;
        return p->parentNode;
    }
    
    return nullptr;
}

/*
        1
      /   \
     2     3
    /     / \
   4     5   6
    \       /
     7     8
*/
void test()
{
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    int length = 8;
    Node* root = BuildTree(pre, in, length);

    Node* p0 = InOrderNodeNextValue(root);
    if (p0 != root->rightTree->leftTree)
        throw exception("assert failed");
    else
        cout << "p0 passed" << endl;

    Node* p1 = InOrderNodeNextValue(root->leftTree);
    if (p1 != root)
        throw exception("assert failed");
    else
        cout << "p1 passed" << endl;

    Node* p2 = InOrderNodeNextValue(root->leftTree->leftTree);
    if (p2 != root->leftTree->leftTree->rightTree)
        throw exception("assert failed");
    else
        cout << "p2 passed" << endl;

    Node* p3 = InOrderNodeNextValue(root->leftTree->leftTree->rightTree);
    if (p3 != root->leftTree)
        throw exception("assert failed");
    else
        cout << "p3 passed" << endl;

    Node* p4 = InOrderNodeNextValue(root->rightTree);
    if (p4 != root->rightTree->rightTree->leftTree)
        throw exception("assert failed");
    else
        cout << "p4 passed" << endl;

    Node* p5 = InOrderNodeNextValue(root->rightTree->leftTree);
    if (p5 != root->rightTree)
        throw exception("assert failed");
    else
        cout << "p5 passed" << endl;

    Node* p6 = InOrderNodeNextValue(root->rightTree->rightTree);
    if (p6 != nullptr)
        throw exception("assert failed");
    else
        cout << "p6 passed" << endl;

    Node* p7 = InOrderNodeNextValue(root->rightTree->rightTree->leftTree);
    if (p7 != root->rightTree->rightTree)
        throw exception("assert failed");
    else
        cout << "p7 passed" << endl;
}

/*
        1
      /   \
     2     3
    / \    / \
   4   9  5   6
      / \      
    10   7    
*/
void test1()
{
    int pre[] = { 1, 2, 4, 9, 10, 7, 3, 5, 6 };
    int in[] = { 4, 2, 10, 9, 7, 1, 5, 3, 6 };
    int length = 8;
    Node* root = BuildTree(pre, in, length);

    Node* p0 = InOrderNodeNextValue(root);
    if (p0 != root->rightTree->leftTree)
        throw exception("assert failed");
    else
        cout << "p0 passed" << endl;

    Node* p1 = InOrderNodeNextValue(root->leftTree);
    if (p1 != root->leftTree->rightTree->leftTree)
        throw exception("assert failed");
    else
        cout << "p1 passed" << endl;

    Node* p2 = InOrderNodeNextValue(root->leftTree->leftTree);
    if (p2 != root->leftTree)
        throw exception("assert failed");
    else
        cout << "p2 passed" << endl;

    Node* p3 = InOrderNodeNextValue(root->leftTree->rightTree);
    if (p3 != root->leftTree->rightTree->rightTree)
        throw exception("assert failed");
    else
        cout << "p3 passed" << endl;

    Node* p4 = InOrderNodeNextValue(root->leftTree->rightTree->leftTree);
    if (p4 != root->leftTree->rightTree)
        throw exception("assert failed");
    else
        cout << "p4 passed" << endl;

    Node* p5 = InOrderNodeNextValue(root->leftTree->rightTree->rightTree);
    if (p5 != root)
        throw exception("assert failed");
    else
        cout << "p5 passed" << endl;

    Node* p6 = InOrderNodeNextValue(root->rightTree);
    if (p6 != root->rightTree->rightTree)
        throw exception("assert failed");
    else
        cout << "p6 passed" << endl;

    Node* p7 = InOrderNodeNextValue(root->rightTree->leftTree);
    if (p7 != root->rightTree)
        throw exception("assert failed");
    else
        cout << "p7 passed" << endl;

    Node* p8 = InOrderNodeNextValue(root->rightTree->rightTree);
    if (p8 != nullptr)
        throw exception("assert failed");
    else
        cout << "p8 passed" << endl;
}


int main(int argc, char const argv[])
{
    // test();
    test1();
    return 0;
}

#endif