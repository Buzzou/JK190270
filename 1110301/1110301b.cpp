//
// Created by Ruohao L. on 03/11/2024.
//

#include "1110301b.h"
#include <iostream>
#include <cstring>
#include <cctype> // 用于 tolower 函数
using namespace std;

// 将字符串转为小写
inline void toLowerCase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void Compare_strings()
{
    char s1[80], s2[80];

    // 读取输入的两个字符串
    cin.getline(s1, 80);
    cin.getline(s2, 80);

    // 将两个字符串都转换为小写
    toLowerCase(s1);
    toLowerCase(s2);

    // 比较两个字符串
    int result = strcmp(s1, s2);
    if (result < 0)
    {
        cout << "<" << endl;
    }
    else if (result > 0)
    {
        cout << ">" << endl;
    }
    else
    {
        cout << "=" << endl;
    }
}
