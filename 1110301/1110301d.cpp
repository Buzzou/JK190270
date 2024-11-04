//
// Created by Ruohao L. on 03/11/2024.
//

#include "1110301d.h"
#include <iostream>
#include <iomanip> // 用于 setw 控制输出格式
using namespace std;

void Matrix_swap_rows()
{
    int matrix[5][5];
    int n, m;

    // 输入 5*5 矩阵数据
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // 输入 n 和 m 的值
    cin >> n >> m;

    // 检查 n 和 m 是否在有效范围
    if (n < 0 || n >= 5 || m < 0 || m >= 5)
    {
        cout << "error" << endl;
    }
    else
    {
        // 交换第 n 行和第 m 行
        for (int j = 0; j < 5; j++)
        {
            swap(matrix[n][j], matrix[m][j]);
        }

        // 输出交换后的矩阵
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << setw(4) << matrix[i][j];
            }
            cout << endl;
        }
    }
}
