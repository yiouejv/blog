### 7.1

请编写一个程序，该程序读取一个文本文件然后将每行的内容按照字母表顺序排序后重写该文件。如果在调用时不带参数，则从标准输入读取并向标准输出写入；如果在调用时传入一个文件名作为参数，则从该文件中读取并向标准输出写入；如果在调用时传入两个文件名作为参数，则从第一个文件读取并将结果写入到第二个文件中。

```lua
function sortAndWrite(input, output)
    io.input(input)
    io.output(output)
    local lines = {}
    for line in io.lines() do
        lines[#lines + 1] = line
    end
    table.sort(lines, function(a, b)
        return string.sub(a, 1, 1) < string.sub(b, 1, 1)
    end)
    for i, line in ipairs(lines) do
        io.write(line, '\n')
    end
end
```

### 7.2

请改写上面的程序，使得当指定的输出文件已经存在时，要求用户进行确认。

```lua
function sortAndWrite(input, output)
    if io.open(output) then
        io.write(output, " file is exist, input y or n:", '\n')
        local y = io.read('l')
        if y == "n" then
            io.write("you give up", '\n')
            return
        end
    end
    io.input(input)
    io.output(output)
    local lines = {}
    for line in io.lines() do
        lines[#lines + 1] = line
    end
    table.sort(lines, function(a, b)
        return string.sub(a, 1, 1) < string.sub(b, 1, 1)
    end)
    for i, line in ipairs(lines) do
        io.write(line, '\n')
    end
end
```

### 7.3

对比使用下列几种不同的方式把标准输入流复制到标准输出流中的Lua程序的性能表现：

```
•按字节
•按行
•按块（每个块大小为8KB）
•一次性读取整个文件
对于最后一种情况，输入文件最大支持多大？
```

```lua
function test_7d3(filename)
    -- bytes: 文件太大容易导致栈溢出
    local startTime = os.time()
    assert(io.input(filename, 'r'))
    local str = io.read('a')
    local bytes = {string.byte(str, 1, -1)}
    for i, byte in ipairs(bytes) do
        io.write(string.char(byte))
    end
    print('----------------- bytes: ', os.difftime(os.time(), startTime))
    io.close()

    -- line
    local startTime = os.time()
    assert(io.input(filename, 'r'))
    for i=1, math.huge do
        local line = io.read('L')
        if not line then break end
        io.write(line)
    end
    print('----------------- line: ', os.difftime(os.time(), startTime))
    io.close()

    -- block
    local startTime = os.time()
    assert(io.input(filename, 'r'))
    for i=1, math.huge do
        local block = io.read(2^10)
        if not block then break end
        io.write(block)
    end
    print('----------------- block: ', os.difftime(os.time(), startTime))
    io.close()

    -- read all
    local startTime = os.time()
    assert(io.input(filename, 'r'))
    local str = io.read('a')
    io.write(str)
    print('----------------- read all: ', os.difftime(os.time(), startTime))
    io.close()
end
```

### 7.4

请编写一个程序，该程序输出一个文本文件的最后一行。当文件较大且可以使用seek时，请尝试避免读取整个文件。

```lua
function test_7d4(filename)
    local f = assert(io.open(filename))
    local total_size = f:seek("end")
    f:seek("set")
    local text = f:read("a")

    local _end = total_size
    while _end > 0 do
        local s = string.sub(text, _end, _end)
        if s == '\n' then
            local last_line = string.sub(text, _end+1, total_size)
            print("last_line: ", last_line)
            break
        end
        _end = _end - 1
    end
end
```

### 7.5

请将上面的程序修改得更加通用，使其可以输出一个文本文件的最后n行。同时，当文件较大且可以使用seek时，请尝试避免读取整个文件。

```lua
function test_7d4(filename, last_n)
    local f = assert(io.open(filename))
    local total_size = f:seek("end")
    f:seek("set")
    local text = f:read("a")

    local _end, count = total_size, last_n
    while _end > 0 do
        local s = string.sub(text, _end, _end)
        if s == '\n' then
            count = count - 1
            if count == 0 then
                local last_line = string.sub(text, _end+1, total_size)
                print("last_line: ", last_line)
                break
            end
        end
        _end = _end - 1
    end
end
```

### 7.6

使用函数os.execute和io.popen，分别编写用于创建目录、删除目录和输出目录内容的函数。

```lua
function test_7d5()
    function createDir(dirname)
        print(os.execute("mkdir " .. dirname))
    end

    function removeDir(dirname, isForce)
        local cmd = "rmdir " .. dirname
        if isForce then
            cmd = "rm -rf " .. dirname
        end
        print(os.execute(cmd))
    end

    function printDir(dirname)
        local cmd = "ls -l" .. dirname
        local t = io.popen(cmd)
        if t then
            local s = t:read('a')
            print(s)
            t:close()
        end
    end
end
```

### 7.7

你能否使用函数os.execute来改变Lua脚本的当前目录？为什么？

```lua
function test_7d6()
    function changeDir(target)
        local cur = arg[0]
        local cmd = "mv " .. cur .. " " .. target
        os.execute(cmd)
    end
end
```




