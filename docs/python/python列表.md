### 问题

如何将计算机运算的数据临时保存在一个地方，同时又方便添加，删除，修改等操作

### 列表的定义

- 列表是一种容器
- 列表是可以改变的序列
- 列表是由一系列特定元素组成的，元素与元素之间可能没有任何的关联关系，但他们之间有先后顺序关系

### 创建空列表的字面值表达式

- []  # 创建一个空列表
- l = []  # 变量l 绑定一个新创建的空列表

### 创建非空的列表的字面值

```python
	l = [1 ,2 ,3, 4]  # 变量l 绑定一个新创建的且含有四个元素的列表
    l = ['BeiJing', 'ShangHai', 'ShenZhen']
	l = [1, 'Two', 3.14, '四']
	l = [1, 2, [3.1, 3.2, 3.3], 4]
```

### 列表的构造函数list

- list() 生成一个空的列表，等同于[]
- list(iterable) 用有、可迭代对象创建一个列表

```
	l = list()  # l = []
	l = list('hello')  # l = ['h', 'e', 'l', 'l', 'o']
	l = list(range(5))  # l = [0, 1, 2, 3, 4]
```

### 列表的运算

```
算术运算：
	+ += * *=（运算规则和字符串的运算规则）
+ 用于拼接列表，生成新的列表
	x = [1, 2, 3]
	y = [4, 5, 6]
	z = x + y
+= 用于原列表与右侧可迭代对象追加来修改原列表
	语法：
		列表 += 可迭代对象
	示例
		x = [1, 2, 3]
		y = [4, 5, 6]
		x += y  # x = [1, 2, 3, 4, 5, 6]
		x += 'ABC'  # x = [1, 2, 3, 4, 5, 6, 'A', 'B', 'C']

	+= 是改变原来的列表对象，并不会创建新的列表
		x = [1, 2, 3]
		print(id(x))
		x += [4 ,5, 6]
		print(id(x))

* 生成重复的列表
	x = [1, 2] * 3  # x = [1, 2, 1, 2, 1 ,2]

*= 生成重复的列表， 并改变对列表的绑定
	x = [1, 2, 3]
	x *= 2  # x = [1, 2, 3, 1, 2, 3]
```

### 列表的比较运算

```
	运算符 < <= > >= != ==
	比较规则，与字符串的比较规则相同

	示例
		[1, 2, 3] < [1, 2, 4]  # True
		[1, 2, 3] < [3, 2, 1]  # True
```

### 列表是可迭代对象

```python
l = [1, 3, 5, 7]
	for i in l:
		print(i)
```

### 列表的 in / not in 运算符

- 判断一个值是否存在于列表中，如果存在返回True,否则返回 False
- 同字符串的 in 运算符 用于检查一个值是否存在于列表中，如果存在返回True, 否则返回False

```python
  x = [1, 'Two', 3, '四']
  3 in x  # 返回 True
  '3' in x  # 返回 False
  10 in x  # False
  10 not in x  # True
```

### 列表的索引操作

```python
  语法:
    列表[整数表达式]
  用法:
    与字符串索引的用法相同(分为正向索引和反向索引)
　　示例:
    x = [1,3,5,7]
    print(x[1])  # 3　　
    print(x[-1])  # 7
```

### 列表的索引赋值

```
  列表是可变的，可以通过索引赋值改变列表中的元素
  语法:
    列表[整数表达式] = 表达式
  作用:
    改变列表中索引的绑定关系
  示例:
    x = [1, 2, 3, 4]
    x[2] = 3.14  # 改变了第三个元素的值
```

### 列表的切片

```
  列表[:]
  列表[::]
  列表的切片取值返回一个新的列表，规则等同于字符串切片规则

  示例:
    x = [1, 2, 3, 4, 5, 6, 7, 8]
    x[::2]  # [1, 3, 5, 7]
    y = [1::3]  # y = [2, 5, 8]
```

### 列表的切片赋值

```
  作用:
    可以改变原列表的数据排列，可以插入和修改数据
    可以用切片改变列表的对应元素的值
  语法:
    列表[切片]　= 可迭代对象
　　说明:
    切片赋值的赋值运算符(=) 的右侧必须是一个可迭代对象

  示例:
    L = [2, 3, 4]
    L[0:1] = [1.1, 2.2]  # L = [1.1, 2.2, 3, 4]
    L[2:] = [3.3, 4.4, 5.5]  # L = [1.1, 2.2, 3.3, 4.4, 5.5]
    L[:] = [3, 4] 　# L = [3, 4]
    L[0:0] = [1, 2]  # L = [1, 2, 3, 4]
    L = [3, 4]
    L[1:1] = [3.14]  # L = [3, 3.14, 4]
    L = [3, 4]
    L[-1:-1] = [5, 6] # L = [3, 4, 5, 6]
    L = [2, 3, 4]
    L[1:2] = "ABC"  # L = [2, 'A', 'B', 'C', 4]
    L = [2, -1, 7]
    L[1:2] = range(3, 7)  # L=[2, 3, 4, 5, 6, 7]
```

