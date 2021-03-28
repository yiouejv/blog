

### 练习4.1

请问如何在lua程序中以字符串的方式使用如下的XML片段。

```xml
<![CDATA[hello world]]>
```

答: 

```lua
s = [=[<![CDATA[hello world]]>]=]
```

```lua
s = "<![CDATA[hello world]]>"
```

### 练习4.2

假设你需要以字符串常量的形式定义一组包含歧义的转义字符序列，你会使用哪种方式？ 
请注意考虑诸如可读性，每行最大长度及字符串最大长度等问题。

答: 使用一对方括号来声明长字符串/多行字符串常量

### 练习4.3

请编写一个函数，使之实现在某个字符串的指定位置插入另一个字符串。

```lua
function insert(str, pos, s)
    if not pos then return s end
    if pos == 0 then return str end
    local head, tail
    if pos > 0 then
        head = string.sub(str, 1, pos - 1)
        tail = string.sub(str, pos)
    else
        head = string.sub(str, 1, pos)
        tail = string.sub(str, pos+1)
    end
    if pos == -1 then tail = '' end

    return head .. s .. tail
end
```