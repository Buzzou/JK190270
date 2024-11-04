//
// Created by Ruohao L. on 27/10/2024.
//

#include "1070202e.h"
#include <iostream>

void Separate_integer_digits()
{
    int num;
    std::cin >> num;

    // 提取各个数位
    int hundreds = num / 100; // 百位
    int tens = (num / 10) % 10; // 十位
    int units = num % 10; // 个位

    // 输出每个位数
    std::cout << hundreds << std::endl;
    std::cout << tens << std::endl;
    std::cout << units << std::endl;
}
