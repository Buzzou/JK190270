//
// Created by Ruohao L. on 01/12/2024.
//
//TODO:多态非常好的例子
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

// 基类 A，表示类别 A 的人
class A
{
protected: //公共属性
    int age; // 年龄
public:
    A(int age) : age(age) {} // 构造函数
    //提供虚析构函数，确保销毁派生类对象时正确释放资源
    virtual ~A() {} // 虚析构函数，保证派生类对象能正确销毁

    int getAge() const { return age; } // 获取年龄
    //提供虚函数 print，以实现动态绑定（多态）
    virtual void print() const
    {
        // 打印 A 类信息
        cout << "A " << age << endl;
    }
};

// 派生类 B，表示类别 B 的人
class B : public A
{
public:
    B(int age) : A(age) {} // 调用基类构造函数
    //重写 print 方法输出 B 的类别信息
    void print() const override
    {
        // 重写打印函数
        cout << "B " << age << endl;
    }
};

// 比较器，用于 set 的排序规则 - 按年龄排序 - 按 A 类的 age 属性升序排列
struct Comp
{
    bool operator()(const A* a1, const A* a2) const
    {
        return a1->getAge() < a2->getAge(); // 按年龄升序排序
    }
};

// 打印函数，用于输出所有人的信息 - 由多态机制决定实际调用的是 A::print 或 B::print
void Print(const A* person)
{
    person->print();
}

int main()
{
    int t; // 组数
    cin >> t;
    // 使用 set<A*>，我们就可以在同一个容器中存储 A 和 B 两种类型的对象
    // 如果直接存储对象（值类型 A），set 的类型是 set<A>，就无法插入 B 类型的数据，因为 B 是 A 的派生类，直接存储会导致派生类丢失特性（对象切割）
    set<A*, Comp> ct; // 用 set 自动排序
    /*如果直接存储对象（值类型）：
     * set<A> ct;
       ct.insert(B(10)); // B 被切割成 A，丢失 B 类特有的行为
       for (const auto& person : ct) {
           person.print(); // 始终调用 A::print
       }
*/
    /*使用指针（存储多态对象）：
    * set<A*, Comp> ct;
      ct.insert(new B(10)); // B 仍然完整，具有 B 的行为
      for (auto person : ct) {
          person->print(); // 动态绑定，调用 B::print
      }
     */
    while (t--)
    {
        int n; // 每组数据的数量
        cin >> n;
        ct.clear(); // 清空 set
        for (int i = 0; i < n; ++i)
        {
            char c;
            int k;
            cin >> c >> k;
            // 根据类别动态创建对象，并插入 set
            if (c == 'A')
                ct.insert(new A(k)); // 插入 A 类对象
            else
                ct.insert(new B(k)); // 插入 B 类对象
        }
        // 输出当前组数据 - 由多态机制决定实际调用的是 A::print 或 B::print
        // 通过基类(A类)指针才能调用基类和派生类中的同名虚函数
        for_each(ct.begin(), ct.end(), Print);
        cout << "****" << endl;

        // 清理当前组内存 - 因为 set 存储的是动态分配的指针，需手动释放内存
        for (auto person: ct)
        {
            delete person;
        }
    }
    return 0;
}
