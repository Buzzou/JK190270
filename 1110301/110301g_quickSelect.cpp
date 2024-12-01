#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//// 快速选择算法，用来寻找第k小的元素
//int quickSelect(vector<int>& nums, int left, int right, int k) {
//    if (left == right) return nums[left];
//
//    int pivot = nums[right];
//    int i = left;
//
//    for (int j = left; j < right; j++) {
//        if (nums[j] <= pivot) {
//            swap(nums[i], nums[j]);
//            i++;
//        }
//    }
//    swap(nums[i], nums[right]);
//
//    int count = i - left + 1;
//    if (count == k) return nums[i];
//    else if (count > k) return quickSelect(nums, left, i - 1, k);
//    else return quickSelect(nums, i + 1, right, k - count);
//}
inline int quickSelect(vector<int> &nums, int left, int right, int k)
{
    if (left == right) return nums[left];

    int pivot = nums[right]; //rightmost->pivot
    int l = left; //leftmost marker
    int r = right - 1; //rightmost\pivot marker
    while (r > l) //右碰到左 停止
    {
        while (nums[l] < pivot) //l找大等pivot的
        {
            ++l;
        }
        if (l == right) //pivot指向的数是这列数中最大的
        {
            break;
        }
        while (r > l && nums[r] >= pivot) //r找比pivot小的
        {
            r--;
        }
        swap(nums[l], nums[r]); //小的都在左边，大等的跑去右半边
    }
    //互换停止
    if (l == r) swap(nums[l], nums[right]);

    int k_offset = k - 1;
    if (l == k_offset) return nums[l];
    if (k_offset < l) return quickSelect(nums, left, l - 1, k);
    return quickSelect(nums, l + 1, right, k - (l + 1));
}

int main() {
//    int N;
//    while (cin >> N && N != 0) {
//        vector<int> nums(N);
//        for (int i = 0; i < N; i++) {
//            cin >> nums[i];
//        }
//
//        if (N % 2 == 1) { // 奇数个元素
//            cout << quickSelect(nums, 0, N - 1, N / 2 + 1) << endl;
//        } else { // 偶数个元素
//            int mid1 = quickSelect(nums, 0, N - 1, N / 2);
//            int mid2 = quickSelect(nums, 0, N - 1, N / 2 + 1);
//            cout << (mid1 + mid2) / 2 << endl;
//        }
//    }
//    return 0;
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
    return 0; // 表示程序正常结束
}
