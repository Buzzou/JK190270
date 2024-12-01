#include <iostream>
using namespace std;

class MyInt
{
    int nVal; // 存储值的成员变量
public:
    // MyInt(int n) { nVal = n; } // 构造函数初始化成员变量
    MyInt(int n): nVal(n) {} // 构造函数初始化成员变量
    int ReturnVal() { return nVal; } // 返回成员变量 nVal
    // 在此处补充你的代码
    // 重载 - 运算符
    MyInt &operator-(int x)
    {
        nVal -= x; // 减去参数 x
        return *this; // 返回当前对象引用(如果返回的是值对象(即拷贝)，那么链式调用中的下一次操作会作用于拷贝，而不是原始对象，导致逻辑错误)
    }
};

int main()
{
    MyInt objInt(10); // 创建 MyInt 对象，初始值为 10
    objInt - 2 - 1 - 3; // 连续调用减法
    cout << objInt.ReturnVal(); // 输出 4
    cout << ",";
    objInt - 2 - 1; // 连续调用减法
    cout << objInt.ReturnVal(); // 输出 1
    return 0;
}
