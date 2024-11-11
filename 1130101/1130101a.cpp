//
// Created by Ruohao L. on 07/11/2024.
//

#include "1130101a.h"
#include <iostream>
using namespace std;

void Judge_leap_year()
{
    int a;
    cin >> a;

    if (a % 3200 == 0)
    {
        cout << "N" << endl;
    }

    else if (a % 400 == 0)
    {
        cout << "Y" << endl;
    }
    else if (a % 100 == 0)
    {
        cout << "N" << endl;
    }

    else if (a % 4 == 0)
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
}
