//
// Created by Ruohao L. on 07/11/2024.
//

#include "110301h.h"
#include <iostream>
#include <vector>
using namespace std;

void Tree_outside_school()
{
    int L, M;
    cin >> L >> M;

    // 初始化一个长度为 L+1 的数组，全部设为 true 表示每个位置都有树
    vector<bool> trees(L + 1, true);

    // 读取 M 个区间，移除对应位置的树
    for (int i = 0; i < M; ++i)
    {
        int start, end;
        cin >> start >> end;
        for (int j = start; j <= end; ++j)
        {
            trees[j] = false; // 将这个区间的树设为移除状态
        }
    }

    // 统计剩余的树
    int remainingTrees = 0;
    for (int i = 0; i <= L; ++i)
    {
        if (trees[i])
        {
            ++remainingTrees;
        }
    }

    // 输出剩余的树的数量
    cout << remainingTrees << endl;
}
