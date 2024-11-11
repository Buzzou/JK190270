//
// Created by Ruohao L. on 08/11/2024.
//

#include "2030501c.h"
#include <iostream>
#include <stack>
#include <string>

void Queue_Game()
{
    std::string queue;
    std::cin >> queue;

    // 确定男孩和女孩的字符
    char boy = queue[0]; // 第一个出现的字符
    char girl = '\0'; // 女孩字符
    for (char c: queue) //范围-based for 循环
    {
        if (c != boy)
        {
            girl = c;
            break;
        }
    }

    std::stack<int> boys;
    for (int i = 0; i < queue.size(); ++i)
    {
        if (queue[i] == boy)
        {
            // 将小男孩「编号」入栈
            boys.push(i);
        }
        else if (queue[i] == girl)
        {
            // 配对：小男孩出栈与小女孩配对
            int boy_index = boys.top();
            boys.pop();
            // 输出配对编号
            std::cout << boy_index << " " << i << std::endl;
        }
    }
}
