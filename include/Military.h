#ifndef MILITARY_H
#define MILITARY_H

#include "Unit.h"
#include "Cell.h"


class Military : public Unit
{
    public:

        virtual ~Military();
        virtual bool attack(Unit*);
    protected:
        Military(units::Units, Cell*, std::string, int, int);
};

#endif // MILITARY_H
