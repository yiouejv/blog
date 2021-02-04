// isPopOrder.cpp
#include <iostream>
#include <stack>
#include <cassert>
#include <vector>
using namespace std;

bool isPopOrder(vector<int>& pushVector, vector<int>& popVector)
{
    if (pushVector.size() <= 0 || popVector.size() <= 0)
        return false;

    stack<int> stackTemp;
    unsigned int pushVectorIndex = 0;
    unsigned int popVectorIndex = 0;

    stackTemp.push(pushVector[pushVectorIndex++]);

    while (popVectorIndex < popVector.size())
    {
        while (stackTemp.top() != popVector[popVectorIndex])
        {
            if (pushVectorIndex >= pushVector.size())
                break;
            stackTemp.push(pushVector[pushVectorIndex++]);
        }

        if (stackTemp.top() != popVector[popVectorIndex])
            break;

        stackTemp.pop();
        popVectorIndex++;
    }
    if (stackTemp.empty())
        return true;
    return false;
}


void test(const char* testName, vector<int>& pushVector, vector<int>& popVector)
{
    assert(isPopOrder(pushVector, popVector));
    cout << testName << " passed" << endl;
}

void test1()
{
    vector<int> pushVector;
    pushVector.push_back(1);
    pushVector.push_back(2);
    pushVector.push_back(3);
    pushVector.push_back(4);
    pushVector.push_back(5);

    vector<int> popVector;
    popVector.push_back(4);
    popVector.push_back(5);
    popVector.push_back(3);
    popVector.push_back(2);
    popVector.push_back(1);
    test("test1", pushVector, popVector);
}

void test2()
{
    vector<int> pushVector;
    pushVector.push_back(1);
    pushVector.push_back(2);
    pushVector.push_back(3);
    pushVector.push_back(4);
    pushVector.push_back(5);

    vector<int> popVector;
    popVector.push_back(4);
    popVector.push_back(3);
    popVector.push_back(5);
    popVector.push_back(1);
    popVector.push_back(2);
    test("test2", pushVector, popVector);
}


int main(int argc, char const* argv[])
{
    test1();
    //test2();
    return 0;
}