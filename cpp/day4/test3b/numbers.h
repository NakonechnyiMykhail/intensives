#ifndef NUMBERS_H
#define NUMBERS_H

#include <iostream>

class Numbers
{
private:
   double m_a, m_b, m_c;
public:
    void setValues(double a, double b, double c);
    void print();
    bool isEqual(const Numbers &obj);
    Numbers();
};

#endif // NUMBERS_H
