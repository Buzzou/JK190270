//
// Created by Ruohao L. on 27/10/2024.
//

#include "1080402a.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Age_and_disease()
{
    int n;
    cin >> n;
    int age;

    int count_1_18 = 0, count_19_35 = 0, count_36_60 = 0, count_60_plus = 0;

    // 读取年龄并分类
    for (int i = 0; i < n; ++i)
    {
        cin >> age;
        if (age <= 18)
        {
            ++count_1_18;
        }
        else if (age <= 35)
        {
            ++count_19_35;
        }
        else if (age <= 60)
        {
            ++count_36_60;
        }
        else
        {
            ++count_60_plus;
        }
    }

    // 计算并输出比例，保留两位小数
    cout << fixed << setprecision(2);
    cout << "1-18: " << (count_1_18 * 100.0 / n) << "%" << endl;
    cout << "19-35: " << (count_19_35 * 100.0 / n) << "%" << endl;
    cout << "36-60: " << (count_36_60 * 100.0 / n) << "%" << endl;
    cout << "60-: " << (count_60_plus * 100.0 / n) << "%" << endl;
}
