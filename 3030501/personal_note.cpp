//
// Created by Ruohao L. on 13/11/2024.
//
#include <iostream>
#include <string>
using namespace std;

// 定义 BankAccount 类
class BankAccount
{
private:
    string accountHolder;
    double balance;
    /*静态成员变量 (Static Member Variable) - 所有账户共享的年利率
 *用静态成员函数 setInterestRate 修改
 *这样不需要在每个账户对象中存储一份利率数据，提高了效率和一致性。
 * sizeof 运算符不会计算静态成员变量。
    * 本质上是全局变量，哪怕一个对象都不存在，类的静态成员变量也存在*/
    static double interestRate;

public:
    // 复制构造函数 (Copy Constructor) - 以「现有对象的数据为基础」初始化 - 其只有一个参数,即对同类对象的引用。
    // 如果在析构函数中减少了某一个static变量，要在复制构造函数中相应地增加；否则只减少不增加了
    BankAccount(const BankAccount& other)
        : accountHolder(other.accountHolder), balance(other.balance)
    {
        cout << "Copy constructor called for " << accountHolder << endl;
    }

    // 类型转换构造函数 (Conversion Constructor) - 接受一个 double 余额，并将其转换为 BankAccount 对象
    explicit BankAccount(double initialBalance)
        : accountHolder("Unknown"), balance(initialBalance)
    {
        cout << "Conversion constructor called with balance: " << balance << endl;
    }

    // 普通构造函数 (Regular Constructor)
    BankAccount(const string& holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance)
    {
        cout << "Constructor called for " << accountHolder << endl;
    }

    /*析构函数 (Destructor) - 在 main 函数执行完毕后，会自动调用析构函数
     *名字与类名相同
     *在前面加 ‘~’
     *没有参数和返回值
     *一个类最多只有一个析构函数*/
    ~BankAccount()
    {
        cout << "Destructor called for " << accountHolder << endl;
    }

    // 静态成员函数 (Static Member Function) - 用于更新所有账户的利率 - 用于修改静态变量 interestRate - 本质上是全局函数
    static void setInterestRate(double rate)
    {
        interestRate = rate;
    }

    // 常成员函数：计算并返回账户的当前余额（包括利息） (Constant Member Function)
    // 只能修改static成员变量的值，只能调用static/const成员函数
    double calculateBalanceWithInterest() const
    {
        return balance * (1 + interestRate);
    }

    // 常成员函数 (Constant Member Function) - 用于输出账户信息 - 在提供安全只读接口时很有用，确保它不会修改对象的状态
    void printAccountInfo() const
    {
        cout << "Account Holder: " << accountHolder << ", Balance: " << balance << endl;
    }

    // 非常量成员函数 (Non-Constant Member Function) - 用于存入金额
    void deposit(double amount)
    {
        this->balance += amount; // 使用 this 指针 (this Pointer) - 确保对正确的对象进行操作
    }

    // 友元函数 (Friend Function) - 允许外部函数访问私有成员 - 在这里帮助显示账户余额信息
    friend void showAccountBalance(const BankAccount& account);
};

// 静态成员变量初始化 (Static Member Variable Initialization)
// 必须在定义类的文件中对静态成员变量进行一次说明或初始化。否则编译能通过，链接不能通过。
double BankAccount::interestRate = 0.05;

// 友元函数定义 (Friend Function Definition)
void showAccountBalance(const BankAccount& account)
// 可以访问该类的private成员
{
    cout << "Friend function - Account Balance for " << account.accountHolder << ": " << account.balance << endl;
}

int main()
{
    // 使用类型转换构造函数 (Using Conversion Constructor)
    BankAccount anonymousAccount(100.0);
    anonymousAccount.printAccountInfo();

    // 使用普通构造函数 (Using Regular Constructor)
    BankAccount aliceAccount("Alice", 500.0);
    aliceAccount.printAccountInfo();

    // 使用复制构造函数 (Using Copy Constructor)
    BankAccount copyAlice(aliceAccount);
    copyAlice.printAccountInfo();

    // 静态成员函数 (Using Static Member Function)
    BankAccount::setInterestRate(0.03);
    cout << "Alice's balance with interest: " << aliceAccount.calculateBalanceWithInterest() << endl;

    // 友元函数 (Using Friend Function)
    showAccountBalance(aliceAccount);

    // 常量对象和常成员函数 (Constant Object and Constant Member Function)
    const BankAccount constAccount("ConstantAccount", 200.0);
    constAccount.printAccountInfo(); // 只能调用static/const成员函数 (Calling Constant Member Function)，及修改static成员变量的值

    return 0;
}
