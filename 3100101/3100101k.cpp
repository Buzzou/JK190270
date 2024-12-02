//
// Created by Ruohao L. on 01/12/2024.
//
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
// 自定义模板类
template<class Key, class Value, class Compare = greater<Key> >
class MyMultimap
{
public:
    using MultimapType = multimap<Key, Value, Compare>;
    using iterator = typename MultimapType::iterator;

private:
    MultimapType data;

public:
    // 插入数据
    void insert(const pair<Key, Value>& p)
    {
        data.insert(p);
    }

    // 查找指定键
    iterator find(const Key& key)
    {
        return data.find(key);
    }

    // 清空数据
    void clear()
    {
        data.clear();
    }

    // 返回起始迭代器
    iterator begin()
    {
        return data.begin();
    }

    // 返回结束迭代器
    iterator end()
    {
        return data.end();
    }

    // 修改所有指定键的值
    void Set(const Key& key, const Value& newValue)
    {
        for (iterator it = data.begin(); it != data.end(); ++it)
        {
            if (it->first == key)
            {
                it->second = newValue;
            }
        }
    }

    // 修改所有指定值的键
    // 在 std::multimap 中，键 (key) 的值是不可修改的。它们是由 std::map 或 std::multimap 的底层实现所约束的
    // 这一限制确保了容器的内部数据结构（如红黑树）的顺序性不会因为修改键而被破坏
    // 如果需要修改键，则必须删除原始元素并重新插入新键值对。这是因为插入操作会重新构建红黑树，确保容器保持有序性
    void Set(const Value& value, const Key& newKey)
    {
        for (iterator it = data.begin(); it != data.end(); ++it)
        {
            if (it->second == value)
            {
                auto node = *it; // 保存当前值
                data.erase(it); // 删除当前元素
                node.first = newKey; // 修改键
                data.insert(node); // 重新插入
                /*在 STL 容器中，erase 操作可能会使迭代器失效，因此在删除后需要重置迭代器以确保后续操作的正确性。重置迭代器的方式如下：
                 *如果在循环中使用 erase，通常需要设置迭代器为下一元素的位置。
                 *在本例中，因为可能需要重新插入，所以重新设置为 begin() 以确保安全*/
                it = data.begin(); // 重置迭代器
            }
        }
    }
};

// 打印函数
template<class T>
void Print(T first, T last)
{
    for (; first != last; ++first)
        cout << "(" << first->first << "," << first->second << "),";
    cout << endl;
}

// 学生结构体
struct Student
{
    string name;
    int score;
};

int main()
{
    // 初始化学生数据
    Student s[] = {{"Tom", 80}, {"Jack", 70}, {"Jone", 90}, {"Tom", 70}, {"Alice", 100}};
    MyMultimap<string, int> mp;

    // 插入数据
    for (int i = 0; i < 5; ++i)
        mp.insert(make_pair(s[i].name, s[i].score));
    Print(mp.begin(), mp.end()); // 按姓名从大到小输出

    mp.Set("Tom", 78); // 修改所有名为 "Tom" 的学生的成绩
    Print(mp.begin(), mp.end());

    MyMultimap<int, string, less<int> > mp2;
    for (int i = 0; i < 5; ++i)
        mp2.insert(make_pair(s[i].score, s[i].name));
    Print(mp2.begin(), mp2.end()); // 按成绩从小到大输出

    mp2.Set(70, "Error"); // 修改所有成绩为 70 的学生的名字
    Print(mp2.begin(), mp2.end());

    cout << "******" << endl;

    // 动态输入部分
    mp.clear();
    string name, cmd;
    int score;

    while (cin >> cmd)
    {
        if (cmd == "A")
        {
            // 添加
            cin >> name >> score;
            if (mp.find(name) != mp.end())
            {
                cout << "error" << endl;
            }
            else
            {
                mp.insert(make_pair(name, score));
            }
        }
        else if (cmd == "Q")
        {
            // 查询
            cin >> name;
            auto it = mp.find(name);
            if (it != mp.end())
            {
                cout << it->second << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
        }
    }

    return 0;
}
