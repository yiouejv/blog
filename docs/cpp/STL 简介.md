

STL (Standard Template Library)

标准模板库

### STL 的地位

C++ 含义： C语言+类+模板

### STL 整体内容

#### STL 的6大组件

- 容器
- 迭代器
- 算法
- 适配器
- 分配器
- 仿函数

##### 容器 container

系统封装好的数据结构

顺序容器

- string
- 数组 array, vector (数组，向量)
- 链表 list, forward_list (单向链表，双向链表)
- 栈 stack
- 队列 deque
- 树 map, set
- hash表 hash_map

关联容器

- 有序容器

	- map 键值保存，高校访问
	- multimap
	- set 集合
	- multiset

- 无序容器

	- unorder_map
	- unorder_multimap
	- unorder_set
	- unorder_multiset


每种数据结构都能装任意类型，这就是泛型编程的思想，也是模板的应用

##### 算法 algorithm

系统内置的常用算法，排序，交换，替换等。

一个算法可以适用多个容器。

##### 迭代器 iterator 

链接容器和算法

#### STL 的优点

- 节省开发时间，提高开发效率
- 高移植性
	STL 是c++标准库，所有的c++编译器都必须支持。
- 高性能
	每个容器的操作，每个算法的实现，都是经过几代大师的修改。
	

