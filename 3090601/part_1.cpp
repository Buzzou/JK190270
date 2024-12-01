#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
    int x;
    int y;
    Point(int x_,int y_):x(x_),y(y_) { }
};
//C++ 的重载机制是基于函数的参数类型来决定调用哪个重载的 - 这个函数只对 Point 类型的比较生效
//如果将 operator< 定义为成员函数，则只能通过类的实例调用，且其左操作数必须是类的对象
//定义为全局函数则标准库算法（如 std::sort 或 std::binary_search）可以直接使用这个重载函数
bool operator < ( const Point & p1, const Point & p2)
{
    if( p1.y < p2.y )
        return true;
    else if( p1.y == p2.y )
        return p1.x < p2.x;
    else
        return false;
}
int main()
{
    int t;
    int x,y;
    cin >> t;
    vector<Point> v;
    while( t -- ) {
        cin >> x >> y;
        v.push_back(Point(x,y));
    }
    vector<Point>::iterator i,j;
    int nTotalNum = 0;
// 在此处补充你的代码
    sort(v.begin(), v.end()); // 对点集排序，便于二分查找
    //
    for (i = v.begin(); i < v.end() - 1; i++) // 枚举第一个点
        for (j = i + 1; j < v.end(); j++) { // 枚举第二个点 - j 在 i 的后面，避免重复
            // 如果两个点构成矩形的对角点
            if (i->x != j->x && i->y != j->y) {
                // 检查是否存在另外两个点
                if (binary_search(v.begin(), v.end(), Point(j->x, i->y)) &&
                    binary_search(v.begin(), v.end(), Point(i->x, j->y))) {
                    nTotalNum++; // 符合条件，计数增加
                    }
            }
        }
    cout << nTotalNum / 2 << endl; // 每个矩形被计算了两次，因此除以 2

    return 0;
}
