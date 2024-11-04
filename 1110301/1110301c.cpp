//
// Created by Ruohao L. on 03/11/2024.
//

#include "1110301c.h"
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

void Longest_word_2()
{
    char sentence[500];
    cin.getline(sentence, 500); // 读取整个句子

    // 去掉句号
    int length = strlen(sentence);
    if (sentence[length - 1] == '.')
    {
        sentence[length - 1] = '\0';
    }

    // 分割单词并找出最长的单词
    string longestWord = "";
    stringstream ss(sentence);
    string word;

    while (ss >> word)
    {
        if (word.length() > longestWord.length())
        {
            longestWord = word;
        }
    }

    // 输出最长的单词
    cout << longestWord << endl;
}
