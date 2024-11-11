//
// Created by Ruohao L. on 10/11/2024.
//

#include "2050301a.h"
#include <iostream>
#include <vector>
using namespace std;

void sum_of_edge_elements_of_matrix()
{
    int k;
    cin >> k;
    while (k--)
    {
        int m, n; //行，列
        cin >> m >> n;

        vector<vector<int> > matrix(m, vector<int>(n));

        // 读取矩阵元素
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> matrix[i][j];
            }
        }

        int sum = 0;

        // 计算第一行和最后一行
        for (int j = 0; j < n; ++j)
        {
            sum += matrix[0][j];
            if (m > 1) sum += matrix[m - 1][j];
        }

        // 计算第一列和最后一列（排除第一行和最后一行已经统计过的元素）
        for (int i = 1; i < m - 1; ++i)
        {
            sum += matrix[i][0];
            if (n > 1) sum += matrix[i][n - 1];
        }

        // 输出结果
        cout << sum << endl;
    }
}
