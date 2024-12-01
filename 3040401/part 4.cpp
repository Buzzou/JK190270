//
// Created by Ruohao L. on 19/11/2024.
//
/*由于 C++ 的基本数据类型（如 int、long long）无法直接存储长度超过其范围的整数（100 位正整数远超它们的范围）
 *我们需要自己设计数据结构和算法来处理这些大整数。*/
#include "part 4.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 去掉前导零 - 000123 → 123
string trimLeadingZeros(const string& num)
{
    //无符号类型：size_t 只能表示非负值，通常用于内存大小和数组索引，确保没有负值干扰
    /*与平台无关：size_t 的大小取决于编译器和操作系统的位宽：
        在 32 位系统上，通常是 4 字节（32 位）。
        在 64 位系统上，通常是 8 字节（64 位）*/
    size_t pos = num.find_first_not_of('0');
    if (pos == string::npos) return "0"; // 全是0
    return num.substr(pos);
}

// 大整数加法 - 从低位到高位逐位相加，处理进位
string add(const string& a, const string& b)
{
    string result; // 存储最终的结果
    int carry = 0, sum = 0; // carry 表示进位
    size_t i = a.size() - 1, j = b.size() - 1; // 从两个字符串的最后一位开始加

    while (i >= 0 || j >= 0 || carry)
    {
        // 继续加直到两个数字的所有位都处理完且无进位
        sum = carry; // 加上上一轮的进位
        if (i >= 0) sum += a[i--] - '0'; // 将字符串的字符转成数字并累加
        if (j >= 0) sum += b[j--] - '0'; // 同样处理 b 的对应位

        result.push_back((sum % 10) + '0'); // 每次将当前的个位 sum % 10 放入结果中
        carry = sum / 10; // 进位是 sum 的十位，留到下一轮
    }

    reverse(result.begin(), result.end()); // 当前 result 是反的，需要翻转
    return result;
}

// 大整数减法 - 从低位到高位逐位相减，处理借位；需要判断两个数的大小，决定结果是正数还是负数
string subtract(const string& a, const string& b)
{
    string result;
    int borrow = 0, diff = 0;
    string x = a, y = b;
    if (x < y) swap(x, y); // 确保 x >= y，结果是正数
    int i = x.size() - 1, j = y.size() - 1;

    while (i >= 0)
    {
        diff = (x[i] - '0') - (j >= 0 ? (y[j--] - '0') : 0) - borrow;
        if (diff < 0)
        {
            diff += 10; // 借位
            borrow = 1; // 标记借位
        }
        else
        {
            borrow = 0;
        }
        result.push_back(diff + '0');
        i--;
    }

    reverse(result.begin(), result.end());
    return trimLeadingZeros(result); // 去掉前导零
}


// 大整数乘法 - 按位模拟小学算术乘法：用 b 的每一位去乘以 a，累加部分和
string multiply(const string& a, const string& b)
{
    string result(a.size() + b.size(), '0'); // 结果最大长度为 a 和 b 长度之和，用 '0' 填充
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = b.size() - 1; j >= 0; j--)
        {
            int temp = (result[i + j + 1] - '0') + (a[i] - '0') * (b[j] - '0') + carry;
            result[i + j + 1] = temp % 10 + '0'; // 更新当前位
            carry = temp / 10; // 更新进位
        }
        result[i] += carry; // 处理进位
    }
    return trimLeadingZeros(result); // 去掉前导零
}


// 大整数除法 - 按位模拟长除法：使用逐步尝试法，模拟手工长除法，找到商
string divide(const string& a, const string& b)
{
    if (b == "0") return "Error"; // 除零错误
    string result, remainder;
    for (size_t i = 0; i < a.size(); i++)
    {
        remainder.push_back(a[i]); // 当前位加入余数
        remainder = trimLeadingZeros(remainder); // 去掉余数的前导零
        int count = 0;
        while (remainder >= b)
        {
            // 减法计算商
            remainder = subtract(remainder, b);
            count++;
        }
        result.push_back(count + '0'); // 商的当前位
    }
    return trimLeadingZeros(result); // 去掉商的前导零
}


int main()
{
    string a, b, op;
    cin >> a >> op >> b;

    string result;
    if (op == "+") result = add(a, b);
    else if (op == "-") result = subtract(a, b);
    else if (op == "*") result = multiply(a, b);
    else if (op == "/") result = divide(a, b);

    cout << result << endl;
    return 0;
}
