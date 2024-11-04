//
// Created by Ruohao L. on 03/11/2024.
//

#include "1110301a.h"
#include <iostream>
#include <cstring> // 用于使用 strlen 函数
using namespace std;

void number_of_letters()
{
    char s[80]; // 定义字符数组 s，长度为 80
    cin.getline(s, 80); // 读取输入字符串，包括空格

    // 初始化计数器
    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;

    // 遍历字符串
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        // 判断元音字母并统计
        switch (s[i])
        {
            case 'a': countA++;
                break;
            case 'e': countE++;
                break;
            case 'i': countI++;
                break;
            case 'o': countO++;
                break;
            case 'u': countU++;
                break;
        }
    }

    // 输出结果
    cout << countA << " " << countE << " " << countI << " " << countO << " " << countU << endl;
}
