//
// Created by Ruohao L. on 25/11/2024.
//
#include <iostream>
#include <iomanip> // 用于流操纵算子
using namespace std;

int main()
{
    double number;
    cin >> number;

    // 非科学计数法，保留 5 位小数
    cout << fixed << setprecision(5) << number << endl;

    // 科学计数法，保留 7 位小数
    cout << scientific << setprecision(7) << number << endl;

    return 0;
}

/*扩展问题
 *如果需要设置输出宽度，可以结合 std::setw()。
 *如果需要定制输出格式（如补充空格或零），可以使用 std::setfill() 和 std::setw() 配合。*/
