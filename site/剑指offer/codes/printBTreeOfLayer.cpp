// printBTreeOfLayer.cpp
#include <iostream>
#include <cassert>
#include <queue>
#include <vector>
using namespace std;


struct Node
{
    int value;
    Node* pLeft = nullptr;
    Node* pRight = nullptr;
};


vector<int> printBTreeOfLayer(Node* pRoot)
{
    vector<int> vectorResult;
    if (pRoot == nullptr)
        return vectorResult;

    queue<Node*> queueNodes;
    queueNodes.push(pRoot);
    vectorResult.push_back(pRoot->value);

    Node* node = nullptr;
    while (queueNodes.size() > 0)
    {
        node = queueNodes.front();
        queueNodes.pop();
        if (node->pLeft != nullptr)
        {
            queueNodes.push(node->pLeft);
            vectorResult.push_back(node->pLeft->value);
        }

        if (node->pRight != nullptr)
        {
            queueNodes.push(node->pRight);
            vectorResult.push_back(node->pRight->value);
        }
    }
    return vectorResult;
}


void test(const char* testName, Node* pRoot, vector<int> expect)
{
    assert(printBTreeOfLayer(pRoot) == expect);
    cout << testName << " passed" << endl;
}



/*
                8
            /       \
           6         10
          / \        / \
         5   7      9   11
*/
void test1()
{
    Node* pRoot = new Node;
    pRoot->value = 8;

    Node* pNode6 = new Node;
    pNode6->value = 6;

    Node* pNode10 = new Node;
    pNode10->value = 10;

    Node* pNode5 = new Node;
    pNode5->value = 5;

    Node* pNode7 = new Node;
    pNode7->value = 7;

    Node* pNode9 = new Node;
    pNode9->value = 9;

    Node* pNode11 = new Node;
    pNode11->value = 11;


    pRoot->pLeft = pNode6;
    pRoot->pRight = pNode10;

    pNode6->pLeft = pNode5;
    pNode6->pRight = pNode7;

    pNode10->pLeft = pNode9;
    pNode10->pRight = pNode11;

    vector<int> expect;
    expect.push_back(8);
    expect.push_back(6);
    expect.push_back(10);
    expect.push_back(5);
    expect.push_back(7);
    expect.push_back(9);
    expect.push_back(11);
    test("test1", pRoot, expect);
}


/*
             8
            / 
           6  
          /  
         5  
*/
void test2()
{
    Node* pRoot = new Node;
    pRoot->value = 8;

    Node* pNode6 = new Node;
    pNode6->value = 6;

    Node* pNode5 = new Node;
    pNode5->value = 5;

    pRoot->pLeft = pNode6;

    pNode6->pLeft = pNode5;

    vector<int> expect;
    expect.push_back(8);
    expect.push_back(6);
    expect.push_back(5);
    test("test2", pRoot, expect);
}


/*
                8
                 \
                  10
                   \
                    11
*/
void test3()
{
    Node* pRoot = new Node;
    pRoot->value = 8;

    Node* pNode10 = new Node;
    pNode10->value = 10;

    Node* pNode11 = new Node;
    pNode11->value = 11;

    pRoot->pRight = pNode10;

    pNode10->pRight = pNode11;

    vector<int> expect;
    expect.push_back(8);
    expect.push_back(10);
    expect.push_back(11);
    test("test3", pRoot, expect);
}

int main(int argc, char const* argv[])
{
    test1();
    test2();
    test3();
    return 0;
}