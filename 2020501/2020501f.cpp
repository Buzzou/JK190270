//
// Created by Ruohao L. on 07/11/2024.
//

#include "2020501f.h"
#include <iostream>
#include <vector>
using namespace std;

void Flu_infection()
{
    int n, m;
    cin >> n;

    vector<vector<char> > dormitory(n, vector<char>(n)); // 存储宿舍区初始状态 参照1110301e
    /*每一行是一个 vector<char>
     * 将每一行初始化为一个大小为 n 的 vector<char>，其中每个元素都为默认值 '\0'
     * 等价于创建了一个大小为 n x n 的二维字符数组
     */
    vector<vector<char> > temp(n, vector<char>(n)); // 临时数组，用于每日传播更新

    // 读取宿舍区布局
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> dormitory[i][j];
        }
    }

    cin >> m; // 目标天数

    // 从第2天开始的传播模拟
    for (int day = 1; day < m; ++day)
    {
        temp = dormitory; // 每天开始时，将当前状态复制到临时矩阵

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dormitory[i][j] == '@')
                {
                    // 如果当前房间有人感染
                    // 检查上下左右四个方向
                    if (i > 0 && dormitory[i - 1][j] == '.') temp[i - 1][j] = '@';
                    if (i < n - 1 && dormitory[i + 1][j] == '.') temp[i + 1][j] = '@';
                    if (j > 0 && dormitory[i][j - 1] == '.') temp[i][j - 1] = '@';
                    if (j < n - 1 && dormitory[i][j + 1] == '.') temp[i][j + 1] = '@';
                }
            }
        }

        dormitory = temp; // 将更新后的临时状态赋值回原状态
    }

    // 统计第 m 天的感染人数
    int infectedCount = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dormitory[i][j] == '@')
            {
                ++infectedCount;
            }
        }
    }

    cout << infectedCount << endl;
}
