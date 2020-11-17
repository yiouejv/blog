//symmetricTree.cpp
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* pLeft;
    Node* pRight;
};

bool isSymmetric(Node* pRoot1, Node* pRoot2)

bool isSymmetric(Node* pRoot)
{
    return isSymmetric(pRoot->pLeft, pRoot->pRight);
}

bool isSymmetric(Node* pRoot1, Node* pRoot2)
{
    if (pRoot1 == nullptr || pRoot2 == nullptr)
        return false;

    if (pRoot1->value != pRoot2->value)
        return false;

    if (pRoot1 == nullptr && pRoot2 == nullptr)
        return true;

    return isSymmetric(pRoot1->pLeft, pRoot2->pRight)
        && isSymmetric(pRoot1->pRight, pRoot2->pLeft);
}


int main(int argc, char const *argv[])
{
    
    return 0;
}