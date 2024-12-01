//
// Created by Ruohao L. on 01/12/2024.
//
//TODO：通过 new 和 delete 演示对象的生命周期 - 动态分配和释放内存会触发构造和析构
#include <iostream>
#include <map>
using namespace std;

// 在此处补充你的代码
class A
{
public:
    static int count; // 记录A及其派生类的对象个数

    // 构造函数
    A()
    {
        count++;
    }

    A(int x)
    {
        count++;
    }

    // 虚析构函数，确保派生类的析构函数被正确调用
    virtual ~A()
    {
        cout << "A::destructor" << endl;
        count--;
    }
};

class B : public A
{
public:
    // 构造函数
    B(int x) : A(x) {}

    // 析构函数
    ~B()
    {
        cout << "B::destructor" << endl;
    }
};

int A::count = 0; // 初始化静态变量 - 用于记录当前存在的 A 或 A 派生类的实例个数

void func(B b) {}

int main()
{
    A a1(5), a2; //调用 A(int x) 构造函数，count = 1；调用默认构造函数，count = 2
    cout << A::count << endl; //输出 2
    B b1(4); //创建一个 B 类对象，调用 B(int x) 构造函数；B 的构造函数会调用基类 A(int x) 构造函数
    cout << A::count << endl; //输出 3
    func(b1); //func 的参数是按值传递，会调用拷贝构造函数
    /*临时对象会被销毁，调用析构函数，输出：
     *B::destructor
     *A::destructor*/
    cout << A::count << endl; //临时对象销毁后，count = 3
    A* pa = new B(4); //动态分配一个 B 对象，调用 B(int x) 构造函数
    cout << A::count << endl; //输出 4
    delete pa; //释放动态分配的对象；pa 是 A* 类型，调用虚析构函数，先销毁 B，再销毁 A
    /*B::destructor
     *A::destructor*/
    cout << A::count << endl; //输出 3
    return 0; //程序结束时销毁静态对象
    /*静态对象按声明的逆序依次销毁：
     *b1：调用 B::destructor 和 A::destructor
     *a2 和 a1：调用 A::destructor*/
    /*输出：
    * B::destructor
    * A::destructor
    * A::destructor
    * A::destructor
     */
}
