//
// Created by Ruohao L. on 07/11/2024.
//

#include "1130101b.h"
#include <iostream>
using namespace std;

void Numbers_can_be_removed()
{
    int n;
    while (cin >> n)
    {
        bool div3 = (n % 3 == 0);
        bool div5 = (n % 5 == 0);
        bool div7 = (n % 7 == 0);

        if (div3 && div5 && div7)
        {
            cout << "3 5 7" << endl;
        }
        else if (div3 && div5)
        {
            cout << "3 5" << endl;
        }
        else if (div3 && div7)
        {
            cout << "3 7" << endl;
        }
        else if (div5 && div7)
        {
            cout << "5 7" << endl;
        }
        else if (div3)
        {
            cout << "3" << endl;
        }
        else if (div5)
        {
            cout << "5" << endl;
        }
        else if (div7)
        {
            cout << "7" << endl;
        }
        else
        {
            cout << "n" << endl;
        }
    }
}
