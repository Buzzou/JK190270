//
// Created by Ruohao L. on 11/11/2024.
//

#include "2090101a.h"
#include <iostream>
#include <string>

using namespace std;

void Number_containing_k_3s()
{
    int m, k;
    cin >> m >> k; // 读取输入的 m 和 k

    // 判断 m 是否能被 19 整除
    if (m % 19 != 0)
    {
        cout << "NO" << endl;
    }

    // 将 m 转换成字符串，方便统计 '3' 的数量
    string m_str = to_string(m);
    int count_of_3 = 0;

    // 统计 '3' 的数量
    for (char c: m_str)
    {
        if (c == '3')
        {
            count_of_3++;
        }
    }

    // 判断 '3' 的数量是否等于 k
    if (count_of_3 == k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
