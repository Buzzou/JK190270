//
// Created by Ruohao L. on 30/11/2024.
//
#include <iostream>
using namespace std;
// 在此处补充你的代码
// 计算平方
int sqr(int n)
{
    return n * n;
}

// 计算数组中每个元素应用函数后的和
int sum(int* array, int n, int (*func)(int))
/*array 是一个整数数组
 * n 是数组的长度
 * func 是一个函数指针，用于对数组中的每个元素应用操作（如平方计算）
 * 函数指针的语法：返回值类型 (*指针名)(参数类型列表)
 */
{
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        result += func(array[i]);
    }
    return result;
}

int main()
{
    int t, n, a[0x100];
    cin >> t; //组数
    //每组数据：
    for (int c = 0; c < t; ++c)
    {
        cin >> n; //数组长度
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << sum(a, n, sqr) << endl;
    }
    return 0;
}
