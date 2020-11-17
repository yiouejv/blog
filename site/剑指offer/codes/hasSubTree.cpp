// hasSubTree.cpp
#include <iostream>
#include <cassert>
using namespace std;

struct Node
{
	double value;
	Node* left = nullptr;
	Node* right = nullptr;
};

bool equal(double num1, double num2)


bool hasSubTree(Node* pRoot1, Node* pRoot2)
{
	bool result = false;

	if (pRoot1 != nullptr && pRoot2 != nullptr)
	{
		if (equal(pRoot1->value, pRoot2->value))
			result = doesTree1HaveTree2(pRoot1, pRoot2)

		if (!result)
			result = hasSubTree(pRoot1->left, pRoot2);

		if (!result)
			result = hasSubTree(pRoot1->right, pRoot2);
	}

	return result;
}


bool doesTree1HaveTree2(Node* pNode1, Node* pNode2)
{
	if (pNode2 == nullptr)
		return true;

	if (pNode1 == nullptr)
		return false;

	if (!equal(pNode1->value, pNode2->value))
		return false

	return doesTree1HaveTree2(pNode1->left, pRoot2->left) && doesTree1HaveTree2(pNode1->right, pRoot2->right)
}

bool equal(double num1, double num2)
{
	if (num1 - num2 > -0.000001 && num1 - num2 < 0.000001)
		return true;
	return false;
}



int main(int argc, char const *argv[])
{
	
	return 0;
}

