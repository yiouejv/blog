

### string 的构造函数

```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string str;
	cout << str << ' ' << str.empty() << endl;

	// string(size_type length, char ch)
	// 源码: typedef size_t size_type;  unsign int
	string str1(5, 'a');
	cout << str1 << ' ' << str1.empty() << endl;

	// string(const char* str)
	string str2("abcdefg");
	cout << str2 << ' ' << str2.empty() << endl;

	// string(const char* str, size_type length)
	string str3("abcdefg", 2);
	cout << str3 << ' ' << str3.empty() << endl;

	// string(const char* str, size_type index, size_type length)
	string str4("abcdefg", 2, 5);
	cout << str4 << ' ' << str4.empty() << endl;

	// sting(const sting& str)
	string str5(str4);
	cout << str5 << ' ' << str5.empty() << endl;
	return 0;
}
```

### string 对象属性

#### 容量 capacity()

和编译器有关系

- 如果声明字符串的字符少于15个，则容量为15
- 每次溢出则多申请16个字符空间。

#### 修改容量 reserve()

- 只能使容量变大，不能变小

```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string str;							
	cout << str.capacity() << endl;     // 15
	str.reserve(15);
	cout << str.capacity() << endl;     // 15
	str.reserve(16);
	cout << str.capacity() << endl;     // 31
	str.reserve(20);
	cout << str.capacity() << endl;     // 31
	str.reserve(32);
	cout << str.capacity() << endl;     // 47

	return 0;
}
```

- 小于等于 15, 则不变，多余15，则按溢出处理
 
总结: 调用之后，15-31-47-63 ...

#### 长度 length(), 字符个数 size() 

#### resize()

重新设置字符个数

```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string str("abcdefg");
	cout << "str: " << str << ' '
	     << "length: " << str.length() << ' '
		<< "size: " << str.size() << ' '
		<< "capacity: " << str.capacity() << endl;

	str.resize(3);
	cout << "str: " << str << ' '
		<< "length: " << str.length() << ' '
		<< "size: " << str.size() << ' '
		<< "capacity: " << str.capacity() << endl;
	return 0;
}
```

输出
```
str: abcdefg length: 7 size: 7 capacity: 15
str: abc length: 3 size: 3 capacity: 15
```

### string 查询

输出整个字符串

```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string str("abcdefg");
	cout << str << endl;
	cout << str.c_str() << endl;
	return 0;
}
```

输出单个字符

```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string str("abcdefg");
	cout << str[0] << endl;
	cout << str[1] << endl;
	cout << str.at(2) << endl;
	return 0;
}
```

### string 修改

修改指定元素

```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string str("abcdefg");
	str[0] = 's';
	cout << str << endl;

	str.at(1) = 'm';
	cout << str << endl;
	return 0;
}
```

insert()
```c++
basic_string & insert(size_type index, const basic_string &str);  // index 位置插入str
basic_string & insert(size_type index, const char *str);          // index 位置插入字符串
basic_string & insert(size_type index1, const basic_string &str, size_type index2, size_type num);
basic_string & insert(size_type index, const char *str, size_type num);          // 插入前几个
basic_string & insert(size_type index, size_type num, charch);          // 插入n个ch
```

append()
```c++
basic_string & append(const basic_string &str);  // 尾巴通过一个对象拼接
basic_string & append(const char *str);          // 尾巴通过一个字符串拼接
basic_string & append(const basic_string &str, size_type index, size_type len);          // 尾巴通过一个字符串字符串对象的某一段拼接
basic_string & append(const char *str, size_type num);          // 拼接字符串前几个
basic_string & append(size_type num, char ch);          // 拼接num个字符
```

### string 重新赋值

= 赋值， string对象或字符串

\>\> 输入

assign()
```c++
basic_string& assign(const basic_string &str);  // 以str赋值
basic_string& assign(const char *str);  // 以字符串赋值
basic_string& assign(const basic_string &str, size_type index, size_type len);  // 以str赋值
basic_string& assign(const char *str, size_type num);  // 字符串前几个赋值
basic_string& assign(size_type num, char ch);  // num个ch赋值
```

### string 删除

```c++
basic_string &erase(size_type index=0, size_type num=npos);  // 删除指定位置开始指定个数
```

### string 比较

```c++
a < b return 1, a == b return 0, a > b return -1
int compare(const basic_string& str);  // 比较两个对象
int compare(const char* str);  // 比较一个对象和字符串
int compare(size_type index, size_type length, const basic_string& str);  // 本对象的一段，跟参数3的对象进行比较
int compare(size_type index, size_type length, const basic_string& str, size_type index2, size_type length2);
```

### string 复制

```c++
size_type copy(char* str, size_type num, size_type index)  // 将对象中的某一段复制进一个字符数组中
```

### string 查找子串

```c++
size_type find(const basic_string& str, size_type index);  // 从指定位置开始查找str
size_type find(const char* str, size_type index);  // 指定位置查找字符串
size_type find(const char* str, size_type index, size_type length);  // 指定段查找str
size_type find(char ch, size_type index);  // 指定位置查找字符
```

### string 返回子串

```c++
substr(size_type index, size_type num=npos);  // 返回指定位置的子串
```

### string 交换

```c++
swap(basic_string& str);  // 交换两个对象的内容
```

### string 的迭代器

```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string str("abcdefg");
	string::iterator iter = str.begin();
	// 迭代器迭代
	for (iter; iter < str.end(); iter++)
	{
		cout << *iter << ' ';
	}

	cout << endl;
	// char * 迭代
	for (size_t i = 0; i < str.length(); i++)
	{
		cout << str[i] << ' ';
	}
	return 0;
}
```
说明：

- str.begin() 返回字符串首地址的迭代器
- str.end()  返回字符串尾地址的迭代器

由以上代码可知，iter相当于char* 类型的指针
!!!question
	为什么还要用迭代器，而不直接用char* 指针？

!!!answer
	迭代器是要和算法进行链接的，它适用于所有的迭代器，即一个通用类型的指针，或者是智能指针。

迭代器失效

```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string str("abcdefg");
	string::iterator iter = str.begin();
	cout << iter[2] << endl;

	str.append(18, 'a');
	//cout << iter[2] << endl;  // 报错，迭代器失效

	iter = str.begin();
	cout << iter[2] << endl;

	return 0;
}
```

**string 重新申请空间的时候，迭代器就会失效，需要重新指定一下**

### for_each()

```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void func(char c)
{
	cout << c << ' ';
}

int main(int argc, const char* argv[])
{
	string str("abcdefg");
	for_each(str.begin(), str.end(), func);
	return 0;
}
```
for_each 函数属于STL算法里的函数

### sort()

```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void func(char c)
{
	cout << c << ' ';
}

int main(int argc, const char* argv[])
{
	string str("adaszxwesdfas");
	sort(str.begin(), str.end());
	for_each(str.begin(), str.end(), func);

	cout << endl;
	sort(str.begin(), str.end(), greater<char>());
	for_each(str.begin(), str.end(), func);
	return 0;
}
```

其中 greater 为仿函数