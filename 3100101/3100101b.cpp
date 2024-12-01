//
// Created by Ruohao L. on 30/11/2024.
//
#include <iostream>
using namespace std;

class Number
{
public:
    int num;

    // 构造函数
    Number(int n) : num(n) {}
    // 在此处补充你的代码
    // 返回对 num 的引用既能返回 num 的值（用于输出），又支持对 num 进行修改（例如 a.value() = 8）
    int& value()
    {
        return num;
    }

    // 重载 + 运算符
    void operator+(const Number& other)
    {
        this->num += other.num;
    }
};

int main()
{
    Number a(2);
    Number b = a; //调用的是默认拷贝构造函数，b.num 是 a.num 的副本

    // 输出 a 和 b 的值
    cout << a.value() << endl; // 输出 2
    cout << b.value() << endl; // 输出 2

    // 修改 a 的值
    a.value() = 8;
    cout << a.value() << endl; // 输出 8

    // 使用 a + b，修改 a 的值
    a + b;
    cout << a.value() << endl; // 输出 10

    return 0;
}
