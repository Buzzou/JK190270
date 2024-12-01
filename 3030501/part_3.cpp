#include <iostream>
using namespace std;

class Base
{
public:
    int k;
    Base(int n): k(n) {} //带参数的构造函数 Base(int n) : k(n)，用来初始化 k
};

class Big
{
public:
    int v;
    Base b;
    // 在此处补充你的代码
    // 构造函数：将 v 和 b.k 都初始化为 n
    Big(int n) : v(n), b(n) {}

    // 拷贝构造函数：将 other 的 v 和 b.k 值复制到当前对象
    Big(const Big& other) : v(other.v), b(other.b) {}
};

int main()
{
    Big a1(5); //用参数 5 创建了 a1。这里需要一个带有参数的构造函数 Big(int n)，可以用一个整数参数 n 初始化 Big 对象
    Big a2 = a1; //这需要一个 拷贝构造函数，让a2.v 和 a2.b.k 都等于 a1.v 和 a1.b.k
    cout << a1.v << "," << a1.b.k << endl; //要求 v 和 b.k 都被初始化为 n
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}
