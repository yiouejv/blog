### 装饰器 decorator

```
    什么是装饰器
        装饰器是一个函数，主要作用是用来包装另一个函数或类
        包装的目的是在不改变原函数（或类名）的情况下改变被包装对象的行为
```

### 函数装饰器

是指装饰器是一个函数，传入的是一个函数，返回的是一个函数

```
语法
        def 装饰器函数名(参数):
            语句块
            return 函数对象

        @装饰器函数名<换行>
        def 函数名(形参列表):
            语句块
```

**原理**

被装饰器函数的变量（函数名）绑定装饰器函数调用后的返回的函数

```python
# 此示例示意装饰器函数的定义和调用装饰器原理
def mydeco(fn):  # <<<----- 装饰器函数
    def fx():
        print('fx被调用')
    return fx

@mydeco
def myfun():
    print('myfun被调用')

# 上述 mydeco的原理是在 def myfun语句调用之后加了一条如下语句
# myfun = mydeco(myfun)
myfun()  #调用myfun
myfun()
myfun()
```

```python
# 此示例示意装饰器函数用来包装被装束函数
def mydeco(fn):  # <<<----- 装饰器函数
    def fx():
        print('------这个被装饰函数调用之前-------')
        fn()  # 被调用被装饰函数
        print('++++++这个被装饰函数调用之后+++++++')
    return fx

@mydeco
def myfun():
    print('myfun被调用')

# 上述 mydeco的原理是在 def myfun语句调用之后加了一条如下语句
# myfun = mydeco(myfun)
myfun()  #调用myfun
myfun()
myfun()
```

```python
# 此示例示意装饰器的应用场合及功能
# ---------------------以下是魏老师写的程序--------------------------
def privileged_check(fn):
    def fx(name, x):
        print('正在进行权限验证。。。')
        if True:
            fn(name, x)
        else:
            print('权限验证失败')
    return fx


def  message_send(fn):
    def fy(n, money):
        fn(n, money)  # 调用被装饰函数
        print('正在发送短信给', n, '...')
    return fy

# ---------------------以下是魏老师写的程序--------------------------
@ message_send
@ privileged_check
def savemoney(name, x):
    print(name, '存钱', x, '元')
# 实质是
# savemoney = privileged_check(savemoney)
# savemoney = message_send(savemoney)


def withdraw(name, x):
    print(name, '取钱', x, '元')


# ---------------------以下是调用者写的程序--------------------------
savemoney('小王', 200)
savemoney('小赵', 400)

withdraw('小李', 500)
```

### 函数的文档字符串

函数内第一次未赋值给任何变量的字符串是此函数的文档字符串

```
	语法
        def 函数名(参数列表):
            '''函数文档字符串'''
            语句块

    说明
        1. 文档字符串通常用来说明函数功能和使用方法
        2. 在交互模式下，输入:
                            >>>help(函数名)   可以查看函数的文档字符串
        3. 函数的文档字符串绑定在函数的__doc__属性上
    示例
        def mysum(n):
            '''1 + 2 + 3 + 4 + ...+ n'''
            return 100
        help(mysum)
    
    
函数的__doc__属性
    __doc__属性用于记录文档字符串


函数的__name__属性
    __name__属性用于记录函数名
    说明
        以双下划线开头，以双下划线结尾的标识符通常代表python的特殊变量
```

### 函数定义的完整语法

```
	[@装饰器名1]
    [@装饰器名2]
    [...]
    def 函数名(位置形参, *元组形参, 命名关键字形参, **字典形参):
        '''文档字符串'''
        语句块
```

