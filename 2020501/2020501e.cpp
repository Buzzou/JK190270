//
// Created by Ruohao L. on 07/11/2024.
//

#include "2020501e.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// 定义一个结构体来存储培养皿信息
struct Dish
{
    int id; // 培养皿编号
    int initial; // 初始细菌数量
    int final; // 试验后细菌数量
    double rate; // 繁殖率

    // 构造函数
    Dish(int id, int initial, int final) : id(id), initial(initial), final(final)
    // 使用成员初始化列表不仅可以避免先默认初始化成员，再在构造函数主体中赋值的多余操作，使代码更高效，而且在初始化 const 或引用类型成员时也是必须的
    {
        /*等价于
         * id = id;
         * initial = initial;
         * final = final;
         */
        rate = static_cast<double>(final) / initial;
    }
};

// 比较函数，按繁殖率升序排列
inline bool compareDishes(const Dish& a, const Dish& b)
{
    return a.rate < b.rate;
}

void Bacteria_experiment_group()
{
    int n;
    cin >> n;

    vector<Dish> dishes;

    // 输入并计算每个培养皿的繁殖率
    for (int i = 0; i < n; ++i)
    {
        int id, initial, final;
        cin >> id >> initial >> final;
        dishes.emplace_back(id, initial, final); //emplace_back 通常更高效，因为可以避免创建临时对象
    }

    // 按繁殖率排序
    sort(dishes.begin(), dishes.end(), compareDishes); //end指向最后一个元素之后
    //比较函数可以是普通函数、函数对象（例如 std::greater<>()）、Lambda 表达式等，只要符合“接受两个参数、返回 bool”的要求即可
    /*等价于
    sort(dishes.begin(), dishes.end(), [](const Dish& a, const Dish& b) {
        return a.rate < b.rate; // 按 rate 从小到大排序
    });*/


    // 寻找繁殖率显著变化的分界点
    int splitIndex = 0;
    double maxDifference = 0.0;
    for (int i = 0; i < n - 1; ++i)
    {
        double difference = dishes[i + 1].rate - dishes[i].rate;
        if (difference > maxDifference)
        {
            maxDifference = difference;
            splitIndex = i; //[0,i], [i+1,n) 因为是0开始的，而输入是按1开始的，所以不包括n
        }
    }

    // 输出A亚种的结果
    cout << (n - 1) - (splitIndex + 1) + 1 << endl; //统一到以1开始
    for (int i = splitIndex + 1; i < n; ++i)
    {
        cout << dishes[i].id << endl;
    }

    // 输出B亚种的结果
    cout << splitIndex + 1 << endl; //统一到以1开始
    for (int i = 0; i <= splitIndex; ++i)
    {
        cout << dishes[i].id << endl;
    }
}
