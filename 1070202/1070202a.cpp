//
// Created by Ruohao L. on 27/10/2024.
//

#include "1070202a.h"
#include <iostream>
#include <algorithm> // 为了使用 std::max 函数

int ceilDivide(int y, int x)
/*
 * 正整数 y 和 x，小数不适用
 */
{
    return (y + x - 1) / x;
}

int remainingApples(int n, int x, int y)
{
    int applesEaten = ceilDivide(y, x); // 计算虫子吃掉的完整苹果数量
    int remaining = std::max(0, n - applesEaten); // 计算剩余苹果，确保非负
    return remaining;
}
