//
// Created by Ruohao L. on 01/11/2024.
//

#include "1090502a.h"
#include <iostream>
using namespace std;

int main()
{
    int a, num, sum = 0;

    // 读取第一个整数 a
    cin >> a;

    // 依次读取接下来的5个整数并判断是否小于 a
    for (int i = 0; i < 5; ++i)
    {
        cin >> num;
        if (num < a)
        {
            sum += num;
        }
    }

    // 输出小于 a 的数的和
    cout << sum << endl;

    return 0;
}
