//
// Created by Ruohao L. on 11/11/2024.
//

#include "2060301a.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// 定义一个结构体用于存储病人信息
struct Patient
{
    string id; // 病人编号
    double severity; // 疾病严重程度
};

// 自定义排序函数，按严重程度降序排序
bool comparePatients(const Patient& a, const Patient& b)
{
    return a.severity > b.severity;
}

void Allocate_ward()
{
    int m;
    double a;
    cin >> m >> a; // 输入病人数量和重症病房的最低严重值

    vector<Patient> patients; // 用于存储符合条件的病人

    // 读取病人数据
    for (int i = 0; i < m; ++i)
    {
        Patient p;
        cin >> p.id >> p.severity;
        if (p.severity >= a)
        {
            patients.push_back(p); // 只存符合条件的病人
        }
    }

    // 按严重程度降序排序
    sort(patients.begin(), patients.end(), comparePatients);

    // 输出结果
    if (patients.empty())
    {
        cout << "None" << endl; // 没有符合条件的病人
    }
    else
    {
        for (const auto& p: patients) //auto==std::vector<int>::iterator
        {
            cout << p.id << " " << fixed << setprecision(1) << p.severity << endl;
        }
    }
}
