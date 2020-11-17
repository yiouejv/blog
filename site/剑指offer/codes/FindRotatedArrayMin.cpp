#include <iostream>
#include <cassert>
using namespace std;

int FindRotatedArrayMin(int* arr, const int length)
{
    if (arr == nullptr)
        throw "Invaild Params";

    int left = 0;
    int right = length - 1;
    int mid = length / 2;

    while (left < right)
    {
        if (arr[mid] > arr[right])
            left = mid + 1;
        else if (arr[right] == arr[mid])
            right--;
        else
            right = mid;

        mid = left + (right - left) / 2;
    }
    return arr[left];
}

void test()
{
    // 正常无重复数字
    int arr1[] = { 2, 3, 4, 5, 1 };
    int arr2[] = { 3, 4, 5, 1, 2 };
    int arr3[] = { 4, 5, 1, 2, 3 };
    int arr4[] = { 5, 1, 2, 3, 4 };
    int arr5[] = { 1, 2, 3, 4, 5 };
    assert(FindRotatedArrayMin(arr1, 5) == 1);
    assert(FindRotatedArrayMin(arr2, 5) == 1);
    assert(FindRotatedArrayMin(arr3, 5) == 1);
    assert(FindRotatedArrayMin(arr4, 5) == 1);
    assert(FindRotatedArrayMin(arr5, 5) == 1);

    // 只有一个元素
    int arr6[] = { 0 };
    assert(FindRotatedArrayMin(arr6, 1) == 0);

    // 两个元素
    int arr7[] = { 0, 1 };
    assert(FindRotatedArrayMin(arr7, 2) == 0);

    // 两个相同的元素
    int arr8[] = { 1, 1 };
    assert(FindRotatedArrayMin(arr8, 2) == 1);

    // 重复元素不为最小元素
    int arr9[] = { 2, 0, 1, 1, 2 };
    assert(FindRotatedArrayMin(arr9, 5) == 0);

    // 重复元素是最小元素
    int arr10[] = { 2, 0, 0, 1, 2 };
    assert(FindRotatedArrayMin(arr10, 5) == 0);
}


int main(int argc, char const argv[])
{
    test();
    return 0;
}