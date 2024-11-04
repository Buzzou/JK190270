//
// Created by Ruohao L. on 03/11/2024.
//
//TODO:学习哈希表之后再回头看
#include "1090503d.h"
#include <iostream>
#include <unordered_set>
using namespace std;

void sum_K()
{
    int n, k;
    cin >> n >> k;

    unordered_set<int> seen;//使用哈希表实现，平均查找时间复杂度为 O(1)
    bool found = false;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;

        int target = k - num;
        // 检查是否存在匹配的数使得两数之和为k
        if (seen.count(target))
        {
            found = true;
            break;
        }

        // 将当前数加入集合
        seen.insert(num);
    }

    if (found)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}
