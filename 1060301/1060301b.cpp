//
// Created by Ruohao L. on 26/10/2024.
//

#include "1060301b.h"
#include <iostream>
using namespace std;

void Odd_sum()
{
    int m, n, result = 0;
    cin >> m >> n;
    while (m <= n)
    {
        // 如果 m 是奇数，将 m 加到结果中
        if (m % 2 == 1)
            result += m;
        m++;
    }
    // 输出结果
    cout << result << endl;
}
