
### vector对象

向量(动态数组)，内存分配原理和string一样，是连续空间，空间不够用，会申请一个更大的空间，迭代器会失效

```c++
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char argv[])
{

    vector<int> vec;
    return 0;
}
```

### vector 构造函数

```c++
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const argv[])
{
    vector<int> vec;
    vector<int> vec1(5);
    for (int i = 0; i < 5; ++i)
    {
        cout << vec1[i] << ' ';
    }
    cout << endl;

    vector<int> vec2(5, 2); // 5 个2
    for (int i = 0; i < 5; ++i)
    {
        cout << vec2[i] << ' ';
    }
    cout << endl;

    vector<int> vec3(vec2);
    for (int i = 0; i < 5; ++i)
    {
        cout << vec3[i] << ' ';
    }
    cout << endl;

    vector<int> vec4(vec2.begin(), vec2.begin()+3);
    for (int i = 0; i < 3; ++i)
    {
        cout << vec4[i] << ' ';
    }
    cout << endl;
    return 0;
}
```

### vector 容量



```c++
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const argv[])
{
    vector<int> vec(0);
    cout << vec.capacity() << endl;

    vector<int> vec1(5);
    cout << vec1.capacity() << endl;
    return 0;
}
```

**总结： vector的初始容量和初始化时的容量一致。**

```c++
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const argv[])
{
    vector<int> vec(3);
    cout << vec.capacity() << endl;

    vec.push_back(1);                  // 空间增加： 3 + 3 / 2 = 4;
    cout << vec.capacity() << endl;

    vec.push_back(1);                  // 空间增加： 4 + 4 / 2 = 6;
    vec.push_back(1);
    cout << vec.capacity() << endl;

    vec.push_back(1);                  // 空间增加： 6 + 6 / 2 = 9;
    vec.push_back(1);
    cout << vec.capacity() << endl;
    
    return 0;
}
```

**总结： vector的容量不够时，增加原容量的一半。**

### vector 设置容器大小

```c++
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const argv[])
{
    vector<int> vec(3);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    vec.reserve(20);  // 设置多大就是多大，要大于原容量
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    return 0;
}
```

### vector 判断对象是否有元素

```c++
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const argv[])
{
    vector<int> vec(3);
    cout << vec.empty() << endl;

    vector<int> vec2;
    cout << vec2.empty() << endl;
    return 0;
}
```

### 增删改查

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char const argv[])
{
    // 索引赋值
    vector<int> vec;
    for (int i = 0; i < 5; ++i)
    {
        vec.push_back(i);
    }
    for (int i = 0; i < 5; ++i)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;

    // at() 赋值
    for (int i = 0; i < 5; ++i)
    {
        vec.at(i) = i;
    }
    for (int i = 0; i < 5; ++i)
    {
        cout << vec.at(i) << ' ';
    }
    cout << endl;

    // 取最后一个元素
    cout << vec.back() << endl;

    // 迭代器遍历
    for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << ' ';
    }
    cout << endl;

    // for_each() 遍历
    for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' '; });  // 匿名函数：[捕获列表](参数列表){函数体}
    cout << endl;

    // 插入元素
    vec.insert(vec.begin()+2, 12);
    for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' '; });    
    cout << endl;

    vec.insert(vec.begin()+2, 5, 13);
    for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' '; });    
    cout << endl;

    vector<int> vec1(5, 1);
    vec.insert(vec.begin(), vec1.begin(), vec1.begin()+2);
    for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' '; });    
    cout << endl;

    // 尾删除
    vec.pop_back();

    // 删除指定元素
    vec.erase(vec.begin()+3);
    vec.erase(vec.begin(), vec.begin()+3);

    // 清除所有元素
    vec.clear();

    return 0;
}
```


### vector 交换

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char const argv[])
{
    vector<int> vec;
    vector<int> vec1(5);
    for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' '; });
    cout << endl;
    for_each(vec1.begin(), vec1.end(), [](int i) {cout << i << ' '; });
    cout << endl;

    vec.swap(vec1);

    for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' '; });
    cout << endl;
    for_each(vec1.begin(), vec1.end(), [](int i) {cout << i << ' '; });
    cout << endl;
    return 0;
}
```

### vector 排序

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


int main(int argc, char const argv[])
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(4);
    sort(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' '; });
    cout << endl;

    sort(vec.begin(), vec.end(), greater<int>());
    for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' '; });
    cout << endl;

    return 0;
}
```

### random_shuffle

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;


int main(int argc, char const argv[])
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    srand((unsigned int) time(0));
    random_shuffle(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' '; });
    cout << endl;
    return 0;
}
```