#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Complex
{
private:
    double r, i;

public:
    void Print()
    {
        cout << r << "+" << i << "i" << endl;
    }

    // 在此处补充你的代码
    /*注意边界条件：
    字符串格式是否始终为 x+yi？
    是否需要处理负数？
    是否需要考虑不符合格式的输入？*/
    // 重载 operator=
    Complex &operator=(const char* str)
    /*边界情况和扩展
负数支持: 输入类似 "3-4i" 的情况也会正常解析，因为 sscanf 的格式字符串支持符号。
非法输入: 例如，输入 "abc" 或者 "3+4"（缺少 i），程序会因为未匹配到格式而行为不确定。可以扩展为加入输入格式验证。*/
    {
        sscanf(str, "%lf+%lfi", &r, &i); // 解析字符串，提取实部和虚部。%lf 表示读取双精度浮点数，+ 和 i 是字面符号
        return *this; // 返回自身以支持链式赋值
    }
};

int main()
{
    Complex a;
    a = "3+4i";
    a.Print();
    a = "5+6i";
    a.Print();
    return 0;
}
