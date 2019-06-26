#include <iostream>
#include "numbers.h"

using namespace std;

int main()
{
    //a
    Numbers point;
    point.setValues(3.0, 4.0, 5.0);
    point.print();

    //b
    Numbers point1;
    point1.setValues(3.0, 4.0, 5.0);
    Numbers point2;
    point2.setValues(3.0, 4.0, 5.0);
    if (point1.isEqual(point2))
        std::cout << "point1 and point2 are equal\n";
    else
        std::cout << "point1 and point2 are not equal\n";
    Numbers point3;
    point3.setValues(7.0, 8.0, 9.0);
    if (point1.isEqual(point3))
        std::cout << "point1 and point3 are equal\n";
    else
        std::cout << "point1 and point3 are not equal\n";


    return 0;
}
