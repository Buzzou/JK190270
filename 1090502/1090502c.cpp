//
// Created by Ruohao L. on 03/11/2024.
//

#include "1090503c.h"
#include <iostream>
using namespace std;

void Buy_house()
{
    int N, K;

    // 持续读取输入，直到遇到输入结束
    while (cin >> N >> K)
    {
        double house_price = 200.0; // 初始房价
        double savings = 0.0; // 初始存款
        bool can_buy = false; // 是否可以买房的标记

        // 模拟每一年
        for (int year = 1; year <= 20; ++year)
        {
            savings += N; // 每年收入存入savings

            // 判断是否可以买房
            if (savings >= house_price)
            {
                cout << year << endl;
                can_buy = true;
                break;
            }

            // 房价增长
            house_price *= (1 + K / 100.0);
        }

        // 如果20年后仍不能买房，输出Impossible
        if (!can_buy)
        {
            cout << "Impossible" << endl;
        }
    }
}
