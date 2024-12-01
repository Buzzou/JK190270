//
// Created by Ruohao L. on 03/11/2024.
//

#include "110301f.h"
#include <iostream>
#include <vector>
using namespace std;

// 翻转函数
inline void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void Cyclic_movement()
{
    int n, m;
    cin >> n >> m;

    // 调整 m，确保 m < n（如果 m > n，相当于右移 m % n 次）
    m = m % n;

    vector<int> arr(n);

    // 输入数组元素
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 翻转前 n-m 部分
    reverse(arr, 0, n - m - 1);
    // 翻转后 m 部分
    reverse(arr, n - m, n - 1);
    // 整体翻转
    reverse(arr, 0, n - 1);

    // 输出结果
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
}
