#ifndef DATESTRUCT_H
#define DATESTRUCT_H
#pragma once
#include <iostream>
#include <string>

class DateStruct
{
private:
    std::string season;
public:
    DateStruct();
    int m_day;
    int m_month;
    int m_year;
    //void printDate();
    void printDate(){
        std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
    }
    void printSeason(){
        std::cout << season << std::endl;
    }
    std::string inputSeason(std::string seasonInput) {
        season = seasonInput;
        return season;
    }

};


//struct DateStruct2
//{
//    int day;
//    int month;
//    int year;
//};

//void printDateStruct2(DateStruct2 a) {
//    std::cout << a.day << std::endl;
//}

#endif // DATESTRUCT_H
