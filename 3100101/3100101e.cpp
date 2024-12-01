//
// Created by Ruohao L. on 30/11/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个函数对象，累加每个元素的二进制低3位
class CMy_add
{
private:
    int& sum; // 使用引用绑定外部的变量，用于累加，确保结果直接更新到外部变量中
public:
    // 构造函数，绑定 sum
    CMy_add(int& s) : sum(s) {}

    // 函数调用操作符，处理每个元素
    void operator()(int x)
    {
        sum += (x & 7); // 累加二进制低3位
    }
};

int main()
{
    int v, my_sum = 0;
    vector<int> vec;

    // 输入数据
    cin >> v;
    while (v)
    //输入以 0 结束
    {
        vec.push_back(v);
        cin >> v;
    }

    // 使用 for_each 和 CMy_add 函数对象处理数组
    for_each(vec.begin(), vec.end(), CMy_add(my_sum));

    //或不用 for_each 和 CMy_add 函数对象：（只是会显得冗长）
    // for (int i = 0; i < vec.size(); ++i) {
    //     my_sum += (vec[i] & 7); // 累加低3位
    // }

    // 输出结果
    cout << my_sum << endl;

    return 0;
}
