//
// Created by Ruohao L. on 11/11/2024.
//
//TODO:短路求值（short-circuit evaluation）
#include "2060301c.h"
#include <iostream>
#include <vector>

using namespace std;

void Finding_Peak()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int> > terrain(m, vector<int>(n));

    // 读取地块高度数据
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> terrain[i][j];
        }
    }

    // 定义四个方向的位移：上、下、左、右
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // 遍历每个地块，检查是否为山顶
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            bool isPeak = true;

            // 检查四个方向
            for (int k = 0; k < 4; ++k)
            {
                int ni = i + directions[k][0];
                int nj = j + directions[k][1];

                // 确保邻居位置合法，并检查是否不符合山顶条件
                if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                {
                    if (terrain[i][j] < terrain[ni][nj])
                    {
                        isPeak = false;
                        break;
                    }
                }
            }

            // 如果是山顶，输出位置
            if (isPeak)
            {
                cout << i << " " << j << endl;
            }
        }
    }
}
