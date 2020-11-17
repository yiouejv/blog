//treePreOrder.cpp
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

struct Node
{
	int value;
	Node* pLeft = nullptr;
	Node* pRight = nullptr;
};


// ########################################################### 递归解法
void preOrderCore(Node* pNode, vector<int>& vectorResult)
{
	if (pNode == nullptr)
		return;

	vectorResult.push_back(pNode->value);
	if (pNode->pLeft != nullptr)
		preOrderCore(pNode->pLeft, vectorResult);

	if (pNode->pRight != nullptr)
		preOrderCore(pNode->pRight, vectorResult);
}


vector<int> preOrder(Node* pNode)
{
	vector<int> vectorResult;
	if (pNode == nullptr)
		return vectorResult;

	vectorResult.push_back(pNode->value);
	if (pNode->pLeft != nullptr)
		preOrderCore(pNode->pLeft, vectorResult);

	if (pNode->pRight != nullptr)
		preOrderCore(pNode->pRight, vectorResult);

	return vectorResult;
}

// ######################################################## 循环解法
// void preOrderCore2(Node* pRoot, vector<int>& vectorResult)
// {
// 	stack<Node*> vectorNode;

// 	if (pRoot == nullptr)
// 		return;

// 	vectorResult.push_back(pRoot->value);
// 	vectorNode.push(pRoot);

// 	while (vectorNode.size() > 0)
// 	{
// 		Node* pNode = vectorNode.top();
// 		vectorNode.pop();

// 		if (pNode->pLeft != nullptr)
// 		{
// 			vectorResult.push_back(pNode->value);
// 			vectorNode.push(pNode->pLeft);
// 		}

// 		if (pNode->pRight != nullptr)
// 		{
// 			vectorResult.push_back(pNode->value);
// 			vectorNode.push(pNode->pRight);
// 		}
// 	}
// }

// vector<int> preOrder2(Node* pRoot)
// {
// 	vector<int> vectorResult;

// 	if (pRoot == nullptr)
// 		return vectorResult;

// 	vectorResult.push_back(pRoot->value);

// 	if (pRoot->pLeft != nullptr)
// 		preOrderCore2(pRoot->pLeft, vectorResult);

// 	if (pRoot->pRight != nullptr)
// 		preOrderCore2(pRoot->pRight, vectorResult);

// 	return vectorResult;
// }



void test(const char* testName, Node* pRoot, vector<int> &expect)
{
	vector<int> result = preOrder2(pRoot);
	assert(result == expect);
	cout << testName << " passed" << endl;
}

//
//            8
//          /   \
//         6     10
//       /   \  /  \
//      5     7 9   11 
// 
//  expect: 8 6 5 7 10 9 11
void test1()
{
	Node* root = new Node;
    root->value = 8;

    Node* node6 = new Node;
    node6->value = 6;
    root->pLeft = node6;

    Node* node10 = new Node;
    node10->value = 10;
    root->pRight = node10;

    Node* node5 = new Node;
    node5->value = 5;
    node6->pLeft = node5;

    Node* node7 = new Node;
    node7->value = 7;
    node6->pRight = node7;

    Node* node9 = new Node;
    node9->value = 9;
    node10->pLeft = node9;

    Node* node11 = new Node;
    node11->value = 11;
    node10->pRight = node11;
    vector<int> result = preOrder(root);

    vector<int> expect;
    expect.push_back(8);
    expect.push_back(6);
    expect.push_back(5);
    expect.push_back(7);
    expect.push_back(10);
    expect.push_back(9);
    expect.push_back(11);

    test("test1", root, expect);
}


/*
				8
		       / \ 
              3   2

  	expect: 8 3 2
*/
void test2()
{
	Node* root = new Node;
    root->value = 8;

    Node* node3 = new Node;
    node3->value = 3;
    root->pLeft = node3;

    Node* node2 = new Node;
    node2->value = 2;
    root->pRight = node2;

    vector<int> result = preOrder(root);

    vector<int> expect;
    expect.push_back(8);
    expect.push_back(3);
    expect.push_back(2);
    test("test2", root, expect);
}

/*
				8
		      
  	expect: 8
*/
void test3()
{
	Node* root = new Node;
    root->value = 8;

    vector<int> result = preOrder(root);

    vector<int> expect;
    expect.push_back(8);
    test("test3", root, expect);
}

/*
  	空指针
*/
void test4()
{
	Node* root = nullptr;

    vector<int> result = preOrder(root);

    vector<int> expect;
    test("test4", root, expect);
}

int main(int argc, char const *argv[])
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}