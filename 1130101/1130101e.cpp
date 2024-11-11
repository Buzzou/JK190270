//
// Created by Ruohao L. on 07/11/2024.
//

#include "1130101e.h"
#include <iostream>
#include <cstring>
using namespace std;

void String_insertion()
{
    string str, substr;

    // 不断读取输入，处理多组数据
    while (cin >> str >> substr)
    {
        int maxIndex = 0;

        // 找到 ASCII 码最大的字符的位置
        for (int i = 1; i < str.length(); ++i)
        {
            if (str[i] > str[maxIndex])
            {
                maxIndex = i;
            }
        }

        // 构建插入后的新字符串
        string result = str.substr(0, maxIndex + 1) + substr + str.substr(maxIndex + 1);

        // 输出结果
        cout << result << endl;
    }
}
