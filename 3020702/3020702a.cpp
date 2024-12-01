//
// Created by Ruohao L. on 12/11/2024.
//

#include "3020702a.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Student
{
private:
    std::string name;
    int age;
    std::string studentID;
    int grades[4];

public:
    // 设置学生信息的方法
    void setInfo(const std::string& input)
    {
        std::stringstream ss(input);
        std::string token;

        // 获取姓名
        std::getline(ss, name, ',');

        // 获取年龄
        std::getline(ss, token, ',');
        age = std::stoi(token);

        // 获取学号
        std::getline(ss, studentID, ',');

        // 获取四个学年的成绩
        for (int i = 0; i < 4; ++i)
        {
            std::getline(ss, token, ',');
            grades[i] = std::stoi(token);
        }
    }

    // 计算四年平均成绩并向下取整
    int getAverageGrade() const
    {
        int sum = 0;
        for (int i = 0; i < 4; ++i)
        {
            sum += grades[i];
        }
        return sum / 4; // 自动向下取整
    }

    // 输出信息的方法
    void display() const
    {
        std::cout << name << "," << age << "," << studentID << "," << getAverageGrade() << std::endl;
    }
};

int main()
{
    std::string input;
    std::getline(std::cin, input);

    Student student;
    student.setInfo(input);
    student.display();

    return 0;
}
