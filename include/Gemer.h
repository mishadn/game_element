#ifndef GEMER_H
#define GEMER_H
#include <deque>
#include "Unit.h"
#include "Factory.h"
#include <string>

class Gemer
{
    public:
        Gemer(std::string);
        virtual ~Gemer();
        std::string getName() const;
        void printInfo() const;
    private:
        std::deque <Unit*> units;
        std::deque <Factory*> factores;
        std::string const name;
};

#endif // GEMER_H
