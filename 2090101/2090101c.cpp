//
// Created by Ruohao L. on 11/11/2024.
//

#include "2090101c.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Operator_determination()
{
    // string input;
    // getline(cin, input); // 读取输入，格式为 "a,b,c"

    // 解析输入
    int a, b, c;
    char comma; // 用于跳过逗号
    // stringstream ss(input);
    cin >> a >> comma >> b >> comma >> c;

    // 检查每种运算符
    if (a + b == c)
    {
        cout << "+" << endl;
    }
    else if (a - b == c)
    {
        cout << "-" << endl;
    }
    else if (a * b == c)
    {
        cout << "*" << endl;
    }
    else if (b != 0 && a / b == c)
    {
        // 检查除法
        cout << "/" << endl;
    }
    else if (b != 0 && a % b == c)
    {
        // 检查取余
        cout << "%" << endl;
    }
    else
    {
        cout << "error" << endl; // 无符合条件的运算符
    }
}
