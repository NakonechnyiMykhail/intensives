#include "numbers.h"

int main()
{
    Numbers n1;
    n1.set(3, 3); // инициализируем объект n1 значениями 3 и 3
    Numbers n2{4,4}; // инициализируем объект n2 значениями 4 и 4
    n1.print();
    n2.print();


    return 0;
}
