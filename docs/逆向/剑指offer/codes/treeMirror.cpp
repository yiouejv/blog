//treeMirror.cpp
#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};


// #############################  解法1： 递归
void exchangeChild(Node* pNode);

void treeMirror(Node* pRoot)
{
    if (pRoot == nullptr)
        return;

    exchangeChild(pRoot);
}

void exchangeChild(Node* pNode)
{
    if (pNode == nullptr)
        return;

    Node* left = pNode->left;
    Node* right = pNode->right;

    pNode->left = right;
    pNode->right = left;
    exchangeChild(pNode->left);
    exchangeChild(pNode->right);
}

// #############################  解法2： 循环
void exchangeChild2(Node* pNode)
{
    stack<Node*> stackTreeNode;
    stackTreeNode.push(pNode);

    while (stackTreeNode.size() > 0)
    {
        pNode = stackTreeNode.top();
        stackTreeNode.pop();

        Node* tempNode = pNode->left;
        pNode->left = pNode->right;
        pNode->right = tempNode;        

        if (pNode->left)
            stackTreeNode.push(pNode->left);

        if (pNode->right)
            stackTreeNode.push(pNode->right);
    }
}

void treeMirror2(Node* pRoot)
{
    if (pRoot == nullptr)
        return;

    Node* tempNode = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tempNode;

    if (pRoot->left)
        exchangeChild2(pRoot->left);

    if (pRoot->right)
        exchangeChild2(pRoot->right);
}



void test()
{
    Node* root = new Node;
    root->value = 8;

    Node* node6 = new Node;
    node6->value = 6;
    root->left = node6;

    Node* node10 = new Node;
    node10->value = 10;
    root->right = node10;

    Node* node5 = new Node;
    node5->value = 5;
    node6->left = node5;

    Node* node7 = new Node;
    node7->value = 7;
    node6->right = node7;

    Node* node9 = new Node;
    node9->value = 9;
    node10->left = node9;

    Node* node11 = new Node;
    node11->value = 11;
    node10->right = node11;
    // treeMirror(root);
    treeMirror2(root);
}


int main(int argc, char const* argv[])
{
    test();
    return 0;
}