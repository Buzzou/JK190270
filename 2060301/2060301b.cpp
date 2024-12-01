//
// Created by Ruohao L. on 11/11/2024.
//

#include "2060301b.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 根据给定碱基返回互补碱基
inline char getComplement(char base)
{
    switch (base)
    {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'G': return 'C';
        case 'C': return 'G';
        default: return ' ';
    }
}

void Paired_base_chain()
{
    int n;
    cin >> n; // 读取碱基链的数量
    vector<string> sequences(n);

    // 读取每条碱基链
    for (int i = 0; i < n; ++i)
    {
        cin >> sequences[i];
    }

    // 对每条碱基链生成并输出互补链
    for (const string& sequence: sequences)
    {
        string complement;
        for (char base: sequence)
        {
            complement += getComplement(base); // 获取互补碱基
        }
        cout << complement << endl;
    }
}
