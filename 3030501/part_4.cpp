//
// Created by Ruohao L. on 13/11/2024.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//武士
class Warrior
{
public:
    string type; //类型 - 共5种
    int strength; //生命值
    int id; //编号 - 从1起算
    Warrior(string t, int s, int i) : type(t), strength(s), id(i) {}
};

//司令部，负责根据特定顺序生成武士
class Headquarter
{
public:
    string color; //司令部的颜色（红或蓝）
    int life; //当前司令部的生命元数量(制造武士需要生命元：制造一个初始生命值为m的武士，司令部中的生命元就要减少m个)
    vector<int> order; // 生成武士的顺序（红魔和蓝魔的生成顺序不同）
    vector<int> strengths; //每种武士的生命值
    vector<int> count; // 记录每种武士的数量
    int next; // 下一次要生成的武士类型
    bool stopped; // 是否停止生成

    Headquarter(string c, int m, vector<int> str, vector<int> ord)
        : color(c), life(m), strengths(str), order(ord), next(0), stopped(false)
    {
        count = vector<int>(5, 0);
    }

    bool createWarrior(int time) //每个整点降生一个武士
    {
        if (stopped) return false;

        int attempts = 0;
        while (attempts < 5)
        {
            int type = order[next];
            int strength = strengths[type];
            if (life >= strength)
            {
                life -= strength;
                count[type]++;
                int id = count[type];
                string warriorType = getWarriorType(type);
                cout << setw(3) << setfill('0') << time << " " << color << " " << warriorType
                        << " " << id << " born with strength " << strength << ","
                        << count[type] << " " << warriorType << " in " << color << " headquarter" << endl;
                next = (next + 1) % 5;
                return true;
            }
            next = (next + 1) % 5;
            attempts++;
        }

        cout << setw(3) << setfill('0') << time << " " << color << " headquarter stops making warriors" << endl;
        stopped = true;
        return false;
    }

    string getWarriorType(int index)
    {
        switch (index)
        {
            case 0: return "dragon";
            case 1: return "ninja";
            case 2: return "iceman";
            case 3: return "lion";
            case 4: return "wolf";
        }
        return "";
    }
};

int main()
{
    int cases;
    cin >> cases;
    for (int caseNum = 1; caseNum <= cases; ++caseNum)
    {
        int M;
        vector<int> strengths(5);
        vector<int> redOrder = {2, 3, 4, 1, 0}; // iceman, lion, wolf, ninja, dragon
        vector<int> blueOrder = {3, 0, 1, 2, 4}; // lion, dragon, ninja, iceman, wolf

        cin >> M;
        for (int i = 0; i < 5; ++i)
        {
            cin >> strengths[i];
        }

        Headquarter redHQ("red", M, strengths, redOrder);
        Headquarter blueHQ("blue", M, strengths, blueOrder);

        cout << "Case:" << caseNum << endl;
        int time = 0;
        while (!redHQ.stopped || !blueHQ.stopped)
        {
            if (!redHQ.stopped) redHQ.createWarrior(time);
            if (!blueHQ.stopped) blueHQ.createWarrior(time);
            time++;
        }
    }
    return 0;
}
