#include <iostream>
using namespace std;

class A
{
private:
    int nVal;

public:
    void Fun()
    {
        cout << "A::Fun" << endl;
    }

    void Do()
    {
        cout << "A::Do" << endl;
    }
};

class B : public A
{
public:
    virtual void Do()
    {
        cout << "B::Do" << endl;
    }
};

class C : public B
{
public:
    void Do()
    {
        cout << "C::Do" << endl;
    }

    void Fun()
    {
        cout << "C::Fun" << endl;
    }
};

void Call(
    // 在此处补充你的代码 - 传引用 -> 保留动态多态性
    A& p)
{
    p.Fun(); //Fun 在基类 A 中不是虚函数。调用时，直接调用的是 A 的版本
    p.Do(); //调用 p.Do() 时，由于 Do 是虚函数，动态绑定到 C 的版本，因此输出 C::Do
}

int main()
{
    C c;
    Call(c);
    return 0;
}
