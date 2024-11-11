//
// Created by Ruohao L. on 07/11/2024.
//

#include "2020501c.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Invoice_Statistics()
{
    // 初始化每个人和每类发票的总金额
    float person_total[3] = {0.0, 0.0, 0.0}; // 分别对应 ID 为 1、2、3 的人
    float category_total[3] = {0.0, 0.0, 0.0}; // 分别对应 A、B、C 类发票

    // 读取三行输入
    for (int i = 0; i < 3; ++i)
    {
        int id, num_invoices;
        cin >> id >> num_invoices;

        // 根据 id 确定对应的索引
        int person_index = id - 1;

        // 读取每张发票的类别和金额
        for (int j = 0; j < num_invoices; ++j)
        {
            char category;
            float amount;
            cin >> category >> amount;

            // 更新个人总金额
            person_total[person_index] += amount;

            // 更新发票类别的总金额
            int category_index;
            if (category == 'A')
            {
                category_index = 0;
            }
            else if (category == 'B')
            {
                category_index = 1;
            }
            else
            {
                // category == 'C'
                category_index = 2;
            }
            category_total[category_index] += amount;
        }
    }

    // 输出每个人的总金额，保留两位小数
    for (int i = 0; i < 3; ++i)
    {
        cout << i + 1 << " " << fixed << setprecision(2) << person_total[i] << endl;
    }

    // 输出每种发票类别的总金额，保留两位小数
    cout << "A " << fixed << setprecision(2) << category_total[0] << endl;
    cout << "B " << fixed << setprecision(2) << category_total[1] << endl;
    cout << "C " << fixed << setprecision(2) << category_total[2] << endl;
}
