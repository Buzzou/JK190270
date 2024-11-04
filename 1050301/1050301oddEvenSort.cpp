//
// Created by Ruohao L. on 23/10/2024.
//

#include "1050301oddEvenSort.h"
#include <iostream>
using namespace std;

void oddEvenSort()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    // 首先，我们把奇数放到数组左边，偶数放到数组右边
    int l = 0, r = 9; //用左手和右手分别指向数组两端
    int count = 0;
    while (l <= r)
    {
        count++;
        bool leftIsOdd = a[l] % 2 == 1;
        bool rightIsEven = a[r] % 2 == 0;
        if (leftIsOdd)
        {
            l++;
        }
        if (rightIsEven)
        {
            r--;
        }
        if (leftIsOdd || rightIsEven)
        {
            cout << "!swap" << ' ' << "count:" << count << ' ' << "l:" << l << ' ' << "r:" << r << endl;
            continue;
        }
        cout << "count:" << count << ' ' << "l:" << l << ' ' << "r:" << r << endl;
        swap(a[l], a[r]);
    }
    // 对l左边（不含l）（奇数部分）冒泡，不断比较相邻的两个数，如果顺序错了，那么就交换
    int start = 0, end = r;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < 5 - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
    // 对l右边（含l）（偶数部分）冒泡，不断比较相邻的两个数，如果顺序错了，那么就交换
    start = l, end = 10;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 6 - 5; j < 6 - i; j++)
        {
            if (a[j - 1 + 5] > a[j + 5])
            {
                swap(a[j + 5], a[j - 1 + 5]);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';
    }
}

void anotherOddEvenSort()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    // 冒泡，不断比较相邻的两个数，如果顺序错了，那么就交换
    for (int i = 0; i < 9; i++)
    {
        for (int j = 1; j < 10 - i; j++)
        {
            // 与刚才的冒泡排序不同，我们不只是通过较数字的大小决定顺序
            // 如果左边的为偶数，右边的为奇数，那么顺序也需要颠倒
            bool leftIsEven = a[j - 1] % 2 == 0;
            bool rightIsEven = a[j] % 2 == 0;
            if ((leftIsEven && !rightIsEven) ||
                (leftIsEven == rightIsEven && a[j - 1] > a[j]))
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';
    }
}
