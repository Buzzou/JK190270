//
// Created by Ruohao L. on 30/11/2024.
//
#include <iostream>
using namespace std;

class Number
{
public:
    int num;

    Number(int n = 0) : num(n) {} // 构造函数
    // 在此处补充你的代码
    // 重载乘法运算符
    Number operator*(const Number& other)
    {
        return Number(this->num * other.num);
    }

    // 重载类型转换运算符 - 将 Number 对象转换为其内部存储的 num
    operator int() const
    {
        return this->num;
    }
};

int main()
{
    Number n1(10), n2(20);
    Number n3;
    n3 = n1 * n2;
    cout << int(n3) << endl; // 输出结果：200
    return 0;
}
