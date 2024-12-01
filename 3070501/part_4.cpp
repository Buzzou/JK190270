//
// Created by Ruohao L. on 25/11/2024.
//
//TODO:类似编译原理
#include <iostream>
#include <string>
#include <vector>
#include <cctype> // 判断数字用
using namespace std;

// 全局存储所有字符串 - 所有操作都可以直接修改或访问这个数组
vector<string> strings;

// 判断字符串是否为整数
bool isInteger(const string& str)
{
    for (char c: str)
    {
        if (!isdigit(c)) return false;
    }
    return !str.empty(); //空字符串也被认为不是整数
}

// 解析命令并执行 - 当一个函数需要在它的实现体中递归调用自身或调用其他未定义的函数时，我们需要先声明这个函数，否则编译器会报错
string executeCommand(const string& command);

// 解析并返回字符串
string parseString(const string& expr)
{
    if (expr.substr(0, 4) == "copy")
    {
        int N, X, L;
        //递归调用 executeCommand，解析嵌套命令
        size_t pos = 5;
        string arg1 = executeCommand(expr.substr(pos, expr.find(' ', pos) - pos));
        pos += arg1.size() + 1;
        string arg2 = executeCommand(expr.substr(pos, expr.find(' ', pos) - pos));
        pos += arg2.size() + 1;
        string arg3 = executeCommand(expr.substr(pos));
        N = stoi(arg1);
        X = stoi(arg2);
        L = stoi(arg3);
        //std::string::substr 返回从 X 开始、长度为 L 的子串
        return strings[N - 1].substr(X, L);
    }
    else if (expr.substr(0, 3) == "add")
    {
        //递归调用 executeCommand，解析嵌套命令
        size_t pos = 4;
        string S1 = executeCommand(expr.substr(pos, expr.find(' ', pos) - pos));
        pos += S1.size() + 1;
        string S2 = executeCommand(expr.substr(pos));
        //若 S1 和 S2 都是整数，转为整数后相加，结果转换为字符串返回。 否则拼接两个字符串
        if (isInteger(S1) && isInteger(S2))
        {
            return to_string(stoi(S1) + stoi(S2));
        }
        else
        {
            return S1 + S2;
        }
    }
    else
    {
        return expr; // 直接返回
    }
}

// 解析并返回整数
int parseInteger(const string& expr)
{
    if (expr.substr(0, 4) == "find")
    {
        size_t pos = 5;
        string S = executeCommand(expr.substr(pos, expr.find(' ', pos) - pos));
        pos += S.size() + 1;
        int N = stoi(executeCommand(expr.substr(pos)));
        return strings[N - 1].find(S);
    }
    else if (expr.substr(0, 5) == "rfind")
    {
        size_t pos = 6;
        string S = executeCommand(expr.substr(pos, expr.find(' ', pos) - pos));
        pos += S.size() + 1;
        int N = stoi(executeCommand(expr.substr(pos)));
        return strings[N - 1].rfind(S);
    }
    else
    {
        return stoi(expr); // 直接返回整数
    }
}

// 执行命令
string executeCommand(const string& command)
{
    if (command.substr(0, 6) == "insert")
    {
        size_t pos = 7;
        //递归调用 executeCommand 解析 S，因为它可能是嵌套命令（如 copy）
        string S = executeCommand(command.substr(pos, command.find(' ', pos) - pos));
        //使用 parseInteger 解析 N 和 X，它们可能是 find 或 rfind 返回的结果
        pos += S.size() + 1;
        int N = parseInteger(command.substr(pos, command.find(' ', pos) - pos));
        pos += to_string(N).size() + 1;
        int X = parseInteger(command.substr(pos));
        //使用 std::string::insert 将 S 插入到第 N 个字符串的第 X 个位置。
        strings[N - 1].insert(X, S);
        return "";
    }
    else if (command.substr(0, 5) == "reset")
    {
        size_t pos = 6;
        //S 和 N 可能是嵌套命令的结果
        string S = executeCommand(command.substr(pos, command.find(' ', pos) - pos));
        pos += S.size() + 1;
        int N = parseInteger(command.substr(pos));
        //使用 std::string::assign 将第 N 个字符串重置为 S
        strings[N - 1] = S;
        return "";
    }
    else if (command.substr(0, 5) == "print")
    {
        //解析出字符串编号 N，输出第 N 个字符串
        int N = parseInteger(command.substr(6));
        cout << strings[N - 1] << endl;
        return "";
    }
    else if (command == "printall")
    {
        //遍历 strings 数组，依次输出每个字符串
        for (const string& s: strings)
        {
            cout << s << endl;
        }
        return "";
    }
    else if (command == "over")
    {
        exit(0);
    }
    else
    {
        if (isdigit(command[0]) || command[0] == '-')
        {
            return command;
        }
        else //如果命令不属于上述类型，默认解析为 copy 或 add，进一步交由 parseString 处理
        {
            return parseString(command);
        }
    }
}

// 主函数
int main()
{
    //读取字符串数量 n，然后读取 n 个字符串
    int n;
    cin >> n;
    /*当我们使用 cin 进行输入时，按下回车键（Enter）会将回车符（\n）存储在输入缓冲区中。
     *如果不清除缓冲区中遗留的 \n，随后的 getline(cin, s) 会直接读取这个 \n，导致 s 为空*/
    cin.ignore(); //忽略输入缓冲区中的一个字符
    //cin.ignore(n, '\n')，忽略最多 n 个字符，直到遇到换行符（\n）
    /* 在 C++ 中，vector 是动态大小的容器。但如果我们提前知道需要存储多少个元素，可以通过 resize 方法调整容器大小。*/
    strings.resize(n); //调整 strings 容器的大小，使其可以存储 n 个字符串
    /*如果当前 strings 的大小小于 n，会新增元素以填充到大小 n。
     *如果当前 strings 的大小大于 n，会移除多余的元素。
     *新增的元素会被初始化为默认值（对于 string，默认值是空字符串 ""）*/
    for (int i = 0; i < n; i++)
    {
        getline(cin, strings[i]);
    }
    //循环读取每行命令，调用 executeCommand 执行，直到 over 命令结束程序
    string command;
    while (getline(cin, command))
    {
        executeCommand(command);
    }
    return 0;
}
