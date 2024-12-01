//
// Created by Ruohao L. on 25/11/2024.
//
#include <iostream>
#include <iomanip> // 包含流操纵算子
using namespace std;

void printBinary(int number)
{
    int width = 0;
    int temp = number;
    while (temp > 0)
    {
        temp /= 2;
        width++;
    }
    cout << bitset<32>(number).to_string().substr(32 - width) << endl;
}

int main()
{
    int number;
    cin >> number;

    // 十六进制输出
    cout << hex << number << endl;

    // 十进制，宽度为10，左边补0
    cout << dec << setw(10) << setfill('0') << number << endl;

    // 八进制输出
    cout << "Octal: " << oct << number << endl;

    // 二进制输出
    cout << "Binary: " << bitset<32>(number) << endl;

    // 二进制输出（自适应宽度）
    cout << "Binary (adaptive width): ";
    printBinary(number);

    return 0;
}

/*扩展问题
 *负数的处理：
如果输入允许负数，可以直接运行代码，十六进制的负数会自动加上前缀（如 -17）。
但宽度补零时不会补负号。
 *多种输出格式：
如果需要同时输出八进制或二进制，可结合位操作或 C++20 的格式库（<format>）。
 *符号扩展：
对负数来说，std::bitset 会以补码形式表示（带符号的二进制数），如 -23 会显示其补码形式。
如果需要处理负数，可以结合逻辑操作。*/