### 切片的注意事项

```
对于步长不等于1的切片赋值,赋值运算符的右侧的可迭代对象提供元素的个数一定要等于切片切出的段数
  示例:
    L = [1, 2, 3, 4, 5, 6, 7, 8]
    L[1::2] = "ABCD"  # 对的
    L[1::2] = "ABCDEF"  # 错的
```

**练习**

```
  已知有列表:
    L = [3, 5]
  用索引和切片操作,将原列表改变为:
    L = [1, 2, 3, 4, 5, 6]
  将列表反转,删除最后一个元素后打印此列表
    ....
    print(L)  # [6, 5, 4, 3, 2]
    
  写程序,让用户循环输入一些整数,当输入-1时结束输入,将这些整数存于列表L中
    1) 打印您共输入了多少个有效的数
    2) 打印您输入的数的最大数是?
    3) 打印您输入的最小数是多少?
    4) 打印您输入的这些数的平均值是多少?

  写一个程序，让用户输入很多个正整数，当输入小于零的数时结束输入
　　1) 打印这些数中最大的一个数
　　2) 打印这些数中第二大的一个数
   3) 删除最小的一个数
   4) 按原来顺序打印出剩余的这些数
```

### 列表推导式 

list comprehension:   列表推导式是用可迭代对象创建列表的表达式

```
  作用:
    用简易方法生成列表
  语法:
    [表达式 for 变量 in 可迭代对象]
    或
    [表达式 for 变量 in 可迭代对象 if 真值表达式]
  示例:
    # 生成一个数值为1~9的平方的列表
    # [1, 4, 9, 16, .... 81]
    # 不用推导式:
    L = []
    for i in range(1, 10):
        L.append(i**2)
    # 推导式实现
    L = [i ** 2 for i in range(1, 10)]
```



```
用列表推导式生成 1~100以内奇数的列表, 结果是:[1, 3, 5, 7, ...., 99]
  答案:
    [i for i in range(1, 100, 2)]

    或
    [i for i in range(1, 100) if i % 2 == 1]
```

**练习**

输入一个开始的整数用begin绑定  
  输入一个结束的整数用end绑定  
  将从begin开始,到end结束(不包含end)的所有偶数存于列表中  
  并打印此列表  
  (可以使用列表推导式完成,也可以用循环语句来完成  

### 列表推导式的嵌套

```
语法:
    [表达式
      for 变量1 in 可迭代对象1 if真值表达式1
        for 变量2 in 可迭代对象2 if 真值表达式2 ...]
```

```
示例:
    #将列表[10, 20, 30] 中的元素与列表[1,2,3]元素分别相加,将得到的元素放于一个列表中

    L = [x + y
          for x in [10, 20, 30]
            for y in [1,2,3]]
    print(L)  #[11, 12, 13, 21, 22, 23, 31,32,33]
```

**练习**

```
  1. 用字符串"ABC"和字符串"123" 生成如下列表
   ['A1', 'A2', 'A3', 'B1', 'B2', 'B3', 'C1', 'C2', 'C3', ]
   答案:
     [ x + y for x in "ABC" for y in "123"]

  2. 已知有一个字符串:
    s = '100,200,300,500,800'
    将其转化为列表,列表的内部是整数
    L = [100, 200, 300, 500, 800]
  答案:
    L = [int(x) for x in s.split(',')]
```

```
  1. 有一些数存在列表中, 如:
     L = [1, 3, 2, 1, 6, 4, 2, ...., 98, 82]
    1) 将列表L中出现的数字存于另一个列表L2中
      要求:
         重复出现多次的数字只在L2列表中保留一份(去重)
    2) 将列表中出现两次的数字存于L3列表中(在L3列表中保留一份)

  2. 计算出100以内的素数,将这些素数存于列表中,最后打印出列表中的这些素数

  3. 生成前40个斐波那契数(Fibonacci)
    1 1 2 3 5 8 13 21 ......
    要求将这数整数存于列表L中,最后打印出这些数
    (斐波那契的前两个是1, 1, 之后的数是前两个数的和)
```