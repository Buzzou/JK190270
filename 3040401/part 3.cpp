#include <iostream>
#include <cstring>
using namespace std;

// 在此处补充你的代码
class Array2
{
private:
    int* data; // 存储一维化的二维数组数据
    int rows, cols; // 行数和列数

public:
    // 默认构造函数 - 初始化空对象
    Array2() : data(nullptr), rows(0), cols(0) {}

    // 带参数构造函数 - 分配 rows * cols 个元素的动态内存
    Array2(int r, int c) : rows(r), cols(c)
    {
        data = new int[rows * cols];
    }

    // 析构函数
    ~Array2()
    {
        delete[] data;
    }

    // 重载 operator[]，返回第 r 行的起始地址 -> 实现 a[i][j] 的语法
    int *operator[](int r)
    {
        return data + r * cols;
    }

    // 重载 operator()，直接返回指定位置的值 -> 支持函数式访问
    int operator()(int r, int c) const
    {
        return data[r * cols + c];
    }

    // 重载赋值操作符，支持深拷贝
    Array2 &operator=(const Array2& other)
    {
        if (this == &other)
        {
            return *this; // 防止自赋值
        }

        // 释放原有数据
        delete[] data;

        // 复制新数据
        rows = other.rows;
        cols = other.cols;
        data = new int[rows * cols];
        //memcpy 可以快速复制一块「连续内存区域」的数据。因为二维数组被存储为一维连续内存，memcpy 很适合这种情况
        memcpy(data, other.data, rows * cols * sizeof(int)); //memcpy复制的是数据内容，而不是内存地址
        //赋值 b = a 后，b.data 和 a.data 指向不同的内存
        //修改 b 的数据仅影响 b.data，不会影响 a.data。

        return *this;
    }
};

int main()
{
    Array2 a(3, 4); //需要实现一个能够指定行和列的构造函数
    int i, j;

    // 填充数据
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            //在访问 a[i][j] 时，j 的递增操作还没有发生，因此这个操作完全与 j++ 或 ++j 的返回值无关
            a[i][j] = i * 4 + j; //通过下标操作符 [] 访问数组中的元素，这需要重载 operator[]

    // 按函数方式访问并打印数据
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << a(i, j) << ","; //使用 a(i, j) 来访问元素，要求重载 () 运算符
        }
        cout << endl;
    }
    cout << "next" << endl;

    // 测试深拷贝
    Array2 b;
    b = a; //b = a，将数组 a 的值赋给数组 b，需要实现赋值运算符 operator=，并确保深拷贝（即数据完全独立，修改 b 不会影响 a）
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
