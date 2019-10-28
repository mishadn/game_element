#ifndef UNIT_H
#define UNIT_H

#include "gameSets.h"
#include "Cell.h"
#include "CellsMap.h"


class Unit
{
public:

    virtual ~Unit();
    //virtual std::string getUnitType() const;
    Cell* getCell() const;
    void setCell(Cell*);
    void setHealth(int);
    int getHealth() const;
    void setPower(int);
    int getPower() const;
    std::string getSound() const;
    virtual bool damage(Unit*);
    virtual int getPowerBonus() const = 0;
    virtual int getDefenceBonus() const = 0;
    virtual int getDigInBonus() const = 0;
    virtual actions::Actions getAction() const = 0;
    //virtual actions::Actions t_getAction() const;
    virtual void doAction(actions::Actions, CellsMap*) = 0;
    virtual void digIn();
    virtual void digOut();
    virtual bool getIsDigIn() const;
    void printInfo() const;
    std::string printInfoLine() const;
    std::string toString() const;
    units::UnitTypes getUnitType() const;
    units::Units getUnitName() const;

protected:
    Unit(units::UnitTypes, units::Units, Cell*, std::string, int, int);
private:
    const units::UnitTypes unitType;
    const units::Units unitName;
    Cell* cell;
    int health;
    int power;
    bool isDigIn = false;
    std::string sound;

};

#endif // UNIT_H
