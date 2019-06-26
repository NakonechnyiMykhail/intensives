//#include <iostream>
#include <string>
#include "add.h"
#include "datestruct.h"
using namespace std;

int main()
{
    /*out << "Enter your name: ";
    string name;
    cin >> name;
    cout << sum(14.5,25.6)<< endl;*/

    DateStruct date;
    date.m_day = 12;
    date.m_month = 3;
    date.m_year = 2019;
    date.printDate();
    date.inputSeason("winter");
    date.printSeason();
    //DateStruct date2 = {2,1,2020};

    return 0;
}


