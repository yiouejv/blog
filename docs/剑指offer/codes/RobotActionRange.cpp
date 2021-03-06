#include <iostream>
#include <cassert>
using namespace std;

bool pointLessK(int r, int c, int k)
{
    if(r < 0 || c < 0)
        return false;

    if(k < 0)
        return true;

    while(r > 0)
    {
        k -= (r % 10);
        r /= 10;
    }
    if (k < 0)
        return false;

    while(c > 0)
    {
        k -= (c % 10);
        c /= 10;
    }

    if (k < 0)
        return false;
    return true;
}

int RobotActionRangeCore(int k, int* matrix, int row, int col, int r, int c, int* visited)
{
    static int count = 0;

    if (r >= 0 && r < row && c >= 0 && c < col
        && visited[r*col + c] == 0 && pointLessK(r, c, k)
    )
    {
        count ++;
        visited[r*col + c] = 1;

        // 上下左右四个方向能走到则一直递归
        RobotActionRangeCore(k, matrix, row, col, r - 1, c, visited);
        RobotActionRangeCore(k, matrix, row, col, r, c + 1, visited);
        RobotActionRangeCore(k, matrix, row, col, r - 1, c, visited);
        RobotActionRangeCore(k, matrix, row, col, r, c - 1, visited);
    }
    return count;
}

int getRobotActionRange(int k, int* matrix, int row, int col)
{
    if(matrix == nullptr || row < 1 || col < 1 || r < 0 || c < 0)
        return nullptr;

    int* visited = new matrix[row * col];
    memset(visited, 0, row*col);
    int count = RobotActionRangeCore(k, matrix, row, col, 0, 0, visited);
    delete[] visited;
    return count
}


// 测试pointLessK
void testPointLessK()
{
    assert(pointLessK(0, 0, 0) == true);
    assert(pointLessK(0, 1, 1) == true);
    assert(pointLessK(1, 0, 1) == true);
    assert(pointLessK(2, 2, 5) == true);
    assert(pointLessK(2, 2, 3) == false);
    assert(pointLessK(20, 2, 5) == true);
    assert(pointLessK(20, 2, 3) == false);
}


/*
    空指针测试
*/
void test1()
{
    const int k = 0;
    const int row = 0;
    const int col = 0;
    int matrix = nullptr;
    assert(getRobotActionRange(k, matrix, row, col) == nullptr);
}


/*
    矩阵只有一个元素
*/
void test2()
{
    const int row = 1;
    const int col = 1;
    int matrix[row*col] = {0};

    const int k1 = 0;
    assert(getRobotActionRange(k1, matrix, row, col) == 1);
    const int k2 = 1;
    assert(getRobotActionRange(k2, matrix, row, col) == 0);
}


/*
    矩阵有两个元素
*/
void test3()
{
    // 两行一列
    const int row = 2;
    const int col = 1;
    int matrix[row*col] = {0};

    const int k1 = 0;
    assert(getRobotActionRange(k1, matrix, row, col) == 2);
    const int k2 = 1;
    assert(getRobotActionRange(k2, matrix, row, col) == 2);

    // 一行两列
    const int row = 1;
    const int col = 2;
    int matrix2[row*col] = {0};

    const int k3 = 0;
    assert(getRobotActionRange(k3, matrix2, row, col) == 2);
    const int k4 = 1;
    assert(getRobotActionRange(k4, matrix2, row, col) == 2);
}


/*
    矩阵有12个元素，矩阵下标位数为一位
*/
void test4()
{
    const int row = 3;
    const int col = 4;
    int matrix[row*col] = {0};

    const int k1 = 1;
    assert(getRobotActionRange(k1, matrix, row, col) == 3);
    const int k2 = 5;
    assert(getRobotActionRange(k2, matrix, row, col) == 12);
}

/*
    矩阵有1000个元素，矩阵下标位数大于1位
*/
void test5()
{
    const int row = 20;
    const int col = 50;
    int matrix[row*col] = {0};

    const int k1 = 1;
    assert(getRobotActionRange(k1, matrix, row, col) == 3);
    const int k2 = 20;
    cout << getRobotActionRange(k2, matrix, row, col) << endl;
}




int main(int argc, char const argv[])
{
    testPointLessK();
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    return 0;
}