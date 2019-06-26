#include "numbers.h"



void Numbers::set(int first, int second)
{
    m_first = first;
    m_second = second;
}

void Numbers::print()
{
    std::cout << "Numbers(" << m_first << ", " << m_second << ")" << std::endl;
}

Numbers::Numbers()
{

}
Numbers::Numbers(int first, int second)
{
    m_first = first;
    m_second = second;
}
