//
// Created by Ruohao L. on 12/11/2024.
//

#include "2090101d.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义一个结构体表示点
struct Point
{
    int x, y;
};

// 判断 p1 是否支配 p2
bool dominates(const Point& p1, const Point& p2)
//点 (x1, y1) 支配 (x2, y2) 的条件是 x1 >= x2 且 y1 >= y2
{
    return p1.x >= p2.x && p1.y >= p2.y;
}

int Finding_maximum_point_on_plane()
{
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> maxPoints;

    // 找出所有极大点
    for (int i = 0; i < n; ++i)
    {
        bool isMaxPoint = true;
        for (int j = 0; j < n; ++j)
        {
            if (i != j && dominates(points[j], points[i])) //i != j 的限制是为了避免一个点与自身进行比较
            {
                isMaxPoint = false;
                break;
            }
        }
        if (isMaxPoint)
        {
            maxPoints.push_back(points[i]);
        }
    }

    // 按 x 坐标排序极大点
    sort(maxPoints.begin(), maxPoints.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    // 格式化输出
    for (size_t i = 0; i < maxPoints.size(); ++i)
    {
        if (i > 0) cout << ","; //同2050301c的处理方法
        cout << "(" << maxPoints[i].x << "," << maxPoints[i].y << ")";
    }
    cout << endl;
}
