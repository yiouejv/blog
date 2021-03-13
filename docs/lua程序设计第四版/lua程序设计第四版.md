

下划线+大写字母(例如 `_VERSION`)组成的标识符通常被lua语言用于特殊用途。

哑变量: 通常没有实际意义的变量


单行注释: `--`   
多行注释: `--[[]]`

lua语言不区分未初始化变量和被赋值为`nil`的变量。 变量赋值为`nil`, lua会回收变量占用的内存。

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

