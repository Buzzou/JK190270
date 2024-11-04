//
// Created by Ruohao L. on 27/10/2024.
//

#include "1080402b.h"
#include <iostream>
using namespace std;

void Results()
{
    int n;
    cin >> n; // 输入分数

    // 判断分数并输出等级
    if (n >= 95 && n <= 100)
    {
        cout << 1 << endl;
    }
    else if (n >= 90)
    {
        cout << 2 << endl;
    }
    else if (n >= 85)
    {
        cout << 3 << endl;
    }
    else if (n >= 80)
    {
        cout << 4 << endl;
    }
    else if (n >= 70)
    {
        cout << 5 << endl;
    }
    else if (n >= 60)
    {
        cout << 6 << endl;
    }
    else
    {
        // n < 60
        cout << 7 << endl;
    }
}
