//
// Created by Ruohao L. on 07/11/2024.
//

#include "1130101d.h"
#include <iostream>
using namespace std;

void Simple_calculator()
{
    int a, b;
    char op;
    cin >> a >> b >> op;

    switch (op)
    {
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            if (b == 0)
            {
                cout << "Divided by zero!" << endl;
            }
            else
            {
                cout << a / b << endl;
            }
            break;
        default:
            cout << "Invalid operator!" << endl;
            break;
    }
}
