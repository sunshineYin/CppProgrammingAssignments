/**********************************

* 本项目采用多文件编程方式，目的是解决爬楼梯问题及bonus要求

* 本项目主要采用面向过程编程方式，各种具体功能由各个函数实现

* 除完成问题基本要求外，本项目还实现了bonus相应要求，具体说明如下： 

* 1、本项目递归方法是采取暴力递归方法，因此选择递归方法时，正常输入或文件输入时，尽量不要输入过大整数（如30+），避免死机

* 2、主函数部分实现用户友好交互界面，采取两重循环结构，实现bonus要求2，此外更进一步，允许返回上一级，对数据方式重新选择

* 3、对于输入较大的整数，建议选择非递归方法，而非递归。
    该要求（bonus要求1）核心代码是大整数加法，实际输入的整数可以大于200，只需调整常量MAX_INPUTNUM的值即可 

* 4、实现bonus要求3，即文件批量导入数据。具体操作方式是：用户自行编辑与程序同级文件夹下的“data.txt”文件，
    每行一个整数，以0为结束，保存后，运行程序，即可批量输出结果。  

* 5、对于大整数加法的实现，采用字符指针表示大整数，并借助数组，对大整数进行位（个十百千...）运算，具体实现参照相应cpp源文件 

* 6、对于非递归方法，采用自底向上的递推（？）方法，借助数组存储所有计算结果，达到空间换时间的效果，大大优化算法
 
*********************************/
