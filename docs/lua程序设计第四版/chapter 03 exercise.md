

### 练习3.1

!!!question
	以下哪些值是有效的数值常量？它们的值分别是多少?

!!!answer
	```lua
	-- .0e12       有效  0.0
	-- .e12        无效  '.' unexpected
	-- 0.0e        无效  malformed number near '0.0e'
	-- 0x12        有效  18
	-- 0xABFG      无效  syntax error
	-- 0xA         有效  10
	-- FFFF        无效  变量名
	-- 0xFFFFFFFF  有效  4294967295
	-- 0x          无效  syntax error
	-- 0x1P10      有效  1024.0
	-- 0.1e1       有效  1.0
	-- 0x0.1p1     有效  0.125
	```

### 练习3.2

!!!question
	解释下列表达式之所以得出相应结果的原因。(注意:整型算术运算总是会回环)

!!!answer
	print(math.maxinteger * 2)               -- => maxinteger +  (maxinteger + 1) - 1 => maxinteger + mininteger - 1 =>  -1 + -1 => -2
	print(math.mininteger * 2)               -- => mininteger +  (mininteger - 1) + 1 => mininteger + maxinteger + 1 =>  -1 +  1 => 0
	print(math.maxinteger * math.maxinteger) -- => maxinteger * (mininteger - 1) => mininteger - maxinteger => 1
	print(math.mininteger * math.mininteger) -- => mininteger * (maxinteger + 1) => mininteger + mininteger => 0

### 练习3.3

!!!question
	下列代码的输出结果是什么?
	```lua
	for i = -10, 10 do
	    print(i , i % 3)
	end
	```
!!!answer
	注意 : Lua的取整除法向负无穷取整
      -- 比如 -10 // 3 等于 -4 而不是 -3
      -- 所以 -10 % 3 等于 2 而不是 -1
      -- 若要得到与C++等语言一样的结果请使用 math.fmod

### 练习3.4

!!!question
	表达式2^3^4的值是什么？表达式2^-3^4呢？
!!!answer
	```lua
	print(2^3^4)   -- 2.4178516392293e+024
	print(2^-3^4)  -- 4.1359030627651e-025
	```


### 练习3.5

当分母是10的整数次幂时，数值12.7与表达式127/10相等。能否认为当分母是2的整数次幂时，这是一种通用规律？对于数值5.5情况又会怎样呢？

### 练习3.6

请编写一个通过高、母线与轴线的夹角来计算正圆锥体体积的函数。

```lua
local function CalculateConeVolume(h,fAngle)
    local r = h * math.tan( math.rad(fAngle))
    return math.pi * (r^2) * h / 3
end
print(CalculateConeVolume(1,60))
```

### 练习3.7

利用函数 math.random 编写一个生成遵循正态分布（高斯分布）的伪随机数发生器