#ifndef NUMBERS_H
#define NUMBERS_H

#include <iostream>


class Numbers
{
private:
    int m_first;
    int m_second;
public:
    void set(int first, int second);
    void print();
    Numbers();
    Numbers(int first, int second);

};

#endif // NUMBERS_H
