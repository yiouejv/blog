#include <iostream>
#include <exception>
using namespace std;

struct Node
{
    int value;
    Node* leftTree;
    Node* rightTree;
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
    }
    if (endIn - rootValueIn > 0)
    {
        root->rightTree = BuildCore(startPre + startInLength + 1, endPre,
            rootValueIn + 1, endIn);
    }
    return root;
}

Node* BuildTree(int* pre, int* in, int length)
{
    if (pre == nullptr || in == nullptr || length <= 0)
        return nullptr;
    return BuildCore(pre, pre + length - 1, in, in + length - 1);
}

/*
    空指针
*/
void test()
{
    int* pre = nullptr;
    int* in = nullptr;
    int length = 0;
    Node* root = BuildTree(pre, in, length);
    if (root != nullptr)
        throw exception("assert failed");
    else
        cout << "test passed";
}

/*
    普通二叉树
        1
      /   \ 
     2     3
    /     / \
   4     5   6
    \       /  
     7     8
*/
void test1()
{
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    int length = 8;
    Node* root = BuildTree(pre, in, length);
}

/*
    只有一个节点的二叉树
            1
*/
void test2()
{
    int pre[] = { 1 };
    int in[] = { 1 };
    int length = 1;
    Node* root = BuildTree(pre, in, length);
}

/*
    只有右子节点的树
            1
             \
              2
               \
                3
                 \
                  4
*/
void test3()
{
    int pre[] = { 1, 2, 3, 4 };
    int in[] = { 4, 3, 2, 1 };
    int length = 4;
    Node* root = BuildTree(pre, in, length);
}

/*
    只有左子节点的树
            1
           /
          2
         /
        3
       /
      4
*/
void test4()
{
    int pre[] = { 1, 2, 3, 4 };
    int in[] = { 4, 3, 2, 1 };
    int length = 4;
    Node* root = BuildTree(pre, in, length);
}

/*
    输入的遍历序列不匹配
        1
      /   \
     2     3
    /     / \
   4     5   6
    \       /
     7     8
*/
void test5()
{
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int in[] = { 4, 7, 2, 1, 3, 3, 8, 6 };
    int length = 8;
    Node* root = BuildTree(pre, in, length);
}

int main(int argc, const char* argv[])
{
    test();
    test1();
    test2();
    test3();
    test4();
    //test5();  // 抛出异常
    return 0;
}

