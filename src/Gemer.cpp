#include "Gemer.h"
#include <string>
#include <iostream>

Gemer::Gemer(std::string n) : name(n)
{
    std::cout << "Gemer::Gemer(std::string n) : name(n)" << std::endl;
}

Gemer::~Gemer()
{
    //dtor
}

std::string Gamer::getName()
{
    return name;
}
