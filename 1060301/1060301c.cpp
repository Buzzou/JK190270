//
// Created by Ruohao L. on 26/10/2024.
//

#include "1060301c.h"
#include <iostream>
using namespace std;

void Numbe_of_integers()
{
    int k;
    cin >> k;
    int n1 = 0, n5 = 0, n10 = 0;

    // 遍历输入的 k 个数
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;

        // 判断数字是否是1, 5, 或10
        if (n == 1) n1++;
        else if (n == 5) n5++;
        else if (n == 10) n10++;
    }

    // 输出结果
    cout << n1 << endl;
    cout << n5 << endl;
    cout << n10 << endl;
}
