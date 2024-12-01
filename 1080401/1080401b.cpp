//
// Created by Ruohao L. on 27/10/2024.
//

#include "1080401b.h"
#include<iostream>
using namespace std;

inline int calculate_gcd(int a, int b)
/*a≥b*/
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Sum_of_fractions()
{
    int n;
    cin >> n;
    int sumn = 0, sumd = 1; // sumn表示分子，sumd表示分母，用于累加结果的分数
    while (n--)
    {
        int num, deno;
        char slash; // 用于读取斜杠符号‘/’
        cin >> num >> slash >> deno;
        // 累加分数 a/b + c/d = (a*d + b*c) / (b*d)
        sumn = sumn * deno + num * sumd; // 更新累加后的分子
        sumd = sumd * deno; // 更新累加后的分母
    }
    // 约分
    // 使用欧几里得算法求最大公约数gcd
    // gcd(a,b)=gcd(b,a mod b)
    int gcd = calculate_gcd(sumn, sumd); // 最大公约数
    // 用gcd约分分子和分母
    sumd /= gcd;
    sumn /= gcd;
    // 输出结果，根据分母是否为1决定输出格式
    if (sumd > 1)
        cout << sumn << '/' << sumd << endl; // 输出带分母的最简分数
    else
        cout << sumn << endl; // 输出整数
}
