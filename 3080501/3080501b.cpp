//
// Created by Ruohao L. on 27/11/2024.
//
#include <iostream>
#include <map>
#include <set>
#include <iterator>
using namespace std;

map<int, multiset<int> > sequences; // 存储序列编号和对应的 multiset

void processCommand(const string& command)
{
    string op;
    int id, id1, id2, num;
    if (command.substr(0, 3) == "new")
    {
        sscanf(command.c_str(), "new %d", &id);
        sequences[id] = multiset<int>(); // 新建空序列
    }
    else if (command.substr(0, 3) == "add")
    {
        sscanf(command.c_str(), "add %d %d", &id, &num);
        sequences[id].insert(num); // 插入元素
    }
    else if (command.substr(0, 5) == "merge")
    {
        sscanf(command.c_str(), "merge %d %d", &id1, &id2);
        sequences[id1].insert(sequences[id2].begin(), sequences[id2].end()); // 合并序列
        sequences[id2].clear(); // 清空 id2
    }
    else if (command.substr(0, 6) == "unique")
    {
        sscanf(command.c_str(), "unique %d", &id);
        set<int> uniqueSet(sequences[id].begin(), sequences[id].end()); // 去重
        sequences[id] = multiset<int>(uniqueSet.begin(), uniqueSet.end()); // 重建 multiset
    }
    else if (command.substr(0, 3) == "out")
    {
        sscanf(command.c_str(), "out %d", &id);
        for (int val: sequences[id])
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符
    for (int i = 0; i < n; ++i)
    {
        string command;
        getline(cin, command);
        processCommand(command);
    }
    return 0;
}
