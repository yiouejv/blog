#include <iostream>
#include <cstring>
using namespace std;


class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator=(const CMyString& str);
	void print();

private:
	char* m_pData;
};

CMyString::CMyString(char* pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		this->m_pData = new char[length + 1];
		memcpy(this->m_pData, pData, length+1);
	}
}

CMyString::CMyString(const CMyString& str)
{
	int length = strlen(str.m_pData) + 1;
	this->m_pData = new char[length + 1];
	memcpy(this->m_pData, str.m_pData, length+1);
}

CMyString::~CMyString()
{
	delete[] this->m_pData;
}

void CMyString::print()
{
	for (int i = 0; i < strlen(m_pData); i++)
	{
		cout << m_pData[i] << ' ';
	}
	cout << endl;
}


CMyString& CMyString::operator =(const CMyString& str)
{
	if (this != &str)
	{
		CMyString strTemp(str);
		char* temp = strTemp.m_pData;
		strTemp.m_pData = this->m_pData;
		this->m_pData = temp;
	}
	return *this;
}


char str[] = "123";
void test_init();
void test_copy_init();
void test_opertor_equip();

int main(int argc, char const *argv[])
{
	
	test_init();
	test_copy_init();
	test_opertor_equip();
	return 0;
}

// 测试构造函数
void test_init()
{
	CMyString s1(str);
	s1.print();
}

// 测试复制构造函数
void test_copy_init()
{
	CMyString s1(str);
	CMyString s2(s1);
	s2.print();
}

// 测试操作运算符 =
void test_opertor_equip()
{
	CMyString s1(str);
	CMyString s2, s3;
	s2 = s3 = s1;
	s2.print();
	s3.print();
}