### C++基础
**1. const用法**
- 修饰变量，被修饰的变量不能被修改，当所修饰的是一个对象的时候，该对象仅能调用被const修饰的方法；
- 用来修饰函数参数，表示禁止对参数的修改，在传值的时候没有意义，一般搭配指针或者引用，表示指针或者引用所指向的对象不能被修改，使用cosnst+引用做形参，既避免了拷贝，又避免了对值的修改，const修饰指针或者引用的时候是可以用来区别重载的；
- 用来修饰成员方法，代表该方法不能修改对象里面的成员，实际上是const object* const this；
- 用来修饰返回值，同样搭配指针或引用来使用，表示返回值所指向或引用的对象不能被修改，实质上就是是的函数表达式不能被用来当做左值；

**2. 顶层const与底层const**
- 底层const，典型的是常量指针，const int* p,p是一个指针，指向一个常量，这里定义的常量指针就是底层const，无法通过这个指针来改变指向的对象的值；
- 顶层const，典型的是指针常量，int * const p，指针常量是一个常量，即指针本身是常量，不能被修改，必须在定义时赋初值，他存储的地址值不能被修改，指针常量即是一个顶层const，此时可以改变指向的地址的值;
- 用途：根据《C++primer》的解释，区分顶层const和底层const有两个用处：
> 1.在执行对象的拷贝时，需要能区分对象是顶层const还是底层const，拷贝时顶层const一般不受什么影响，但在执行对象的拷入和拷出时，对象必须具有相同的底层const资格，或者两个对象的数据类型能够转换，在进行类型转换时，非常量可以转换成常量，反之则不行；\
> 2.在进行const_cast类型转换时，const_cast仅能改变对象的底层const；

**3. static用法**
- 修饰变量和函数，用于限定作用域，仅在本文件中可见，。static修饰的变量在在静态区，仅仅被初始化一次，在整个程序运行期间都不会被销毁；
- 修饰类成员和方法，修饰类成员时，需要在类外初始化，且这个静态成员被所有对象共享，static方法为类方法，不需要实例化对象即可调用，但static方法只能调用类的static成员；

**4. define和const**
- define执行宏替换，发生在预处理阶段，直接进行文本替换，而const发生在编译阶段；
- 宏定义不进行类型检查，而const会进行类型检查；
- const定义了一个值不能被改变的变量，会占用空间，而宏定义不会占用空间；

**5. define和typedef**
- define执行宏替换，发生在预处理阶段，直接进行文本替换，typedef用于定义类型别名，在编译期间被解释；
- 宏定义不会进行类型检查，typedef会进行类型检查；

**6. 宏定义和函数**
- 宏定义直接进行文本替换，相当于直接插入代码，不存在函数调用，执行更快，而且没有返回值，函数需要进入函数体调用，并且有返回值；
- 宏定义中的函数参数是没有类型的，函数参数具有类型；

**7. 内联函数**
- 使用内联函数时，编译器将使用相应的函数代码来替换函数调用，因此，内联函数比一般函数速度要快，但需要占用更多内存；
- 与宏定义相比，内联函数在编译期展开，并进行类型检查，且有返回值，内联函数是一个函数，有函数特性，支持重载等操作，在类内部实现的成员函数一般被定义为内联函数；

**8. malloc、free和new、delete**
- malloc和free是C语言提供的函数，仅仅为对象开辟空间，而不会执行初始化，返回一个void类型指针，需要手动进行类型转换；
- new和delete是C++提供的运算符，在为对象开辟空间后，还会自动调用构造函数

**9. 类中的this指针**
- this 指针是一个隐含于每一个非静态成员函数中的特殊指针。它指向调用该成员函数的那个对象；
- 当调用一个对象的成员函数时，编译程序先将对象的地址赋给 this 指针，然后调用成员函数，每次成员函数存取数据成员时，都隐含使用 this 指针；
- 当一个成员函数被调用时，自动向它传递一个隐含的参数，该参数是一个指向这个成员函数所在的对象的指针；
- this 指针被隐含地声明为: typename* const this，这意味着不能给 this 指针赋值；在类的 const 成员函数中，this 指针的类型为：const type* this const，这说明不能对 this 指针所指向的这种对象是不可修改的（即不能对这种对象的数据成员进行赋值操作）；
this并不是一个常规变量，而是个右值，所以不能取得 this的地址（不能 &this）。
- 在以下场景中，经常需要显式引用 this 指针： 
   - 为实现对象的链式引用；
   - 为避免对同一对象进行赋值操作；
   - 在实现一些数据结构时，如 list；

