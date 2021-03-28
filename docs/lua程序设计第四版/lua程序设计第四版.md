

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
编译器在运行代码前会创建一个名为`arg`的表，索引0中保存脚本名，索引1保存第一个参数，以此类推。


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

-------------------------

### 安全访问

确认某个库中存在某个函数，如果我们确定这个库确实存在，那么可以直接使用`if lib.foo then ...`, 否则就得使用形如`if lib and lib.foo then ...` 的表达式，当表的嵌套变得比较深时，这种写法就很容易出错。

例如:

```lua
zip = company and company.director and
    company.director.address and company.director.address.zipcode
```

这种写法不仅冗长而且低效，该写法在一次成功的访问中对表进行了6次访问，而非3次访问。

lua 的话可以这么写

```lua
E = {}
zip = (((company or E).director or E).address or E).zipcode
```

------------------------------

### table.pack

要遍历可变长参数，函数可以使用表达式{...}将可变长参数放在一个表中。

不过，在某些罕见的情况下，如果可变长参数中包含无效的nil，那么{...}获得的表可能不再是一个有效的序列。

此时，就没有办法在表中判断原始参数究竟是不是以nil结尾的。

对于这种情况，Lua语言提供了函数table.pack。 该函数像表达式{...}一样保存所有的参数，然后将其放在一个表中返回，但是这个表还有一个保存了参数个数的额外字段"n"。

例如，下面的函数使用了函数table.pack来检测参数中是否有nil：

```lua
function nonils( ... )
    local arg = table.pack(...)
    for i=1, arg.n do
        if arg[i] == nil then return false end
    end
    return true
end
```

### select

函数select总是具有一个固定的参数selector，以及数量可变的参数。如果selector是数值n，那么函数select则返回第n个参数后的所有参数；否则，selector应该是字符串"#"，以便函数select返回额外参数的总数。

<a href="../../lua/select函数">select函数</a>

