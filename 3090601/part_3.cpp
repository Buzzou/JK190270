//
// Created by Ruohao L. on 28/11/2024.
//
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> history; // 用于存储曾经加入过的元素
    multiset<int> current; // 用于存储当前集合的元素（包括重复）

    for (int i = 0; i < n; ++i)
    {
        string command;
        int x;
        cin >> command >> x;

        if (command == "add")
        {
            current.insert(x); // 插入到 multiset
            history.insert(x); // 插入到 history
            cout << current.count(x) << endl; // 输出当前 x 的个数
        }
        else if (command == "del")
        {
            cout << current.count(x) << endl; // 输出当前 x 的个数
            current.erase(x); // 删除所有的 x
        }
        else if (command == "ask")
        {
            cout << (history.count(x) ? 1 : 0) << " "; // 是否曾加入过
            cout << current.count(x) << endl; // 当前的个数
        }
    }

    return 0;
}
