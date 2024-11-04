//
// Created by Ruohao L. on 27/10/2024.
//

#include "1070202d.h"
#include <iostream>
#include <vector>
#include <cmath> // 用于 abs 函数

void abs_difference_largest_odd_smallest_even()
{
    std::vector<int> numbers(6);
    for (int i = 0; i < 6; ++i)
    {
        std::cin >> numbers[i];
    }

    // 初始化最大奇数为最小可能值，最小偶数为最大可能值
    int max_odd = -1;
    int min_even = 100;

    for (int num: numbers)
    {
        if (num % 2 == 1)
        {
            // 奇数
            if (num > max_odd)
            {
                max_odd = num;
            }
        }
        else
        {
            // 偶数
            if (num < min_even)
            {
                min_even = num;
            }
        }
    }

    // 计算并输出 |a - b|
    int result = std::abs(max_odd - min_even);
    std::cout << result << std::endl;
}
