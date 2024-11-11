//
// Created by Ruohao L. on 07/11/2024.
//

#include "2020501d.h"
#include <iostream>
#include <iomanip>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int year)
{
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
}

// 获取指定月份的天数
int getDaysInMonth(int year, int month)
{
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    return days_in_month[month - 1];
}

void Tomorrow_never_knows()
{
    int year, month, day;
    char dash; // 用于跳过短横线

    // 读取输入日期，格式为 yyyy-mm-dd
    cin >> year >> dash >> month >> dash >> day;

    // 计算下一天
    day += 1; // 递增日期
    if (day > getDaysInMonth(year, month))
    {
        day = 1;
        month += 1;
        if (month > 12)
        {
            month = 1;
            year += 1;
        }
    }

    // 输出下一天的日期，格式为 yyyy-mm-dd
    cout << setw(4) << setfill('0') << year << "-"
            << setw(2) << setfill('0') << month << "-"
            << setw(2) << setfill('0') << day << endl;
}