**10. volatile关键字**
- volatile告诉编译器，这个对象很有可能会被某些未知因素，如多线程访问，操作系统等更改，要求编译器不要对其做出优化，因为编译器在默认情况下可能会将非volatile修饰的变量放入寄存器中，而volatile修饰的变量每次都从内存中取值；

**11. sizeof()**
- sizeof是一个运算符而非函数，在编译期间即得出结果；

**13. struct和class**
- C++中struct和class最大的区别就是默认访问权限，class为private，struct为public

**14. struct和union**
- 联合（union）是一种节省空间的特殊的类，一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。当某个成员被赋值后其他成员变为未定义状态；
- struct是一个默认权限为public的类，其他性质与clas类似，struct每一个成员独立占用空间，而且一般都需要做内存对齐；

**15. explicit和implicit**
- Explicit关键字声明必须通过转换来调用的用户定义的类型转换运算符。不同于隐式转换，显式转换运算符必须通过转换的方式来调用，如果缺少了显式的转换，在编译时就会产生错误；
- implicit关键字用于声明隐式的用户定义类型转换运算符。它可以实现2个不同类的隐式转换 ，提高代码的可读性。但是需要注意使用隐式转换操作符之后，在编译时会跳过异常检查，所以隐式转换运算符应当从不引发异常并且从不丢失信息，否则在运行时会出现一些意想不到的问题；

**15. 变长参数**
- 以printf为例，他是一个具有变长参数的函数，他的原型为:
```cpp 
    printf(const char *format, ...)
```
- 在声明变长参数时，我们用到...这个符号和使用到三个宏va_start,va_arg 和va_end；
- 未完

### 面向对象
1. 面向对象的特性
- 封装
    - 封装可以隐藏实现细节，使得代码模块化；封装是把数据和方法隐藏起来，对数据的访问只能通过已定义的接口。面向对象计算始于这个基本概念，即现实世界可以被描绘成一系列完全自治、封装的对象，这些对象通过一个受保护的接口访问其他对象。在面向对象编程上可理解为：把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，而隐藏内部的实现细节；
- 继承
     - 继承是指这样一种能力：它可以使用现有类的所有功能，并在无需重新编写原来的类的情况下对这些功能进行扩展。其继承的过程，就是从一般到特殊的过程。通过继承创建的新类称为“子类”或“派生类”。被继承的类称为“基类”、“父类”或“超类”。要实现继承，可以通过“继承”（Inheritance）和“组合”（Composition）来实现。在某些 OOP 语言中，一个子类可以继承多个基类。

- 多态
    - 可以简单概括为“一个接口，多种方法”，即用的是同一个接口，但是效果各不相同，多态有多种形式的多态，大体上可分为静态多态和动态多态，即编译期多态和运行期多态，可细分如下：
        - 重载多态（Ad-hoc Polymorphism，编译期）：函数重载、运算符重载
        - 子类型多态（Subtype Polymorphism，运行期）：虚函数
        - 参数多态性（Parametric Polymorphism，编译期）：类模板、函数模板
        - 强制多态（Coercion Polymorphism，编译期/运行期）：基本类型转换、自定义类型转换
    
2. 类的访问权限

3. 覆盖、重载、隐藏

4. 构造函数和析构函数

5. 虚函数的实现

6. 虚继承的实现

7. 类的内存对齐

8. 类的内存分布

9. 深拷贝与浅拷贝

10. 重载和模板


### C++11
1. 类型推导(RTTI)

2. 智能指针(RAII)
- 智能指针

3. 右值引用、移动语义和完美转发
- forward和move\
    **先说结论**
    - std::move执行到右值的无条件转换。就其本身而言，它没有move任何东西
    - std::forward只有在它的参数绑定到一个右值上的时候，它才转换它的参数到一个右值
    - std::move和std::forward只不过就是执行类型转换的两个函数；std::move没有move任何东西，std::forward没有转发任何东西。在运行期，它们没有做任何事情。它们没有产生需要执行的代码，一byte都没有
    - std::forward<T>()不仅可以保持左值或者右值不变，同时还可以保持const、Lreference、Rreference、validate等属性不变

- move实现
```cpp
    template<class T> typename remove_reference<T>::type&&
    std::move(T&& a) noexcept
    {
        typedef typename remove_reference<T>::type&& RvalRef;
        return static_cast<RvalRef>(a);
    }
```
- foward实现
```cpp
    template<class S>
    S&& forward(typename remove_reference<S>::type& a) noexcept
    {
        return static_cast<S&&>(a);
    }
```

4. lambda、function和bind

5. 多线程

6. 锁和条件变量


### effictive C++


