### 练习1.1

!!!question
    运行阶乘的实例并观察，如果输入的是负数，程序会出现什么问题?试着修改代码来解决问题

!!!answer
    输入负数程序会无限递归至栈溢出, 修改：
    ```lua
    function fact(n)
        if n < 0 then error("invalid n") end
        if n == 0 then return 1 end
        return n*fact(n-1)
    end
    ```

### 练习1.2

!!!question
    分别使用 -i 参数和 dofile 加载脚本并运行twice示例，你更喜欢哪种方式? (注意是-i 不是-l 中文版印刷有错误)

!!!answer
    ```
    第一种: lua -i test.lua
            ->fact(3)

    第二种: 直接运行 lua
            ->dofile(test.lua)
            ->fact(3)
    ```

### 练习1.3

!!!question
    你能否列举出其他使用 "--" 作为注释的语言

!!!answer
    AppleScript


### 练习1.4

!!!question
    以下字符串中哪些是有效的标识符

!!!answer
    ```lua
    local ___  =    "valid"
    local _end =    "valid"
    local End  =    "valid"
    local end  =    "invalid"
    local until?  = "invalid"
    local nil     = "invalid"
    local NULL    = "valid"
    local one-step     = "invalid"
    ```

### 练习1.5

!!!question
    表达式 `type(nil) == nil` 的值是什么?（你可以运行代码来检查下答案）你能解释下原因吗?

!!!answer
    ```lua
    print(type(nil) == nil)  -- false   
    ```
    type 函数返回的永远是一个字符串

### 练习1.6

!!!question
    在不使用函数type的情况下，你如何检查一个值是否为boolean类型?

!!!answer
    ```lua
    function isBoolean(b)
        return b == true or b == false
    end
    ```

### 练习1.7

!!!question
    考虑如下的表达式。其中的括号是否是必需的? 你是否推荐在这个表达式中使用括号

    ```lua
    (x and y and (not z) or (not y) and x)
    ```

!!!answer
    不是必需的。 推荐还是用括号，增强可读性

    ```lua
    local x,y,z = true,true,false
    if x and y and (not z) or (( not y) and x) then
        print("success1")
    end
    if x and y and not z or not y and x then
        print("success2")
    end

    x,y,z = true,false,false
    if x and y and (not z) or (( not y) and x) then
        print("success3")
    end
    if x and y and not z or  not y and x then
        print("success4")
    end
    ```

### 练习1.8

!!!question
    请编写一个可以打印出脚本自身名称的程序(事先不知道脚本自身名字)

!!!answer
    ```lua
    print(arg[0])
    ```