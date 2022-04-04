# MyC-Tutorial
## ch04 类和对象

### 4.2 类和对象

#### 4.2.1 类的定义

```c++
class 类名 {
public:
	共有接口
protected:
	保护成员
private:
	私有成员
};
```

#### 4.2.2 访问权限

- 共有类型：定义了外部接口
- 私有类型：只能被类内成员函数访问，类外部任何访问都是非法的
- 保护类型：和私有成员类似，差别继承过程中对新类的影响

> 数据成员应该声明为私有，在书写时公有成员写在最前面

#### 4.2.3 对象

- 声明对象
  类名 对象名

- 访问数据成员

  对象名.数据成员

- 访问函数成员

  对象名.函数成员

#### 4.2.4 类的成员函数

- 类内定义，类外实现，并使用类名限制

  - 类名::函数成员

  ```c++
  返回值类型 类名::成员函数名(参数表)
  {
      函数体
  }
  ```

- 默认参数

  ```c++
  class 类名{
  public:
      返回值类型 成员函数名()(参数列表初始化);
  };
  ```

- 内联成员函数

  - 隐式声明 直接放在函数体内

  ```c++
  返回值类型 fun()
  {
  
  }
  ```

  - 显示声明 使用关键字inline

  ```c++
  inline 返回值类型 成员函数名()
  {
  
  }
  ```


### 4.3 构造函数和析构函数

#### 4.3.1 构造函数

```c++
class 类名{
public:
	类名();
};
```

- 构造函数的作用是初始化对象
- 构造函数的名字与类名相同，而且没有返回值，通常被声明为共有函数
- 构造函数在对象创建时被默认调用
- 无需提供参数的构造函数称为默认构造函数，如果没写构造函数，系统默认生成一个隐含的构造函数，参数列表和函数体均为空
- 如果声明了构造函数(无论是否有参数)，编译器便不会为之生成隐含的构造函数
- 构造函数可以是直接访问所有的数据成员，可以是内联函数，可以带有参数表，可以带默认值，可以重载

> 如果定义了构造函数，编译器不会生成隐含的默认构造函数

#### 4.3.2 复制构造函数

```c++
class 类名{
public:
	类名();
    类名(类名 &对象);
};
```

- 复制构造函数是特殊的构造函数，有构造函数的特性，形参是本类对象的引用
- 作用是用一个存在的对象去初始化同类的另一个新对象
- 如果没有定义类的构造函数，系统会自动生成一个隐含的复制构造函数
- 这个隐含的复制构造函数的作用是把初始值对象的每一个数据成员的值都复制到新建立的对象

- 复制构造函数在以下情况会被默认调用
  - 用类来初始化该类的另一个对象时
  - 函数的形参是类的对象 
  - 函数的返回值是类的对象

### 4.3.3 析构函数

```c++
class 类名{
public:
	~类名();
};
```

- 构造函数用于完成对象被删除前的一些清理工作
- 构造函数是在独享的生存期即将结束的时刻被自动调用
- 构造函数是共有函数，名称由类名前加"~"，没有返回值，不接受任何参数
- 不进行显示说明，系统自动生成一个函数体为空的而隐含析构函数
- 如果人们希望对象被删除之前时刻西东完成某些事情，就可以将他们把他们写进析构函数中

### 4.4 类的组合

#### 4.4.1 组合

- 类的组合描述即使一个类内嵌其他类的对象做为成员

- 当创建类的时候，如果这个类具有内嵌对象成员，那么这个内嵌对象成员将首先被自动创建

- 创建对象时，纪要对本类的基本数据类型进行初始化，也要对内嵌对象成员进行初始化

- 一般的定义形式

- ```C++
  类名::类名(形参表):内嵌对象1(形参表),内嵌对象2(形参表)...
  {
  	类的初始化
  }
  ```

- 构造函数的调用顺序如下
  - 调用内嵌对象的构造函数，点哟ing顺序按照内嵌对象在组合类真的定义中出现的次序
  - 内嵌对象在构造函数的初始化列表中出现的顺序与内嵌对象构造函数的调用顺序无关
  - 执行本类构造函数的函数体
  - 析构函数的执行顺序与构造函数刚好相反

