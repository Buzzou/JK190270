//
// Created by Ruohao L. on 30/11/2024.
//
#include <iostream>
using namespace std;
// 在此处补充你的代码
// CType 类定义
class CType
{
private:
    int value; // 存储整数值

public:
    // 设置值的方法
    void setvalue(int n)
    {
        value = n;
    }

    // 重载后置自增运算符 - 遵循后置自增的语义，即返回自增前的值，但对象的状态需要自增后更新
    CType operator++(int)
    {
        CType temp = *this; // 保存当前对象的副本
        value = value * value; // 自增后将值更新为平方
        return temp; // 返回自增前的对象
    }

    // 重载插入运算符，支持 cout << obj
    //使用 friend 使其成为一个全局函数（并不是类的成员），但被赋予了访问类的私有成员的权限
    //对于成员函数，左操作数必须是该类的对象

    friend ostream& operator<<(ostream& os, const CType& obj)
    {
        os << obj.value; // 输出存储的值
        return os;
    }

    /*如果将 operator<< 定义为 CType 的成员函数，调用它时，语法会变成：
         * obj << cout; // 这显然是违背直觉的！
    */
    ostream& operator<<(ostream& os) const
    //这样，左操作数必须是 CType 对象，而不是 ostream，我们将无法用 cout << obj 的方式输出
    {
        os << value; // 假设有私有成员 value
        return os;
    }
};

int main()
{
    CType obj;
    int n;
    cin >> n;
    while (n)
    {
        obj.setvalue(n); // 设置初始值
        cout << obj++ << " " << obj << endl; // 输出自增前后的值
        cin >> n;
    }
    return 0;
}
