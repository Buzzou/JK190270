#include <iostream>
using namespace std;
class A {
public:
    int val;
// 在此处补充你的代码
    A() : val(0) {}               // 无参构造函数，初始化 val 为 0
    int& GetObj() { return val; }  // 返回 val 的引用（别名，也就是它本身。而不是它的地址！），以便可以对其直接赋值
    //或者int* GetObj() { return &val; }，直观上更好理解
};
int main()  {
    A a;
    cout << a.val << endl; // 输出 0
    a.GetObj() = 5;//因为 GetObj 返回 val 的引用，所以 a.GetObj() 实际上就是 a.val 的 别名，相当于直接操作 a.val
    //line13等价于 a.val = 5;
    cout << a.val << endl; // 输出 5
}