#### 4.4.2 前向引用声明

- 出现两个类相互引用的情况，成为循环依赖

  ```c++
  class B;		前向引用声明
  class A{
  public:
  	void f(B b);
  };
  class B{
  public:
  	void g(A a);
  }
  ```

## ch05 数据的共享与保护

### 5.1 标识符作用域与可见性

#### 5.1.1 作用域

- 作用域是一个标识符在程序正文的有效区域、

##### 1 函数原型作用域

- 在函数原型申明的形式参数的作用域的范围就是函数原型作用域

  ```c++
  double fun(double r);
  ```

> 由于在函数原型的形参列表中起作用参数类型，标识符不起作用，因此可以省略

##### 2 局部作用域

- 函数形参列表中形参的作用域，从形参的声明开始，到整个函数的函数体结束之处为止
- 函数体内的变量，其作用域从声明开始，一直到声明所在的块结束的大括号为止

##### 3 类作用域

- 类作用域可以看成一组有名成员的集合，访问方法有如下三种
  - 如果在X的成员函数中没有声明同名的局部作用域标识符，那么该函数内可直接访问
  - 通过表达式x.m或者X::m
  - 通过ptr->m这样的表达式，其中ptr是只想X类的一个对象的指针

##### 4 命名空间作用域

- 命名空间的语法形式

  ```c++
  namespace 命名空间名{
  	命名空间内的各种声明(函数声明、类声明)
  }
  ```

- 引用其他命名空间的标识符

  ```c++
  命名空间名::标识符名
  ```

- 使用using语句引用命名空间

  ```c++
  using namespace 命名空间名
  ```

#### 5.1.1 可见性

- 一般规则
  - 标识符要声明在前，引用在后
  - 在统一作用域中，布恩那个声明同名的标识符
  - 在没有相互包含关系的不同作用域中声明相同同名的标识符，互不影响
  - 如果在两个或多个具有包含关系的作用域中声明了同名标识符，则外层标识符在内层不可见

### 5.2 对象的生存期

#### 5.2.1 静态生存期

- 如果对象的生存期与成语运行期相同，则它具有静态生存期，要在函数内部的作用域中声明具有静态生存期的对象，要使用static关键字

  ```c++
  static int i;
  ```

- 局部作用域中静态变量不会随着函数产生产生副本，，也不会随着函数结束而失效，下次调用保留上一次的值

  > 定义时候未指定处置的基本类型静态生存期变量，赋予0初始化，对于动态生存期变量，不指定意味着初值不确定

#### 5.2.2 动态生存期

- 局部生存期对象诞生于声明点，结束语声明所在的块执行完毕

### 5.3 类的静态成员

#### 5.3.1 静态数据成员

- 如果每个属性为整个类所有，不属于任何一个对象，则采用static声明为静态成员

- 静态成员具有静态生存期，使用类名::标识符访问

  ```c++
  int 类名::标识符=0; 
  ```

- 需要在类内定义之后在类外在定义于初始化

#### 5.3.2 静态函数成员

- 静态成员函数可以通过类名调用，不属于任何一个对象，非静态成员函数的只能通过对象调用

> 静态成员函数可以通过类名和对象名两种，一般习惯于通过类名调用
>
> 静态成员函数访问非静态成员是非常麻烦的，要之明对象

### 5.4 类的友元

#### 5.4.1 友元函数

- 友元函数是在类中用friend修饰的非成员函数
- 可以是普通的函数，也可以时其他类的成员函数
- 可以通过类名访问类的私有和保护成员

#### 5.4.2 友元类

- 若A是B的友元类，那么A的所有成员函数都是B的友元函数，都可以访问B类的私有和保护成员

### 5.5 共享数据的保护

#### 5.5.1 常对象

- 常对象是指它的数据成员在整个生存期内不能改变

- 常对象必须进行初始化，而且不能更新

  ```c++
  const 类型说明符 对象名;
  ```

#### 5.5.2 用const修饰的类成员

