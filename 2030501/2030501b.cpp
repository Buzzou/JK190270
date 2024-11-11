//
// Created by Ruohao L. on 08/11/2024.
//

#include "2030501b.h"
#include <iostream>

int Kakutani_conjecture()
{
    int n;
    std::cin >> n;

    if (n == 1)
    {
        std::cout << "End" << std::endl;
        return 0;
    }

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            // 偶数处理：n / 2
            std::cout << n << "/2=" << n / 2 << std::endl;
            n /= 2;
        }
        else
        {
            // 奇数处理：n * 3 + 1
            std::cout << n << "*3+1=" << n * 3 + 1 << std::endl;
            n = n * 3 + 1;
        }
    }

    std::cout << "End" << std::endl;
}
