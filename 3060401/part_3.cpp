#include <iostream>
using namespace std;

class A
{
private:
    int nVal;

public:
    void Fun() //静态绑定（非虚函数）
    {
        cout << "A::Fun" << endl;
    }

    virtual void Do() //虚函数 Do，它支持动态绑定
    {
        cout << "A::Do" << endl;
    }
};

class B : public A
{
public:
    virtual void Do() //重写了虚函数 Do
    {
        cout << "B::Do" << endl;
    }
};

class C : public B
{
public:
    void Do() //重写了虚函数 Do
    {
        cout << "C::Do" << endl;
    }

    void Fun()
    {
        cout << "C::Fun" << endl;
    }
};

void Call(
    // 在此处补充你的代码 - 为了支持动态多态，Call 函数的参数需要是基类指针。通过基类指针，虚函数调用时会动态绑定到派生类的版本
    A* p // 参数为基类指针，A* 可以指向 A、B 或 C 的对象，提供了一个统一的接口
    /*假设 Call 函数的参数改为 C*：
    * 调用 Call(new A()) 会报错，因为 A* 无法隐式转换为 C*，Call 函数无法接收 A 类型的对象。
    * 调用 Call(new B()) 同样会报错，因为 B* 无法隐式转换为 C*，函数无法接收 B 类型的对象。
    * 只有 Call(new C()) 可以正常工作，但这就丧失了对多态的支持。
     */
)
{
    p->Fun(); //静态绑定，调用时根据「指针的静态类型」确定调用哪个版本
    p->Do(); //动态绑定，调用时根据「指针指向的实际对象类型」确定调用哪个版本
}

int main()
{
    Call(new A()); //指针 p 的静态类型是 A*。Fun 是非虚函数，因此调用 A::Fun。p 指向的实际对象是 A。Do 是虚函数，因此调用 A::Do
    Call(new C()); //指针 p 的静态类型是 A*。Fun 是非虚函数，因此调用 A::Fun。p 指向的实际对象是 C。Do 是虚函数，因此调用 C::Do

    //通过基类指针（A*），我们可以写出更通用的代码。例如：
    A* objects[] = {new A(), new B(), new C()};

    for (A* obj: objects)
    {
        Call(obj);
    }
    /*这里，Call 函数会根据每个对象的实际类型动态调用对应的虚函数。多态让我们不需要关心具体对象的类型，代码更加简洁灵活。*/

    return 0;
}
