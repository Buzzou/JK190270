//
// Created by Ruohao L. on 03/11/2024.
//

#include "110301g.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 快速选择算法，用来寻找第k小的元素
int quickSelect(vector<int> &nums, int left, int right, int k)
{
    if (left == right) return nums[left];

    int pivot = nums[right];
    int l = left;
    int r = right - 1;

    //[0, N-1]
    while (true)
    {
        while (l < right && nums[l] < pivot) //找到>=pivot的数字，l碰到r不停止，碰到最右边(right)才停止
        {
            ++l;
        }
        while (r > l && nums[r] >= pivot) //找到<pivot的数字，r碰到l停止
        {
            --r;
        }
        if (l < r)
        {
            swap(nums[l], nums[r]);
        }

        if (l == r)
        {
            swap(nums[l], nums[right]);
        };

        if (l == right || l == r)
        {
            break;
        }
    }

    int size_of_current_left_partition = l - left + 1;
    if (k == size_of_current_left_partition)
    {
        return nums[l];
    }
    if (k < size_of_current_left_partition)
    {
        return quickSelect(nums, left, l - 1, k);
    }
    return quickSelect(nums, l + 1, right, k - size_of_current_left_partition);
}

int main()
{
    int N;
    while (cin >> N && N != 0)
    {
        vector<int> nums(N);
        for (int i = 0; i < N; i++)
        {
            cin >> nums[i];
        }

        if (N % 2 == 1)
        {
            // 奇数个元素
            cout << quickSelect(nums, 0, N - 1, N / 2 + 1) << endl;
        }
        else
        {
            // 偶数个元素
            int mid1 = quickSelect(nums, 0, N - 1, N / 2);
            int mid2 = quickSelect(nums, 0, N - 1, N / 2 + 1);
            cout << (mid1 + mid2) / 2 << endl;
        }
    }
    return 0;
}
