//
// Created by Ruohao L. on 30/11/2024.
//
//TODO:优雅的语法
#include <iostream>
#include <string>
#include <list>
using namespace std;

class A
{
private:
    string name;

public:
    A(string n) : name(n) {}

    // 按长度排序规则
    friend bool operator<(const A& a1, const A& a2)
    {
        return a1.get_size() < a2.get_size();
    }

    // 判断是否长度相等（未用到）
    friend bool operator==(const A& a1, const A& a2)
    {
        return a1.name.size() == a2.name.size();
    }

    // 输出重载
    friend ostream& operator<<(ostream& o, const A& a)
    {
        o << a.name;
        return o;
    }

    string get_name() const { return name; }

    /*未来如果类的实现需要改变，比如：
    改为一个更加复杂的逻辑来计算字符串长度（例如去掉空格后再计算）。
    或者 name 换成了一个更复杂的存储方式，不再是 std::string。
    那么，只需要修改 get_size() 的实现，而不需要修改每个直接访问 name.size() 的地方。这样的设计使代码更容易维护和扩展
    */
    /*且，看到 get_size()，开发者一眼就知道这是一个与类的“大小”相关的操作，而不需要关心 name.size() 是怎么计算的。
    如果直接使用 name.size()，会让代码依赖于具体的实现细节，降低可读性*/
    int get_size() const { return name.size(); }
};

// 显示容器内容
template<typename Iterator, typename Func>
void Show(Iterator begin, Iterator end, Func print)
{
    for (Iterator it = begin; it != end; ++it)
    {
        print(*it);
    }
}

// 定义打印函数对象
struct Print
{
    void operator()(const A& a) const { cout << a << " "; }
};

// 按首字符 ASCII 排序规则
template<typename T>
struct MyLarge
{
    bool operator()(const T& a, const T& b) const
    {
        return a.get_name()[0] < b.get_name()[0];
    }
};

int main(int argc, char* argv[])
{
    list<A> lst;
    int ncase, n, i = 1;
    string s;
    cin >> ncase;

    while (ncase--)
    {
        cout << "Case: " << i++ << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            lst.push_back(A(s));
        }

        // 按长度排序
        lst.sort();
        Show(lst.begin(), lst.end(), Print());
        cout << endl;

        // 按首字符排序
        lst.sort(MyLarge<A>());
        Show(lst.begin(), lst.end(), Print());
        cout << endl;

        lst.clear();
    }
    return 0;
}
