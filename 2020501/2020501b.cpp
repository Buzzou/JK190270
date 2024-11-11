//
// Created by Ruohao L. on 07/11/2024.
//

#include "2020501b.h"
#include <iostream>
using namespace std;

void Four_Lakes()
{
    // 枚举所有可能的排名组合，poyang、dongting、taihu、hongze的排名范围为1到4
    for (int poyang = 1; poyang <= 4; ++poyang)
    {
        for (int dongting = 1; dongting <= 4; ++dongting)
        {
            for (int taihu = 1; taihu <= 4; ++taihu)
            {
                for (int hongze = 1; hongze <= 4; ++hongze)
                {
                    // 排名必须不相等
                    if (poyang == dongting || poyang == taihu || poyang == hongze ||
                        dongting == taihu || dongting == hongze || taihu == hongze)
                    {
                        continue;
                    }

                    // 判断A、B、C、D的描述中，每人只有一句话正确
                    int a_correct = (dongting == 1) + (hongze == 4) + (poyang == 3);
                    int b_correct = (hongze == 1) + (dongting == 4) + (poyang == 2) + (taihu == 3);
                    int c_correct = (hongze == 4) + (dongting == 3);
                    int d_correct = (poyang == 1) + (taihu == 4) + (hongze == 2) + (dongting == 3);

                    if (a_correct == 1 && b_correct == 1 && c_correct == 1 && d_correct == 1)
                    {
                        // 找到符合条件的结果，输出排名
                        cout << poyang << endl;
                        cout << dongting << endl;
                        cout << taihu << endl;
                        cout << hongze << endl;
                        return 0;
                    }
                }
            }
        }
    }
}
