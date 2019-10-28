#ifndef BUILDERFACTORY_H
#define BUILDERFACTORY_H
#include "Builder.h"
#include "Factory.h"
#include "CivilFactory.h"


//class Builder
class BuilderFactory : public CivilFactory, public Factory//, private Builder
{
    public:
        BuilderFactory(Cell*);
        BuilderFactory(Cell*, int, int, bool);
        virtual ~BuilderFactory();
        virtual Builder* getUnit() const;
        virtual void printInfo() const;
        std::string printInfoLine() const;
        virtual std::string toString() const;
        virtual std::string toStringWord() const;
        virtual actions::Actions getAction() const;
    private:
        static std::vector <actions::Actions> actionsToDO;
};

#endif // BUILDERFACTORY_H
