//
// Created by Ruohao L. on 10/11/2024.
//

#include "2050301b.h"
#include <iostream>
#include <vector>
using namespace std;

void Traverse_2d_array()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int> > array(row, vector<int>(col));

    // 读取矩阵元素
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cin >> array[i][j];
        }
    }

    // 遍历上三角部分
    for (int start_col = 0; start_col < col; ++start_col)
    {
        int x = 0, y = start_col;
        while (x < row && y >= 0)
        {
            cout << array[x][y] << endl;
            ++x;
            --y;
        }
    }

    // 遍历下三角部分
    for (int start_row = 1; start_row < row; ++start_row)
    {
        int x = start_row, y = col - 1;
        while (x < row && y >= 0)
        {
            cout << array[x][y] << endl;
            ++x;
            --y;
        }
    }
}
