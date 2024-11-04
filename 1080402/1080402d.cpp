//
// Created by Ruohao L. on 01/11/2024.
//

#include "1080402d.h"
#include <iostream>
using namespace std;

void RMB_payment()
{
    int amount;
    cin >> amount; // 输入金额

    // 定义各个面额
    int hundreds = amount / 100;
    amount %= 100; // 更新剩余金额

    int fifties = amount / 50;
    amount %= 50;

    int twenties = amount / 20;
    amount %= 20;

    int tens = amount / 10;
    amount %= 10;

    int fives = amount / 5;
    amount %= 5;

    int ones = amount; // 剩余金额全为1元

    // 输出各面额的张数
    cout << hundreds << endl;
    cout << fifties << endl;
    cout << twenties << endl;
    cout << tens << endl;
    cout << fives << endl;
    cout << ones << endl;
}
