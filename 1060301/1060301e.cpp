//
// Created by Ruohao L. on 26/10/2024.
//

#include "1060301e.h"
#include <iostream>
using namespace std;

int a[100];

void Reverse_array()
{
    int n;
    cin >> n;

    // 顺序读取数组中的元素
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 倒序输出数组中的元素
    while (n--)
    {
        //常用的倒序计数循环，等价于while(n-->0)
        cout << a[n];
        if (n > 0) cout << " "; // 不是最后一个数时加空格
    }
    cout << endl;
}
