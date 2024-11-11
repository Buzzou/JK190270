//
// Created by Ruohao L. on 08/11/2024.
//

#include "2030501d.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>

void Extension_matching()
{
    std::string line;

    // 逐行读取输入
    while (std::getline(std::cin, line)) //不定长
    {
        std::cout << line << std::endl; // 输出原始字符串

        std::vector<char> markers(line.size(), ' '); // 标记数组，初始化为空格
        std::stack<int> left_brackets; // 存储左括号的位置索引

        // 遍历字符串，进行括号匹配
        for (int i = 0; i < line.size(); ++i)
        {
            if (line[i] == '(')
            {
                left_brackets.push(i); // 遇到左括号，记录「索引」
            }
            else if (line[i] == ')')
            {
                if (!left_brackets.empty())
                {
                    left_brackets.pop(); // 匹配成功，出栈一个左括号
                }
                else
                {
                    markers[i] = '?'; // 没有匹配的左括号，标记为孤立的右括号
                }
            }
        }

        // 处理未匹配的左括号
        while (!left_brackets.empty())
        {
            markers[left_brackets.top()] = '$';
            left_brackets.pop();
        }

        // 输出标记结果
        for (char mark: markers)
        {
            std::cout << mark;
        }
        std::cout << std::endl;
    }
}
