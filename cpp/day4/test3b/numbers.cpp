#include "numbers.h"



void Numbers::setValues(double a, double b, double c)
{
    m_a = a;
    m_b = b;
    m_c = c;
}

void Numbers::print()
{
    std::cout << "<"<< m_a << ", " << m_b << ", " << m_c << ">" <<std::endl;
}

bool Numbers::isEqual(const Numbers &obj){
    return (m_a == obj.m_a && m_b == obj.m_b && m_c == obj.m_c);
}

Numbers::Numbers()
{

}
