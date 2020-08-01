#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool hasPathCore(char* matrix, string& str, size_t strIndex, const int row, const int col, int r, int c, bool* boolMatrix);


bool hasPath(string& str, char* matrix, const int row, const int col)
{
    bool result = false;

    if (matrix == nullptr)
        return false;

    if (str == "")
        return true;

    // bool值矩阵，用来判断某个字符是否被路径包含
    bool* boolMatrix = new bool[row * col];
    memset(boolMatrix, true, row * col);

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
            if (hasPathCore(matrix, str, 0, row, col, r, c, boolMatrix))
            {
                result = true;
                break;
            }
            else
                continue;
    }

    delete[] boolMatrix;
    return result;
}

bool hasPathCore(char* matrix, string& str, size_t strIndex, const int row, const int col, int r, int c, bool* boolMatrix)
{

    if (str[strIndex] == '\0')
        return true;

    bool hasPath = false;

    if (r >= 0 && r < row && c >= 0 && c < col
        && matrix[r * col + c] == str[strIndex]
        && boolMatrix[r * col + c] )
    {
        boolMatrix[r * col + c] = false;
        strIndex++;

        hasPath = (
            hasPathCore(matrix, str, strIndex, row, col, r - 1, c, boolMatrix) ||
            hasPathCore(matrix, str, strIndex, row, col, r, c + 1, boolMatrix) ||
            hasPathCore(matrix, str, strIndex, row, col, r + 1, c, boolMatrix) ||
            hasPathCore(matrix, str, strIndex, row, col, r, c - 1, boolMatrix)
        );

        if (!hasPath)
        {
            strIndex--;
            boolMatrix[r * col + c] = true;
        }
    }
    return hasPath;
}

/*
    a b e g
    c f c s
    j d e h

    bfce true
    abfb false
    bfde true
*/
void test1()
{
    string str("bfce");
    string str2("abfb");
    string str3("bfde");
    const int row = 3;
    const int col = 4;
    char matrix[row * col] = { 'a', 'b', 't', 'g', 'c', 'f', 'c', 's', 'j', 'd', 'e', 'h' };

    assert(hasPath(str, matrix, row, col) == true);
    assert(hasPath(str2, matrix, row, col) == false);
    assert(hasPath(str3, matrix, row, col) == true);
}


/*
    空指针
*/
void test2()
{
    string str("bfce");
    string str2("abfb");
    string str3("bfde");
    const int row = 3;
    const int col = 4;
    char* matrix = nullptr;

    assert(hasPath(str, matrix, row, col) == false);
    assert(hasPath(str2, matrix, row, col) == false);
    assert(hasPath(str3, matrix, row, col) == false);
}

/*
    a

    a true
    b false
    ab false
*/
void test3()
{
    string str("a");
    string str2("b");
    string str3("ab");
    const int row = 1;
    const int col = 1;
    char matrix[row * col] = { 'a' };

    assert(hasPath(str, matrix, row, col) == true);
    assert(hasPath(str2, matrix, row, col) == false);
    assert(hasPath(str3, matrix, row, col) == false);
}

/*
    a b

    a true
    ab true
    abc false
    b true
*/
void test4()
{
    string str("a");
    string str2("b");
    string str3("abc");
    string str4("ab");
    const int row = 1;
    const int col = 2;
    char matrix[row * col] = { 'a', 'b' };

    assert(hasPath(str, matrix, row, col) == true);
    assert(hasPath(str2, matrix, row, col) == true);
    assert(hasPath(str3, matrix, row, col) == false);
    assert(hasPath(str4, matrix, row, col) == true);
}

/*
    a b 
    c f

    ab true
    bf true
    cf true
    ac true
    abf true
    abfc true
    abfd false
*/
void test5()
{
    string str("ab");
    string str2("bf");
    string str3("cf");
    string str4("ac");
    string str5("abf");
    string str6("abfc");
    string str7("abfd");
    const int row = 2;
    const int col = 2;
    char matrix[row * col] = { 'a', 'b', 'c', 'f' };

    assert(hasPath(str, matrix, row, col) == true);
    assert(hasPath(str2, matrix, row, col) == true);
    assert(hasPath(str3, matrix, row, col) == true);
    assert(hasPath(str4, matrix, row, col) == true);
    assert(hasPath(str5, matrix, row, col) == true);
    assert(hasPath(str6, matrix, row, col) == true);
    assert(hasPath(str7, matrix, row, col) == false);
}

/*
    a a a a a
    a a a a a
  
    aa true
    aaa true
    aaaa true
    aaaaa true
    aaaaaa true
    aaaaaaaaaa true
*/
void test6()
{
    string str("a");
    string str2("aa");
    string str3("aaa");
    string str4("aaaa");
    string str5("aaaaa");
    string str6("aaaaaaaaaa");
    const int row = 2;
    const int col = 5;
    char matrix[row * col] = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };

    assert(hasPath(str, matrix, row, col) == true);
    assert(hasPath(str2, matrix, row, col) == true);
    assert(hasPath(str3, matrix, row, col) == true);
    assert(hasPath(str4, matrix, row, col) == true);
    assert(hasPath(str5, matrix, row, col) == true);
    assert(hasPath(str6, matrix, row, col) == true);
}

int main(int argc, char const* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
