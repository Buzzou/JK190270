//
// Created by Ruohao L. on 28/11/2024.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

// 计算质因数个数的函数
int countPrimeFactors(int n)
{
    int count = 0;
    for (int i = 2; i * i <= n; ++i)
    {
        //当一个因子 i 小于等于 sqrt(n) 时，我们已经检查了所有可能的因子组合。更大的 i 不需要检查，因为它们的对应因子已经在较小的范围中处理过了
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
    }
    //如果 n > 1，则 n 本身是一个未处理的质因子
    //如果 n = 37（一个质数），主循环根本不会执行（n 始终等于 37），因为没有任何数 i 满足 i * i <= n 且可以整除 n
    //如果 n = 77，n = 77 被 7 除，剩下 11。主循环结束后，n = 11，因为 11 > sqrt(77)，不会再被循环处理。最后 if (n > 1)，处理 11
    if (n > 1) count++; // 正确计数出 37 这个质因子 - 捕获大于 sqrt(n) 的质因子
    return count;
}

// 自定义比较器，用于最小优先队列
// 如果你定义 a < b 为 true，那么 a 会排在 b 的前面（a 被认为优先于 b）-> 质因数数目较少的元素会被放到前面（升序排序）
struct MinCompare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
    {
        if (a.first != b.first) return a.first < b.first; // 质因数数目少的优先
        return a.second < b.second; // 数值小的优先
    }
};

// 自定义比较器，用于最大优先队列
// 质因数数目较多的元素会被放到前面（按质因数数目降序排序）
struct MaxCompare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first != b.first) return a.first > b.first; // 质因数数目多的优先
        return a.second > b.second; // 数值大的优先
    }
};

int main()
{
    int num; // 添加元素次数
    cin >> num;

    // 定义两个优先队列
    priority_queue<pair<int, int>, vector<pair<int, int> >, MaxCompare> maxPQ; // 最大优先队列
    priority_queue<pair<int, int>, vector<pair<int, int> >, MinCompare> minPQ; // 最小优先队列

    for (int i = 0; i < num; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            int n;
            cin >> n;
            int primeCount = countPrimeFactors(n);

            // 将 (质因数个数, 数值) 加入队列
            maxPQ.push({primeCount, n});
            minPQ.push({primeCount, n});
        }

        // 输出优先级最高和最低的元素，并删除
        auto maxElem = maxPQ.top();
        auto minElem = minPQ.top();
        maxPQ.pop();
        minPQ.pop();

        cout << maxElem.second << " " << minElem.second << endl;
    }

    return 0;
}
