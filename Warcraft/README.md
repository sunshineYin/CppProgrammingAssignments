# 魔兽世界
- 应用OO方法编程，所有涉及的对象均应当实现为对应的类，例如司令部、城市、武士，除数据属性外，对象支持必要的操作，如事件报告、战争等。 

- 实体类派生于共同基类，比如城市和司令部可以派生于虚拟的地点类（Place），武士派生于共同的英雄类（Warrior）。

- 各派生类的通用行为（共同的行为）可以用基类指针动态调用虚函数的方式实现，这样流程界面代码就会得到很大的简化，即可以通过一个遍历完成一个时刻所有对象的操作。

- 时间轴（tickle）可以用一个循环实现，其中各个对象依次根据时间轴进度实施动作，并报告状态或事件，循环以某个总部沦陷作为退出点。
