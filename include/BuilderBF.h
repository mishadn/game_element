#ifndef BILDERBF_H
#define BILDERBF_H

#include "Civil.h"
#include "BuilderFactory.h"

class BuilderBF : public Civil
{
    public:
        BuilderBF(Cell*);
        virtual ~BuilderBF();
        BuilderFactory* createBuilderFactory() const;
        int getPowerBonus() const;
        int getDefenceBonus() const;
        int getDigInBonus() const;

    protected:

    private:
};

#endif // BILDERBF_H