##### 1 常成员函数

- 使用const修饰的函数称为常成员函数

- 对于无需改变对象状态的成员函数，应当使用const

  ```
  类型说明符 函数名(参数表) const;
  ```

> 常对象只能访问常成员函数
>
> 无论是否使用常对象调用常成员函数，在常成员函数被调用的时候，都会被视为常对象

##### 2 常数据成员

- 长数据成员只能通过初始化列表进行初始化

#### 5.5.3 常引用

- 常引用所引用的对象不能被更新

  ```c++
  const 类型说明符 & 引用名;
  ```

- 在函数中无须改变其值的参数，不宜使用普通引用传递，那样会使常对象无法被传入

- 复制构造函数的参数一般也宜采用常引用

|                        |                                                |                                          |
| ---------------------- | ---------------------------------------------- | ---------------------------------------- |
| 对象生存期             | 静态生存期                                     | 动态生存期                               |
|                        | 不会随着函数结束而失效，下次调用保留上一次的值 | 诞生于声明点，结束语声明所在的块执行完毕 |
| 静态成员（属于整个类） | 静态数据成员                                   | 静态函数成员                             |
|                        | 属于整个类，不属于任何一个对象                 | 属于整个类，不属于任何一个对象           |
| 常对象                 | 不能被更新                                     |                                          |
| 常成员函数             | 无需改变对象状态                               |                                          |
| 常数据成员             | 不能对数据赋值                                 |                                          |
| 常引用                 | 常引用所引用的对象不能被更新                   |                                          |
|                        |                                                |                                          |

## ch06 数组、指针与字符串 

### 6.1 数组

#### 6.1.1 数组的声明与使用

##### 1 数组的声明

```c++
数据类型 标识符[常量表达式1][[常量表达式2]...;
```

- 数组的大小是各下标的乘积

##### 2 数组的使用

```
数组名[下标表达式1][下标表达式2]...
```

- 数组元素的下标表达式可以是任意合法的算术表达式，其结果必须是整数
- 数组元素的下标值不得超过声明时所确定的上下界，否则运行时将出现数组越界错误

#### 6.1.2 数组的存储与初始化

##### 1 数组的存储

- 数组与严肃在内存中是顺序的、连续存储的 
- 数组名就是数组首地址
- 数组最左一维下标变化最慢，最右一维下标变化最快

##### 2 数组的初始化

- 初始化数组时给出数组全部初值，可以不必说明数组个数

  ```c++
  int a[3]={1,2,3};
  int a[]={1,2,3}
  ```

- 也可以给出部分初值，此时必须给出数组个数

  ```c++
  int a[10]={1,2};
  ```

  - 静态生存期的数组，每个元素被赋予0值
  - 动态生存期的数组，每个元素的初值是不确定的

- 对于多维数组，如果给出了全部初值，第一维可以省略

  ```c++
  int a[][3]={1,2,3,4,5,6};
  ```

- 也可按照第一维下标进行分组，使用花括号将每一维数组进行初始化

  ```c++
  int a[2][3]={{1,2,3},{4,5,6}};
  ```

- 数组也可以声明为常量

  ```c++
  const int f[5]={1,2,3,4,5};
  ```

#### 6.1.3 数组作为函数参数

- 使用数组名传递数据时，传递的地址
- 如果在被调函数中对形参数组进行改变，那么主调函数中的值也相应改变

#### 6.1.4 对象数组

- 声明数组

  ```c++
  类名 数组名[常量表达式];
  ```

- 访问成员

  ```c++
  数组名[下标表达式].成员名;
  ```

### 6.2 指针

#### 6.2.1内存空间的访问方式

#### 6.2.2 指针变量的声名

- 指针变量是用于存放内存单元地址的

- 语法形式

  ```c++
  数据类型 *标识符;
  ```

  - 其中*表示这里申明的是一个指针类型的变量



### 6.6 字符串

#### 6.6.1 用字符数组存储和处理字符串

