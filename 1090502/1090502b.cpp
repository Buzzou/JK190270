//
// Created by Ruohao L. on 03/11/2024.
//

#include "1090502b.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Cycling_and_walking()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int distance;
        cin >> distance;

        // 计算步行时间
        double walk_time = distance / 1.2;

        // 计算骑车时间（包括找车和停车的额外时间）
        double bike_time = distance / 3.0 + 50;

        // 比较时间并输出结果
        if (bike_time < walk_time)
        {
            cout << "Bike" << endl;
        }
        else if (walk_time < bike_time)
        {
            cout << "Walk" << endl;
        }
        else
        {
            cout << "All" << endl;
        }
    }
}
