#ifndef TANK_H
#define TANK_H

#include "Military.h"
#include "gameSets.h"
#include <vector>
#include "CellsMap.h"


class Tank : public Military
{
    public:
        Tank(Cell* );
        Tank (Cell* cell, int health, int power, bool isDigIn);
        virtual ~Tank();
        int getPowerBonus() const;
        int getDefenceBonus() const;
        int getDigInBonus() const;
        actions::Actions getAction() const;
        virtual void doAction(actions::Actions, CellsMap*);
    private:
    static std::map <elements::Landscape, int> powerBonus;
    static std::map <elements::Landscape, int> defenceBonus;
    static std::map <elements::Landscape, int> digInBonus;
    static std::vector <actions::Actions> actionsToDO;
};

#endif // TANK_H
