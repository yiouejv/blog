#!/usr/bin/lua

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



print(insert("hello world", 1, "start: "))
print(insert("hello world", 2, "start: "))
print(insert("hello world", 3, "start: "))
print(insert("hello world", 4, "start: "))
print(insert("hello world", 5, "start: "))
print(insert("hello world", 6, "start: "))
print(insert("hello world", 7, "start: "))
print(insert("hello world", 8, "start: "))
print(insert("hello world", 9, "start: "))
print(insert("hello world", 10, "start: "))
print(insert("hello world", 11, "start: "))
print(insert("hello world", 12, "start: "))
print(insert("hello world", 13, "start: "))
print(insert("hello world", 14, "start: "))
