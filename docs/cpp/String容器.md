

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