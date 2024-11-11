//
// Created by Ruohao L. on 07/11/2024.
//

#include "2020501a.h"
#include <iostream>
#include <vector>
using namespace std;

int findIndexEqualValue(int n, const vector<int>& x)
/*n 是一个简单的整数，按值传递没有太大的性能开销*/
{
    for (int i = 0; i < n; ++i)
    {
        if (x[i] == i)
        {
            return i; // 找到满足条件的第一个元素，返回它的下标
        }
    }
    return -1; // 如果没有找到，返回 -1 表示 "N"
}

void Finding_subscripts()
{
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }

    int result = findIndexEqualValue(n, x);
    if (result != -1)
    {
        cout << x[result] << endl; // 输出满足条件的第一个元素的值
    }
    else
    {
        cout << "N" << endl; // 如果没有找到，输出 "N"
    }
}
