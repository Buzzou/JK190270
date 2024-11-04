//
// Created by Ruohao L. on 26/10/2024.
//

#include "1060301d.h"
#include <iostream>
using namespace std;

void Number_of_1()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, ans = 0;
        cin >> x;

        // 计算二进制中1的个数
        while (x > 0)
        {
            ans += x % 2; // 如果最低位是1，则加1
            x /= 2; // 将x右移1位（等价于除以2）
            // x = x >> 1; //右移和除法的效果仅在非负整数下完全一致。对于负数，右移和除法在处理符号位时可能不同。
        }

        cout << ans << endl;
    }
}
