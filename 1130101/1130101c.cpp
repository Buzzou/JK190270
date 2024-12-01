//
// Created by Ruohao L. on 07/11/2024.
//

#include "1130101c.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

// 定义一个结构体来表示二维点
struct Point
{
    double x, y;
};

// 计算两点之间的欧几里得距离
inline double distance(const Point& p1, const Point& p2)
/*在函数定义中使用 const Point& p1 和 const Point& p2 表示这两个参数是常量引用，这意味着我们可以读取 p1 和 p2 的内容，但无法修改它们的值。
 * 计算距离不应当改变任何点的位置
 */
{
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

void Farther_distance()
{
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    double maxDistance = 0.0;

    // 遍历每一对点，计算距离并更新最大距离
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            double dist = distance(points[i], points[j]);
            if (dist > maxDistance)
            {
                maxDistance = dist;
            }
        }
    }

    cout << fixed << setprecision(4) << maxDistance << endl;
}
