//
// Created by Ruohao L. on 11/11/2024.
//

#include "2090101b.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void second_most_common_letter_in_string()
{
    string input;
    getline(cin, input); // 获取输入的字符串

    map<char, int> freq; // 用于统计字母频率，忽略大小写。该map 容器的键为 char 类型（字符），值为 int 类型（整数）

    // 统计字母频率
    for (char c: input)
    {
        if (isalpha(c))
        {
            // 只处理英文字母
            char lowercase_char = tolower(c); // 将字符转换为小写
            freq[lowercase_char]++; // 统计该字母的频率
        }
    }

    // 将频率存入向量，并按频率排序
    vector<pair<char, int> > freq_vector(freq.begin(), freq.end());
    sort(freq_vector.begin(), freq_vector.end(), [](pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second; // 按出现次数降序排序。.second 用来访问 pair 类型中的第二个元素的成员变量
    });

    // 找到第 2 多的出现次数
    int highest_freq = freq_vector[0].second; // 最多出现次数
    int second_highest_freq = -1;
    for (const auto& entry: freq_vector)
    {
        if (entry.second < highest_freq)
        {
            second_highest_freq = entry.second;
            break;
        }
    }

    // 找到第 2 多出现次数的字母，按原始顺序输出
    for (char c: input)
    {
        if (isalpha(c))
        {
            char lowercase_char = tolower(c);
            if (freq[lowercase_char] == second_highest_freq)
            {
                cout << (char) toupper(lowercase_char) << "+" << lowercase_char << ":" << second_highest_freq << endl;
                break;
            }
        }
    }
}
