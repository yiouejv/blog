

浮点数是我们在程序里常用的数据类型，它在内存中到底是怎么样的形式存在，是我了解之前是觉得好神奇，以此记录，作为学习笔记。

现代计算机中，一般都以IEEE 754标准存储浮点数，这个标准的在内存中存储的形式为：

![](../../images/20170419125813440.png)

对于不同长度的浮点数，阶码与小数位分配的数量不一样，如下：

![](../../images/20170419125828093.jpg)

对于32位的单精度浮点数，数符分配是1位，阶码分配了8位，尾数分配了是23位。

根据这个标准，我们来尝试把一个十进制的浮点数转换为IEEE754标准表示。

*例如：178.125*

1. 先把浮点数分别把整数部分和小数部分转换成2进制
	- 整数部分用除2取余的方法，求得：10110010
	- 小数部分用乘2取整的方法，求得：001
	- 合起来即是：10110010.001
	- 转换成二进制的浮点数，即把小数点移动到整数位只有1，即为：1.0110010001 * 2^111，111是二进制，由于左移了7位，所以是111
2. 把浮点数转换二进制后，这里基本已经可以得出对应3部分的值了
	- 数符：由于浮点数是正数，故为0.(负数为1)
	- 阶码 : 阶码的计算公式：阶数 + 偏移量,  阶码是需要作移码运算，在转换出来的二进制数里，阶数是111(十进制为7)，对于单精度的浮点数，偏移值为01111111(127)[偏移量的计算是：2^(e-1)-1, e为阶码的位数，即为8，因此偏移值是127]，即：111+01111111 = 10000110
	- 尾数：小数点后面的数，即0110010001
	![](../../images/20170419125955641.jpg)


视频讲解: https://www.youtube.com/watch?v=oyWHqJ3ZNJw