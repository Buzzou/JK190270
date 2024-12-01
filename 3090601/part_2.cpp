#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
// 自定义输入流迭代器模板
template<typename T>
class CMyistream_iterator
{
private:
    istream& is; // 引用输入流
    T value; // 当前读取的值
    bool endOfStream; // 用于标记流是否已经结束

public:
    // 构造函数，从流中读取第一个值
    CMyistream_iterator(istream& input) : is(input), endOfStream(false)
    {
        is >> value; // 从输入流中读取第一个值
        if (!is) endOfStream = true; // 如果流已结束，设置标记
    }

    // 解引用操作，返回当前（迭代器所指向的）值
    // 如果你只是想多次访问当前值，只需要多次调用 *，而不必重新读取流
    /* const 的含义是：解引用操作不会修改当前的迭代器对象
     * 加了 const 后，可以在 const 对象上调用这个函数；如果没有加 const，则无法对 const 对象调用 operator*，这会影响代码的通用性
     */
    // T 没有加 &：返回的是一个当前值的拷贝，而不是对内部值的引用。每次调用 operator++ 后，当前值会被替换。返回引用会导致引用悬空问题
    T operator*() const
    {
        return value;
    }

    // 前置自增操作，从流中读取下一个值
    // 如果要读取下一个值，才调用 ++ 操作
    /* operator++() 的功能是修改迭代器状态，从输入流中读取下一个值。因此它必须改变成员变量（例如 value 和输入流状态）。
     * 因此，这个操作不能是 const，因为它需要改变迭代器对象
     */
    /* 返回对当前对象的引用是链式调用的惯例，如果返回的是当前对象的拷贝，那么每次调用 ++ 时都会创建一个新的迭代器对象，开销更大，且
     * 每次调用 ++ 时都会创建一个新的迭代器对象，开销更大
     */
    CMyistream_iterator& operator++()
    {
        if (!endOfStream)
        {
            is >> value; // 读取下一个值
            if (!is) endOfStream = true; // 如果流已结束，设置标记}
            return *this;
        }
    };

    // 后置自增操作符
    /*保存当前对象的状态（通过拷贝构造）。
     *使用前置自增更新当前对象的状态。
     *返回保存的对象（拷贝）。*/
    CMyistream_iterator operator++(int)
    {
        CMyistream_iterator temp = *this; // 保存当前状态
        ++(*this); // 使用前置自增更新状态
        return temp; // 返回保存的状态
    }
};

int main()
{
    // 处理整型输入
    CMyistream_iterator<int> inputInt(cin);
    int n1, n2, n3;

    n1 = *inputInt; // 读入第一个整数
    int tmp = *inputInt; // 再次读取当前整数
    cout << tmp << endl;

    inputInt++; // 移动到下一个输入值
    n2 = *inputInt; // 读入第二个整数

    inputInt++; // 再移动到下一个输入值
    n3 = *inputInt; // 读入第三个整数

    cout << n1 << "," << n2 << "," << n3 << endl;

    // 处理字符串输入
    CMyistream_iterator<string> inputStr(cin);
    string s1, s2;

    s1 = *inputStr; // 读入第一个字符串
    inputStr++; // 移动到下一个输入值
    s2 = *inputStr; // 读入第二个字符串

    cout << s1 << "," << s2 << endl;
    return 0;
}
