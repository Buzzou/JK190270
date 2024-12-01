#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// 在此处补充你的代码
class MyString : public std::string
{
public:
    // 构造函数继承自 std::string
    MyString() : std::string() {}
    MyString(const char* s) : std::string(s) {}
    MyString(const std::string& s) : std::string(s) {}

    // 重载操作符 `()`，返回从指定起始位置开始，指定长度的子串
    MyString operator()(int start, int length) const
    {
        return this->substr(start, length);
    }

    // 支持从字符串拼接到 MyString
    // friend MyString operator+(const char* lhs, const MyString& rhs)
    // {
    //     return MyString(lhs) + rhs;
    // }
};

int CompareString(const void* e1, const void* e2)
{
    MyString* s1 = (MyString *) e1;
    MyString* s2 = (MyString *) e2;
    if (*s1 < *s2) return -1;
    else if (*s1 == *s2) return 0;
    else if (*s1 > *s2) return 1;
}

int main()
{
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A';
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; ++i)
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5, 10) << endl;
    return 0;
}
