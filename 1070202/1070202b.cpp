//
// Created by Ruohao L. on 27/10/2024.
//

#include "1070202b.h"
#include <iostream>
#include <cmath> // 包含常数 M_PI

int buckets_needed(int h, int r)
{
    // 定义 pi 值
    const double pi = 3.14159;
    // 计算每个桶的体积（立方厘米）
    double V_bucket = pi * r * r * h;
    // 需要喝的总水量（立方厘米）
    int total_volume = 20000;

    // 向上取整计算至少需要的桶数
    int buckets_needed = std::ceil(total_volume / V_bucket);

    return buckets_needed;
}
