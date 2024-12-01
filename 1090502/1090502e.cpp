//
// Created by Ruohao L. on 03/11/2024.
//

#include "1090502e.h"
#include <iostream>
using namespace std;

// 计算一个整数各个位数的和
inline int digit_sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    // 从10到n，找出所有自整除数
    for (int x = 10; x <= n; ++x) {
        int m = digit_sum(x); // 计算当前数x的各位数字之和
        if (x % m == 0) {
            cout << x << endl; // 如果x是自整除数，输出x
        }
    }

    return 0;
}
