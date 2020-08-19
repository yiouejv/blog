//bTreeSumPath.cpp
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


struct Node
{
    int value;
    Node* pLeft = nullptr;
    Node* pRight = nullptr;
};

void findPath(Node* pNode, int expectSum, vector<int> vectorPath, int curSum);

void findPath(Node* pRoot, int expectSum)
{
    if (pRoot == nullptr)
        return;

        vector<int> vectorPath;
    int curSum = 0;
    findPath(pRoot, expectSum, vectorPath, curSum);
}

void findPath(Node* pNode, int expectSum, vector<int> vectorPath, int curSum)
{
    if (pNode == nullptr)
        return;

    vectorPath.push_back(pNode->value);
    curSum += pNode->value;
    // 如果路径上的节点的和等于 expectSum
    // 则打印出路径
    bool isLeaf = pNode->pLeft == nullptr && pNode->pRight == nullptr;
    if (curSum == expectSum && isLeaf)
    {
        vector<int>::iterator iter = vectorPath.begin();
        for (; iter != vectorPath.end(); iter++)
        {
            cout << *iter << ' ';
        }
        cout << endl;
    }

    // 继续查找左右子节点
    findPath(pNode->pLeft, expectSum, vectorPath, curSum);
    findPath(pNode->pRight, expectSum, vectorPath, curSum);

    // 在返回父节点之前，在路径上删除当前节点
    vectorPath.pop_back();
}


void test()
{
    Node* pRoot = new Node;
    pRoot->value = 10;

    Node* pNode5 = new Node;
    pNode5->value = 5;

    Node* pNode4 = new Node;
    pNode4->value = 4;

    Node* pNode7 = new Node;
    pNode7->value = 7;

    Node* pNode12 = new Node;
    pNode12->value = 12;

    pRoot->pLeft = pNode5;
    pRoot->pRight = pNode12;
    pNode5->pLeft = pNode4;
    pNode5->pRight = pNode7;
    findPath(pRoot, 22);
}


int main(int argc, char const* argv[])
{
    test();
    return 0;
}