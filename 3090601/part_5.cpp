//
// Created by Ruohao L. on 28/11/2024.
//
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<pair<int, int> > members; // 用于存储会员信息 (实力值, ID)
    members.insert({1000000000, 1}); // 初始化 Facer 的信息

    for (int i = 0; i < n; ++i)
    {
        int id, power;
        cin >> id >> power;

        // 查找新会员实力值附近的老会员
        /*查找集合中第一个元素，其 first >= power。
         *如果有多个这样的元素，则会根据 second 进行比较，而此时的 0 比任何正整数都小，所以优先返回 second 最小的元素。*/
        auto it = members.lower_bound({power, 0});

        pair<int, int> candidate; // 用于存储最近的老会员
        if (it == members.end())
        {
            // 如果没有比当前实力大的老会员，选择最后一个老会员
            candidate = *prev(it);
        }
        else if (it == members.begin())
        {
            // 如果没有比当前实力小的老会员，选择第一个老会员
            candidate = *it;
        }
        else
        {
            // 存在前后两个候选老会员，选择更接近的
            auto next = *it;
            auto prev_it = prev(it);
            auto prev = *prev_it;

            // 比较前后两个老会员，选择更接近的，弱者优先
            if (abs(prev.first - power) <= abs(next.first - power))
            {
                candidate = prev;
            }
            else
            {
                candidate = next;
            }
        }

        // 输出比赛记录
        cout << id << " " << candidate.second << endl;

        // 将新会员加入集合
        members.insert({power, id});
    }

    return 0;
}
