
list 容器的本质是一个双向链表

forward_list 的操作都在链表头。 C++ 11 标准才支持

### 构造函数

#### list()

#### list(size_type \_Count) 
count 个元素初始化为0


#### list(size_type \_Count, const Type& \_Val)
count 个指定的值


#### list(const \_list& \_Right)
用一个list初始化当前的list


#### list(InputIterator \_First, InputIterator \_Last)
另一个对象中间的一段


### 头添加元素
push_front(const Type& Val);


### 尾添加元素
push_back(const Type& Val);



### 插入元素

#### iterator insert(iterator loc, const Type& Val);
在指定迭代器的位置加入一个数据

#### void insert(iterator loc, size_type num, const Type& Val);
在某个迭代器后加num个值为Value的元素

#### void insert(iterator loc, input_iterator start, input_iterator end);
在某个迭代器后加入另一个向量的中间一段


#### 删除元素

#### pop_front()
头删除

#### pop_back()
尾删除

#### clear()
清除链表元素

#### erase(const_iterator \_Where)
擦除某个位置的元素

#### erase(const_iterator \_First, const_iterator \_Last)
擦除从First, 到 last 之间的元素

#### remove(const \_Type Val)
移除所有和Val 相同的元素

#### unique()
移除所有重复的元素

### 合并链表

#### merge(\_Type \_Right)
合并两个链表

### 排序链表

#### sort()

如果链表元素是结构体，则需要重载运算符 <

#### reverse()

翻转链表, 如果链表元素是结构体，则需要重载运算符 <


#### 查找元素

#### find(InputIterator \_First, InputIterator \_Last, \_Type Val)

从一段迭代器中查找Val，找到则返回这个元素的迭代器


参考代码： <a href="../codes/test_list.cpp">test_list.cpp</a>