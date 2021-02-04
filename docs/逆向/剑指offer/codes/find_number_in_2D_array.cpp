#include <iostream>
using namespace std;

bool find_number_in_2D_array(int *nums, int row, int col, int target)
{
	#if 0  // 解法二
	int target_c = 0;  // target元素所在列
	for (int r = 0; r < row; r++)
	{
		if (target_c < 1)
		{
			for (int c = 0; c < col; c++)
			{
				int value = nums[r * col + c];
				if (value == target)
				{
					return true;
				}
				if (value > target)
				{
					target_c = c - 1;
					break;
				}
			}
		}
		else
		{
			if (nums[r*col + target_c] == target)
			{
				return true;
			}
		}
	}
	#endif

	// 解法三
	int r = 0,
		c = col - 1;

	while (nums != nullptr && r >= 0 && c >= 0)
	{
		int value = nums[r * col + c];
		if (value > target)
		{
			c -= 1;
		}
		else if (value < target)
			r += 1;
		else
			return true;
	}
	return false;
}

void test(int *nums, int row, int col, int target, bool result)
{
	bool res = find_number_in_2D_array(nums, row, col, target);
	if (res != result)
	{
		throw "assert failed";
	}
}

/*
	1, 2, 8,  9,
	2, 4, 9,  12,
	4, 7, 10, 13,
	6, 8, 11, 15
*/
void test1()
{
	const int row = 4,
	   		  col = 4;
	int nums[row][col] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	//test((int *)nums, row, col, 7, true);
	test((int *)nums, row, col, 5, false);
}


/*
	1
*/
void test2()
{
	const int row = 1,
			  col = 1;
	int nums[row][col] = { 1 };
	test((int*)nums, row, col, 1, true);
	test((int*)nums, row, col, 2, false);
}

/*
	1, 2,
	3, 4,
*/
void test3()
{
	const int row = 2,
		col = 2;
	int nums[row][col] = { 1, 2, 3, 4 };
	test((int*)nums, row, col, 1, true);
	test((int*)nums, row, col, 2, true);
	test((int*)nums, row, col, 5, false);
}

/*
	nullptr
*/
void test4()
{
	const int row = 0,
		col = 0;
	int *nums = nullptr;
	test((int*)nums, row, col, 1, false);
	test((int*)nums, row, col, 2, false);
	test((int*)nums, row, col, 5, false);
}

int main(int argc, const char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}