- 内存中的存放形式是，按串中字符的排列顺序依次存放，每个字符占一个字节，并在末尾添加'\0'作为结尾标记

  - 字符串常量

    ```
    const char * STRING1="This is a string"
    ```

  - 字符串变量

    ```c++
    char str[8]={'p','r','o','g','r','a','m','\0'};
    char str[9]="program";
    char str[]="program";
    ```

#### 6.6.2 string类

##### 1 构造函数的原型

```c++
string();//默认构造函数 ，建立一个长度为0的字符串
string(const string &rhs);//复制构造函数
string(const char *s);//用指针s指向的字符串常量初始化一个string类的对象
string(const string &rhs,unsigned int pos,unsigned int n);//将rhs中的串从位置pos开始的n个字符初始string类的对象
string(const char *s,unsigned int n);//用指针s指向的字符串中的前n个字符初始化string类的对象
string(unsigned int n,char c);//将参数中c重复n此来初始string类的对象
```

##### 2 string类的操作符

##### 3常用成员函数的功能简介

## ch07 继承与派生

### 7.1 类的继承与派生

#### 7.1.1 继承关系举例

- 类的继承是新类从已有的类哪里得到已有的特性，从已有的类产生新类的过程就是类的派生
- 原有的类叫做基类，产生的类叫做派生类

#### 7.1.2 派生类的定义

- 一个派生类，可以同时有多个基类，称为多继承，一个类只有一个直接基类，成为单继承

```c++
class 派生类名:继承方式 基类1,继承方式 基类2，继承方式 基类3...c++
{
	派生类说明;
}
```

#### 7.1.3 派生类生成过程

- 吸收基类成员
- 改造基类成员
- 添加新的成员

### 7.2 访问控制

#### 7.2.1 公有继承

- 当类的继承方式是共有继承时，基类的公有成员和保护成员的访问属性在派生类中不变，而类的私有成员不可直接访问
- 基类的共有成员和保护成员被继承到派生类中访问属性不变，仍作为派生类的共有成员和保护成员，派生类的其他成员可以直接访问
- 在类外只能通过派生类的对象访问基类的公有成员，无论是派生类的成员还是基类的对象都无法直接访问基类的私有成员

#### 7.2.2 私有继承

- 当类的继承方式是私有继承时，基类的公有成员和保护成员都以为私有成员的身份出现在派生类中，而基类的私有成员在派生类中不可访问
- 派生类的共有成员和保护成员被继承后都作为私有成员，派生类的其他成员可以直接访问，但是类外通过派生类的对象无法直接访问
- 私有继承后，基类的成员无法在以后的派生类中发挥作用

#### 7.2.3 保护继承

- 当类的继承方式是保护继承时，基类的公有成员和保护成员都以为私有成员的身份出现在派生类中，而类的私有成员不可直接访问
- 派生类的其他册灰姑娘原函数可以直接访问基类继承来的共有和保护成员，但在类外通过派生类的对象无法访问

### 7.3 类兼容性规则

```c++
class B{}
class D:public B{}

B b1,*pb1;
D d1;
```

- 派生类的对象可以银海转换为基类指针

  ```c++
  b1=d1;
  ```

- 派生类对象可以初始化基类的引用

  ```c++
  B &rb=d1;
  ```

- 派生类的指针可以隐含转换为基类的指针

  ```c++
  pb1=&d1c
  ```

- 派生类对象可以作为基类对象使用，但只能使用从基类继承来的成员

### 7.4 派生类的构造函数和析构函数

#### 7.4.1 构造函数

- 基类无默认构造函数，基类也无

- 构造派生类对象时，要对基类的成员对象和新增的成员对对象进行初始化

- 基类的构造函数没有被继承过来，由于基类成员大部分无法访问，必须调用基类的构造函数，派生类的构造函数要有参数给基类的构造函数

- 如果基类初始化时需要调用基类带有参数表的构造函数，派生类必须声明构造函数

  ```
  派生类名::派生类名(参数表):基类1(参数表)
  {
  
  }
  ```

-  派生类构造函数的执行一般次序如下

  - 调用基类构造函数，电泳次序按照他们继承的顺序(左->右)
  - 对派生类的新增成员进行初始化，调用顺序是他们在类中声明的顺序
  - 执行派生类中的函数体内容

