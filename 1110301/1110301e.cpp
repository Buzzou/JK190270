//
// Created by Ruohao L. on 03/11/2024.
//

#include "1110301e.h"
#include <iostream>
#include <vector>
using namespace std;

void Abnormal_cell_detection()
{
    int N;
    cin >> N;
    vector<vector<int> > matrix(N, vector<int>(N));

    // 输入矩阵数据
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int abnormalCount = 0;

    // 检查内部的细胞，排除边缘细胞
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            int cellValue = matrix[i][j];
            if (cellValue + 50 <= matrix[i - 1][j] &&
                cellValue + 50 <= matrix[i + 1][j] &&
                cellValue + 50 <= matrix[i][j - 1] &&
                cellValue + 50 <= matrix[i][j + 1])
            {
                abnormalCount++;
            }
        }
    }

    // 输出异常细胞的数目
    cout << abnormalCount << endl;
}
