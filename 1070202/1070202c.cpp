//
// Created by Ruohao L. on 27/10/2024.
//

#include "1070202c.h"
#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::max_element

void Highest_score()
{
    int n;
    std::cin >> n;

    std::vector<int> scores(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> scores[i];
    }

    // 使用 max_element 找出最高分
    int max_score = *std::max_element(scores . begin(), scores . end());
    std::cout << max_score;
}