#### 7.4.2 复制函数

- 一个类如果没有编写复制构造函数，编译系统会自动的自动的生成一个隐含的复制构造函数，并自动的调用基类的复制构造函数，然后对派生类新增对象意义执行复制

#### 7.4.3 析构函数

- 在类的派生过程中，基类的析构函数也不能继承下来，需要虚构的话，要在派生类中声明新的析构函数
- 这些析构函数的调用过程与构造函数的调用次序完全相反

### 7.5 派生类成员的标志与访问

- 在派生类中，成员按照属性划分为以下4种
  - 不可访问的成员
  - 私有成员
  - 保护成员
  - 共有成员

#### 7.5.1 作用域分辨符

- 作用域分辨符 就是:: 它可以用来限定要访问的成员所在的类名称

  ```c++
  类名::成员名
  类名::成员函数名
  ```

- 可见性原则【两个作用域互相包含】

  - 外作用域声明了一个标识符，内作用域没有声明同名的标识符，则外作用域标识符仍然可见
  - 外作用域声明了一个标识符，内作用域声明了同名的标识符，则外作用域标识符不可见

- 类的派生层次

  - 派生类声明了一个和基类同名的新成员，派生的新成员隐藏了外层同名函数，直接使用成员名只能访问到派生类的新成员
  - 派生类声明了一个和基类同名的新函数，即使函数的参数表不同，从基类继承的同名函数所有重载形式也会被隐藏

- 如果某个派生类的多个基类拥有同名的成员，同时，派生类有新增这样的同名函数，派生类成员将隐藏所有基类的同名成员

- 如果派生类不添加新成员，则主函数中对象名.成员名会报错

- 如果某个派生类的部分或全部直接基类都是从另一个共同的基类派生而来的，在这些直接基类中，从上一级继承来的成员拥有相同的名称，因此派生类中也就会产生同名的现象，对这种类型的同名函数也要使用作用域分辨符来唯一标识，而且必须用直接类来标识

#### 7.5.2 虚基类

- 可以将共同基类设为虚基类，这时从不同的路径继承过来的同名数据成员就在内存中只有一个副本，同一个函数名也只有一个映射

  ```c++
  class 派生类名:virtual 继承方式 基类名
  ```

#### 7.5.3 虚基类及其派生类构造函数

- 如果虚基类声明有非默认的构造函数，并且没有声明默认形式的构造函数，在整个继承关系中，直接或间接及策划给你虚基类的所有派生类，都必须通过构造函数的成员初始化列表对需激烈初始化

## ch08 多态性

8.1 多态性概述

### 8.2 运算符重载

- 运算符重载是对已有的运算符赋予多重含义，是同一个运算符作用于不同类型的数据时导致不同的结果

#### 8.2.1 运算符重载的规则

- 只能重载C+已有的运算符
- 重载之后运算符优先级不变
- 不能改变原来的操作对象数量，并且至少一个是自定义类型
- 以下运算符不能重载
  - 类属关系运算符	.
  - 成员指针运算符    .*
  - 作用域运算符    ::
  - 三目运算符    ?:

- 重载为类的成员函数语法

  ```c++
  返回类型 operator 运算符 (形参表)
  {
  	函数体
  }
  ```

- 重载为非成员函数语法

  ```c++
  返回类型 operator 运算符 (形参表)
  {
  	函数体
  }
  ```

  > 当访问设计类的私有成员，可以声明为类的友元函数

