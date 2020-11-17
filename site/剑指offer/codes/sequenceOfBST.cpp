//sequenceOfBST.cpp
#include <iostream>
#include <cassert>
using namespace std;


bool isSequenceOfBST(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
		return false;

	int root = sequence[length - 1];
	int i = 0;

	for (; i < length - 1; ++i)
	{
		if (sequence[i] > root)
			break;
	}

	int j = i + 1;
	for (; j < length - 1; ++j)
	{
		if (sequence[j] < root)
			return false;
	}

	bool left = true;
	if (i > 0)
		return isSequenceOfBST(sequence, i);

	bool right = true;
	if (i < length - 1)
		return isSequenceOfBST(sequence + i, length - i - 1);

	return left && right;
}



int main(int argc, char const *argv[])
{
	return 0;
}