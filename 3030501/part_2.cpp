#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }//这种写法叫做 初始化列表（initializer list），是 C++ 构造函数的一种特殊用法
// 在此处补充你的代码
    // 自定义的拷贝构造函数，复制对象时将 v 的值乘以 2
    Sample(const Sample& other) : v(other.v * 2) { }
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v; // 输出 10，这会调用「拷贝构造函数」
    return 0;
}
