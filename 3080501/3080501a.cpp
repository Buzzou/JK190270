//
// Created by Ruohao L. on 27/11/2024.
//
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main()
{
    int a[] = {8, 7, 8, 9, 6, 2, 1};
    // 在此处补充你的代码
    set<int> v(a, a + sizeof(a) / sizeof(a[0])); // 自动去重并排序
    ostream_iterator<int> o(cout, " ");
    copy(v.begin(), v.end(), o); // 输出 set 中的元素
    return 0;
}
