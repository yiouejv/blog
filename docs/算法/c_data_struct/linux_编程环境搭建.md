## linux_编程环境搭建

### 安装编译器  
```apt-get install gcc```

### 编辑代码  
编辑test.c文件

```C
#include <stdio.h>

int main(int args, char *argv[])
{
    printf("Hello world\n");

    return 0;
}
```

### 编译
```gcc -o test test.c```  
这个命令的意思是，运行gcc命令，编译test.c文件；-o表示将可执行文件保存为test。不出意外，在当前目录下可以看到一个名为test的可执行文件

### 运行
直接运行可执行文件，就可以看到程序输出的Hello world了：
```
$ ./test
Hello world
```