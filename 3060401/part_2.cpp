#include <iostream>
using namespace std;

class A /*使用 final 关键字标记类，可以明确表示它不会被继承*/
{
    // 在此处补充你的代码
public:
    virtual ~A()
    {
        // 虚析构函数 - 为了确保在多态情况下基类指针正确调用派生类的析构函数，基类析构函数必须声明为 virtual
        // 现代 C++ 静态分析工具（如 clang-tidy 或 Visual Studio 分析器）可以帮助检查基类析构函数是否需要声明为虚函数
        cout << "destructor A" << endl;
    }
};

class B : public A
{
public:
    ~B()
    {
        // 派生类的析构函数
        cout << "destructor B" << endl;
    }
};

int main()
{
    A* pa;
    pa = new B; // 创建一个 B 类型对象
    delete pa; // 删除对象:如果 A 中的析构函数不是虚函数，执行 delete pa 时只会调用 A 的析构函数，而不会调用派生类 B 的析构函数
    /*使用智能指针（如 std::shared_ptr 或 std::unique_ptr），可以避免手动调用 delete，从而减轻析构函数的多态问题*/
    return 0;
}
