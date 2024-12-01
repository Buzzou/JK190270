//
// Created by Ruohao L. on 30/11/2024.
//
#include <iostream>
#include <cstring>
using namespace std;

// 在此处补充你的代码
class MyString
{
private:
    char* str; // 用于存储字符串 - 通过 char* str 动态分配字符串空间
public:
    // 默认构造函数
    MyString() : str(new char[1])
    {
        str[0] = '\0';
    }

    // 构造函数：从 const char* 初始化
    MyString(const char* s) : str(new char[strlen(s) + 1])
    {
        strcpy(str, s);
    }

    // 拷贝构造函数
    MyString(const MyString& other) : str(new char[strlen(other.str) + 1])
    {
        strcpy(str, other.str);
    }

    // 析构函数 - 避免内存泄漏
    ~MyString()
    {
        delete[] str;
    }

    // 赋值运算符：MyString
    MyString& operator=(const MyString& other)
    {
        if (this == &other) return *this; // 防止自我赋值
        delete[] str; // 释放原有内存
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
        return *this;
    }

    // 赋值运算符：const char*
    MyString& operator=(const char* s)
    {
        delete[] str; // 释放原有内存
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        return *this;
    }

    // 加法运算符：拼接字符串
    MyString operator+(const MyString& other) const
    {
        char* temp = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        MyString result(temp);
        delete[] temp;
        return result;
    }

    // 加法运算符：拼接 const char* - 只支持 MyString 类型作为左操作数 - 相当于 obj = obj.operator+(s);
    MyString operator+(const char* s) const
    {
        char* temp = new char[strlen(str) + strlen(s) + 1];
        strcpy(temp, str);
        strcat(temp, s);
        MyString result(temp);
        delete[] temp;
        return result;
    }

    // += 运算符
    MyString& operator+=(const char* s)
    {
        char* temp = new char[strlen(str) + strlen(s) + 1];
        strcpy(temp, str);
        strcat(temp, s);
        delete[] str; //放了 str 原来指向的动态内存，防止其无法再被访问或释放（内存泄漏）
        str = temp;
        return *this;
    }

    // [] 运算符：访问或修改指定字符
    char& operator[](int index)
    {
        return str[index];
    }

    // 比较运算符：字典序
    bool operator<(const MyString& other) const
    {
        return strcmp(str, other.str) < 0;
    }

    bool operator>(const MyString& other) const
    {
        return strcmp(str, other.str) > 0;
    }

    bool operator==(const MyString& other) const
    {
        return strcmp(str, other.str) == 0;
    }

    // 输出流运算符
    friend ostream& operator<<(ostream& os, const MyString& obj)
    {
        os << obj.str;
        return os;
    }

    // 提取子串：() 运算符
    MyString operator()(int start, int length) const
    {
        char* temp = new char[length + 1];
        strncpy(temp, str + start, length);
        temp[length] = '\0';
        MyString result(temp);
        delete[] temp;
        return result;
    }

    // 获取内部字符串（辅助函数）
    const char* c_str() const
    {
        return str;
    }

    // 只声明，不定义
    friend MyString operator+(const char* lhs, const MyString& rhs);
};

// 全局重载 operator+，支持 const char* + MyString
// MyString operator+(const char* lhs, const MyString& rhs)
// {
//     MyString result(lhs);
//     result += rhs.c_str();
//     return result;
// }

// 全局重载 operator+，支持 const char* + MyString
MyString operator+(const char* lhs, const MyString& rhs)
{
    // 拼接左侧的 C 字符串和右侧的 MyString 的内容
    MyString result(lhs);
    result += rhs.str; // 调用已实现的 operator+=
    return result;
}


int CompareString(const void* e1, const void* e2)
{
    MyString* s1 = (MyString *) e1;
    MyString* s2 = (MyString *) e2;
    if (*s1 < *s2)
        return -1;
    else if (*s1 == *s2)
        return 0;
    else if (*s1 > *s2)
        return 1;
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
    s4 = "qrst-" + s2; //如果不friend，’+‘就只支持 MyString 类型作为左操作数 - 相当于 "qrst-" = "qrst-".operator+(s2);
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; i++)
        cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5, 10) << endl;
    return 0;
}
