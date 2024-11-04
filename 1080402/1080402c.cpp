//
// Created by Ruohao L. on 01/11/2024.
//
//TODO:学习递归之后再回头看
#include "1080402c.h"
#include <iostream>
#include <queue>
using namespace std;

void K_large()
{
    int N, K;
    cin >> N >> K;
    priority_queue<int, vector<int>, greater<int> > minHeap; // 最小堆

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;

        // 如果堆的大小小于 K，直接加入
        if (minHeap.size() < K)
        {
            minHeap.push(num);
        }
        else if (num > minHeap.top())
        {
            // 如果当前数字大于堆顶元素
            minHeap.pop(); // 弹出最小的
            minHeap.push(num); // 加入当前数字
        }
    }

    // 堆顶即为第 K 大的数
    cout << minHeap.top() << endl;
}
