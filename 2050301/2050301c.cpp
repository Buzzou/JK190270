//
// Created by Ruohao L. on 10/11/2024.
//

#include "2050301c.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Text_layout()
{
    int n;
    cin >> n;
    vector<string> words(n);

    // 读取单词列表
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    int line_length = 0; // 当前行的字符计数
    bool first_word = true; // 判断是否是当前行的第一个单词

    for (const string& word: words)
    {
        if (first_word)
        {
            // 第一个单词，直接加入
            cout << word;
            line_length = word.length();
            first_word = false;
        }
        else
        {
            // 检查加入当前单词是否超过80字符
            if (line_length + 1 + word.length() <= 80)
            {
                cout << " " << word;
                line_length += 1 + word.length();
            }
            else
            {
                // 换行
                cout << endl << word;
                line_length = word.length();
            }
        }
    }

    cout << endl; // 输出末行的换行
}