> 当重载为类的成员函数时，函数的参数个数比原来的操作数少一个(后置”++”、 "--除外)
>
> 当重载为非成员函数时，函数的参数个数不变

#### 8.2.2 运算符重载为成员函数

- 对于双目运算符B，使之能够实现oprd1 B oprd2 其中 oprd1 是A类的对象，则应该把B重载为A的成员函数，该函数只有一个形参，类型是oprd2所属的类型，表达式oprd1 B oprd2相当于 oprd1.operator B(oprd2)
- 对于前置单目运算符 U，如“一”(负号)等，使之能够实现 U oprd，其中oprd是A的对象，则应该把U重载为A的成员函数，函数没有参数，表达式U oprd相当于 oprd.operator U()
- 对于后置运算符”++“、"--",用来实现 oprd++或oprd--，其中oprd是A类的对象，应该运算符重载为A的成员函数，这时候函数需要一个zhengxing(int)类型的形参，表达式oprd++和oprd--就相当于 oprd.operator++(0)和oprd.operator--(0)，其中0不起作用，只是区别前置和后置

#### 8.2.3 运算符重载为非成员函数

- 对于双目运算符B，如果要实现 oprd1 B oprd2 ,其中oprd1和 oprd2中只要有一个具有自定义类型，就可以将B重载为非成员函数,函数的形参为oprd1 和 oprd2。经过重载之后，表达式oprdl B oprd2就相当于函数调用operator B(oprd1,oprd2)

- 对于前置单目运算符U，如“一”(负号)等，如果要实现表达式U oprd，其中 oprd 具有自定义类型，就可以将U重载为非成员函数,函数的形参为oprd。经过重载之后，表达式U oprd相当于函数调用operator U(oprd)
  对于后置运算符十＋和一—，如果要实现表达式 oprd ++或 oprd--，其中oprd为自定义类型,那么运算符就可以重载为非成员函数。这时函数的形参有两个，一个是oprd，另一个是 int类型形参。第二个参数是用于与前置运算符函数相区别的。重载之后，表达式 oprd ＋＋和 oprd--就相当于函数调用operator ++（oprd,0)和operator--(oprd,0)

  > 重载<<运算符时，第一个运算符必须是ostream，因此必须重载为友元函数

### 8.3 虚函数

- 虚函数是动态绑定的基础，虚函数必须是非静态的成员函数，一般不声明为内联函数
  - 构造函数为虚函数赋值
  - 通过虚指针找到虚表，在虚表中找到虚函数入口地址
  - 通过入口地址调用虚函数
- 虚表
  - 每个多态基类有一个虚表
  - 虚表存放各个虚函数的地址
  - 每个对象存放只想虚表的指针(虚指针)

#### 8.3.1 一般虚函数成员

```c++
virtual 函数类型 函数名(形参表);
```

- 虚函数声明只能在类的实现中的函数原型中，不能在成员函数实现的时候
- 运行时多态满足以下三个条件
  - 类之间的兼容性
  - 声明虚函数
  - 由成员函数来调用或者指针、引用来访问虚函数
- 遵循以下规则来判断是不是派生类的一个成员函数是不是虚函数
  - 有相同的名称
  - 有相同的参数个数及相同的对应参数类型
  - 相同的返回值或者满足肤质兼容类型规则的的指针，引用类型的返回值

- 满足以上条件会被自动认定为虚函数，派生类的基函数便覆盖了基类的虚函数
- 派生类的虚函数还会覆盖基类同名函数的其他所有重载形式

> 派生类覆盖基函数的成员函数时候，即可以使用virtual关键字，也可以不使用，而这没有区别

#### 8.3.2 虚析构函数

- 不能声明虚构造函数，但可以声明虚析构函数

- ```c++
  virtual ~类名();
  ```

- 基类的析构函数是虚函数，那么由他派生来的所有子类析构函数都是虚函数
- 如果有可能通过基类指针调用对象的而析构函数(通过delete)，就需要让基类的析构函数成为虚函数，否则会产生不确定后果
- 通过基类指针 删除派生类对象时调用的时基类的析构函数

### 8.4 纯虚函数与抽象类

#### 8.4.1 纯虚函数

- 纯虚函数的声明格式

  ```c++
  virtual 函数类型 函数名(参数表)=0;
  ```

- 声明纯虚函数之后，基类中就不能再给出函数的而实现部分，即使给出了，也会被派生类覆盖，无法实例化

#### 8.4.2 抽象类

- 带有纯虚函数的类时抽象类，通过它作为一个新类建立一个公共接口，是他们能够有效的发挥多态性
- 只能做基类，不能定义抽象类对象，不能实例化