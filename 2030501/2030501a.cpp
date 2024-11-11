//
// Created by Ruohao L. on 08/11/2024.
//

#include "2030501a.h"
#include <iostream>
#include <string>
#include <algorithm>

void Word_Flip()
{
    char input[501];
    std::cin.getline(input, 501);
    std::string sentence(input);
    std::string result;
    int start = 0;

    while (start < sentence.size())
    {
        // 找到第一个不是空格的字符，作为单词的起始
        int end = start;
        while (end < sentence.size() && sentence[end] != ' ')
        {
            end++; //end会指向单词后的一个位置
        }
        // 翻转单词并添加到结果中
        std::string word = sentence.substr(start, end - start); //n是几个字符
        std::reverse(word.begin(), word.end());
        result += word;
        // 添加空格部分
        while (end < sentence.size() && sentence[end] == ' ')
        {
            result += sentence[end];
            end++; //end指向空格后的一个位置
        }
        // 更新起始位置
        start = end;
    }

    std::cout << result << std::endl;
}
