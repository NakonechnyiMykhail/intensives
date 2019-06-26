#ifndef ANIMALS_H
#define ANIMALS_H
#pragma once
#include <iostream>
#include <string>

class Animals
{
protected:
    std::string m_name;
    Animals(std::string name) : m_name(name)
    {
    }
public:
    std::string getName() {return m_name;}
    virtual const char* speak() { return "???";}
};

class Cat: public Animals
{
public:
    Cat(std::string name):Animals(name)
    {
    }
    virtual const char* speak() { return "Meow";}
};


class Dog: public Animals
{
public:
    Dog(std::string name):Animals(name)
    {
    }
    virtual const char* speak() { return "Woow";}
};

void report(Animals &animal){
    std::cout << animal.getName() << " speaks " << animal.speak() << std::endl;
}


#endif // ANIMALS_H
