#ifndef CIVIL_H
#define CIVIL_H

#include "Unit.h"
#include "gameSets.h"
#include <string>

class Civil : public Unit
{
    public:
        virtual ~Civil();
    protected:
        Civil(units::Units, Cell*, std::string, int, int);

};

#endif // CIVIL_H
