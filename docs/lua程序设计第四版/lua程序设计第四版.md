

下划线+大写字母(例如 `_VERSION`)组成的标识符通常被lua语言用于特殊用途。

哑变量: 通常没有实际意义的变量

-----------------

单行注释: `--`   
多行注释: `--[[]]`

-------------------

lua语言不区分未初始化变量和被赋值为`nil`的变量。 变量赋值为`nil`, lua会回收变量占用的内存。

-------------------

八种数据类型: nil, boolean, number, string, userdata, function, thread, table。   
使用`type` 获取值对应的类型名。

```lua
print(type( nil ))
print(type( true ))
print(type( 10.4 * 3 ))
print(type( "hello world" ))
print(type( io.stdin ))
print(type( print ))
print(type( type ))
print(type( {} ))
print(type( type(X) ))
```

userdata 类型允许把任意的C语言数据保存在lua语言变量中。    在lua语言中，用户数据类型除了赋值和相同性能测试外，没有其他预定义的操作。    
用户数据被用来表示由应用或C语言编写的库所创建的新类型。

`nil` 是一种只有一个nil值的类型，主要用来与其他所有值进行区分。 lua语言使用nil来表示`non-value`的情况。

----------------------------


练习:

- 运行阶乘的示例并观察，如果输入负数，程序会出什么问题？修改。

```lua
function fact(n)
    if n == 0 then return 1 end
    return n*fact(n-1);
end

print("enter a number:")

a = io.read("*n");

print(fact(a))
```
无限递归导致栈溢出，改成 `if n <= 0 then return 1 end`

- 请编写一个可以打印出脚本名称的程序。

```lua
print(arg[0])
```

编译器在运行代码前会创建一个名为`arg`的表，索引0中保存脚本名，索引1保存第一个参数，以此类推。

- 八皇后问题。

参考: <a href="../NQueens.lua">NQueens.lua</a>


------------------------

从Lua 5.3版本开始，Lua语言为数值格式提供了两种选择：被称为integer的64位整型和被称为float的双精度浮点类型（注意，在本书中“float”不代表单精度类型）。对于资源受限的平台，我们可以将Lua 5.3编译为精简Lua（Small Lua）模式，在该模式中使用32位整型和单精度浮点类型。

具有十进制小数或者指数的数值会被当作浮点型值，否则会被当作整型值。

整型值和浮点型值的类型都是"number"，由于整型值和浮点型值的类型都是"number"，所以它们是可以相互转换的。同时，具有相同算术值的整型值和浮点型值在Lua语言中是相等的：

```lua
1 == 1.0
-3 == -3.0
0.2e3 == 200
```

在少数情况下，当需要区分整型值和浮点型值时，可以使用函数math.type
