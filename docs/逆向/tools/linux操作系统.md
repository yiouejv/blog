### 文件和目录相关的命令

格式： 命令名 [选项] [参数]

```
【pwd】
作用: 用于显示当前操作的路径（当前工作文件夹）

【ls】
作用：显示指定目录的文件或文件夹

常用选项：
	-l 列表显示文件的 详细信息
	-a 显示全部文件 /文件夹

示例：ls -l core
-rw------- 1 tarena tarena    5943296         7月28 2017 core
	文件权限 	属主  属组   文件大小（字节）  修改日期  文件名

【cd】
作用：改变当前的工作目录（进入某个文件夹）

格式：
	cd 目录名
示例：
	cd /home/tarena 进入到/home/tarena文件夹
	cd /  进入到根目录下
	cd    返回到用户组目录
	cd .. 返回上一级目录
	cd ~  返回到用户组目录（同cd）



【mkdir】
作用：创建一个或多个文件夹

【rmdir】
作用：删除一个或多个文件夹

说明：文件夹内必须为空

【touch】
作用：
	1/ 如果文件不存在，则创建一个空文件
	2/ 如果文件或目录存在，则用系统时间更新它的修改时间
格式：
	touch 文件名
示例：
		touch newfile
【rm】
作用：删除文件或文件夹
常用选项：
	-r 递归删除文件夹内部的文件或文件夹
	-i 删除前给出提示
	-f 强制删除，不给出任何提示
示例：
		rm newfile


【tree】
作用：显示一个文件夹的结构
格式：tree [文件夹]

【help】帮助选项：
格式: 命令 --help
例：ls --help

【man】命令帮助
格式：man 命令
作用：查看命令所对应的帮助文档
```

### Linux下的路径

```
根（root）  /

路径分两种：
	绝对路径：以‘/’字符开头的路径
	相对路径：不以‘/’字符开头的路径
开始符号：
	文件/文件夹名称
	.当前文件夹（目录）
	..上一级文件夹（目录）
	~用户主目录（家目录）
```

### 通配符

​	*代表0个，1个或多个任意字符  
​	？代表1个任意字符  

| 示例： |                                      |
| ------ | ------------------------------------ |
|         touch  a ab ac abc aabb bc cd        |
|         ls a*                                |
|         ls *c                                |
|         rm a*b                               |
|         ls ?? 	显示只有两个字符构成的文件 |
|         ls a??                               |

###  文件管理命令

```
【cp】
作用：复制文件或文件夹
格式：cp [选项] 源文件或文件夹  目标文件或文件夹
示例：
	cp a.txt ~/b.txt
	cp -a /home/tarena/yiouejv  ~/
常用选项：
	-a 可以复制文件夹及其内部的全部内容

【mv】
作用：文件搬移或更名
格式：源文件或文件夹   目标文件或文件夹
示例： mv a.txt b.txt
       mv a.txt /home/tarena


【find】
作用：根据文件名等信息查找指定的文件的位置（路径）
格式：find 路径 -name 文件名

示例：
    #查找文件 passwd
    find /etc -name 'password'
在etc文件夹下查找没有没passwd这个文件，如果有则列出来

【grep】
作用：查找文件中相应的内容，及文本信息
格式：
	grep "内容" [选项] 文件名或路径
常用选项：
	-n 显示行号
	-r 递归搜索文件夹内的文件

```

### 压缩解压缩的命令

```
【gzip】
作用：用zip压缩算法对文件进行压缩，生成压缩后的.gz文件
格式：gzip 文件名

【gunzip】
作用：对用zip压缩的.gz文件进行解压缩
格式：gunzip  文件名
```

### 打包解包的命令

```
【tar】
作用：对文件或文件夹进行打包或解包操作
格式：
	tar [选项] 文件名 [文件名或路径]
常用选项：
	-c 		创建包
	-x 		解包
		-f 文件名  	操作的文件名
	-v 		显示操作的文件细节
	-z 		用gzip或gunzip对包进行压缩和加压缩
示例：
	打包： tar czvf a.tar.gz  [原文件路径]
	解包： tar xzvf a.tar.gz
```

### Linux常用命令

#### ifconfig

查看ip地址和MAC地址

#### ping

测试网络的连通性：ping ip地址 -c 次数

#### top

Lniux下的任务管理器，能够动态的显示当前所有进程CPU以及内存的使用率，q退出

#### ps

ps -aux     显示系统进程（PID号）   
ps -aux | grep "mysql"

#### df

df -h 查看磁盘使用情况

#### ls

ls -lh 文件名

l表达长格式，h提供易读单位


#### chmod
修改文件权限
```
chomd +x 文件名   添加可执行权限

chomd 644 文件名   rw-r--r--

        r: 4

        w: 2

        x:  1
```
#### wc
wc -l : 统计文件的行数    
wc -l /etc/passwd:    统计当前Linux系统由多少用户

#### sort
排序，对文件中的内容进行排序   
sort ip.txt    

#### uniq -c
去除重复的行并统计每行出现的次数（只能去除相邻行）

用法：sort文件名 | uniq -c

#### find

根据指定的条件来查找文件或目录

-name : 根据文件名查找

find 路径  -name 文件名

		  -iname  不区分大小写

查找~/spider目录下的所有.py文件

find ~/spider -name "*.py"
```
-type：根据类型查找(文件|目录)
     -f:  文件
     -d:  目录
     -l:  链接(link快捷方式)
      查找主目录下所有的目录

-size: 按大小查找
    +   大于...文件/目录
    -   大于...文件/目录
    查找/home/tarena/software 大于20M的文件
    find ~/software -size +20M -type f 

-ctime   根据时间查找
    ctime + 1: 表示一天以前的文件或目录
```

查找~/spider下一天以内的文件
```
find ~/spider -ctime -1 -type f
```
处理动作
```
find ...  -exec  Linux命令{} \;
```
查找一天以内的以.doc结尾的文件，删除
```
find / -name *.doc -ctime -1 -type f -exec rm -rf {} \;
```

#### du

du -sh 显示当前目录大小