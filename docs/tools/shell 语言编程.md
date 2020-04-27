

1. sh
2. bash
    ## /etc/passwd 查看用户默认bash，sh解释执行器没有高亮显示，也没有自动补全

### shell 编程
1. 所有的shell程序都是以 .sh 结尾

2. 执行方式
    1. bash  test.sh
    2. chmod +x test.sh
        ./test.sh
        ## 保证test.sh 的第一行为：  #!/bin/bash


#### 变量赋值
```
变量名=值  （等号两侧不能有空格）
number=10    name='张三丰'

获取Linux命令的执行结果给变量赋值
    time=$(Linux命令)
    time=`date`  (1左边那个)

接收用户从终端输入给变量赋值
    read -p "提示信息" 变量名
```

#### 输出语句

echo $变量名

#### ' ' 和  " " 的区别
```
' ' 无法获取变量的值

" " 可以获取变量的值

read -p 'Input name:' name

echo '名字是：$name'     结果： 名字是$name 

echo "名字是：$name"     结果： 名字是:张三丰
```
#### 运算符

##### 算术运算符

```
+  - * / %  ++  --
```

运算命令（let）：

    i=1

    let i++

    echo $i    

    expr 运算表达式

    i=1

    sum=`expr $i + 5`

    echo $sum

##### 比较运算符

文件状态

-e: 文件/目录是否存在

-d: 判断是否为目录

-f: 判断是否为文件

###### 字符比较
```
=    !=  
空： -z
非空:  ！-z   或者  -n
```
###### 数值比较
```
等于：-eq

大于：-gt

  >= : -ge

小于: -lt

  <=: -le

  !=: -ne
```
###### 逻辑比较
```
逻辑与: &&
逻辑或：||
```
#### if 条件判断
######语法格式
```
if [条件]; then

    执行语句

elif [ ]; then

    执行语句

else:

    执行语句

fi
```
##### for 循环1
语法格式    
```
for 变量名 in 值列表
do
    执行语句
done
```

###### 造数方法 seq 起始值 步长 终止值
```
seq 5:  1 2 3 4 5
seq 1 2 10:  1  3 5 7 9
seq 2 2 10:  2 4 6 8 10
```
```shell
打印 1-5：

for i in `seq 5`

do 

    echo $i

done
```


##### for 循环2
语法格式

```
for ((赋初值; 条件判断; 步长))

do

    执行语句

done
```

##### while 循环
```
while [条件]

do

    执行语句

done
```
##### 函数
```
函数名(){

    代码块

}

函数名     # 函数调用
```