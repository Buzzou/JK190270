//
// Created by Ruohao L. on 26/10/2024.
//

#include "1070201.h"
#include <iostream>
using namespace std;

void Bacteria_experiment_group()
{
    int n; // n为培养皿的数量
    int id[100]; // id记录细菌的编号
    double rate[100]; // rate记录细菌的繁殖率，第i个细菌对应id[i]和rate[i]

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int initial, final;
        cin >> id[i] >> initial >> final;
        rate[i] = (double) final / initial; // 计算并存储繁殖率
    }

    // 对细菌按繁殖率进行降序排序
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (rate[j + 1] > rate[j])
            {
                // 交换id和rate，使二者保持同步
                // int tmpId = id[j];
                // id[j] = id[j + 1];
                // id[j + 1] = tmpId;
                swap(id[j], id[j + 1]);

                // double tmpRate = rate[j];
                // rate[j] = rate[j + 1];
                // rate[j + 1] = tmpRate;
                swap(rate[j], rate[j + 1]);
            }
        }
    }

    // 找到最大差异以分隔亚种
    double maxDiff = 0;
    int maxDiffIndex = 0;
    for (int i = 0; i < n - 1; i++)
    {
        double diff = rate[i] - rate[i + 1];
        if (maxDiff < diff)
        {
            maxDiff = diff;
            maxDiffIndex = i;
        }
    }

    // 输出亚种A的培养皿数量和编号
    cout << maxDiffIndex + 1 << endl;
    for (int i = maxDiffIndex; i >= 0; i--)
    {
        cout << id[i] << endl;
    }

    // 输出亚种B的培养皿数量和编号
    cout << n - (maxDiffIndex + 1) << endl;
    for (int i = n - 1; i > maxDiffIndex; i--)
    {
        cout << id[i] << endl;
    }
}
