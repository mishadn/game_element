#include "Tank.h"
#include "gameSets.h"
#include <iostream>
#include "Cell.h"
#include <vector>
#include "CellsMap.h"

std::map <elements::Landscape, int> Tank::powerBonus ={{elements::WaterLand, 2}, {elements::SandLand, 3},{elements::ForestLand, -7}, {elements::MountLand, -1}};
std::map <elements::Landscape, int> Tank::defenceBonus ={{elements::WaterLand, 2}, {elements::SandLand, 3},{elements::ForestLand, 2}, {elements::MountLand, 4}};
std::map <elements::Landscape, int> Tank::digInBonus ={{elements::WaterLand, 20}, {elements::SandLand, 30},{elements::ForestLand, 20}, {elements::MountLand, 40}};
std::vector <actions::Actions> Tank::actionsToDO = {actions::Move, actions::Attack};



void Tank::doAction(actions::Actions act, CellsMap* cellsMap)
{
    switch(act)
    {
    case actions::Attack :
        {
            std::cout << "attack()......." << std::endl;
            break;
        }
    case actions::Move :
        {
            int x;
            int y;
            std::cout << "x = ";
            std::cin >> x;
            std::cout << "y = ";
            std::cin >> y;
            setCell(cellsMap->cell[x][y][1]);
            break;
        }
    }
}

actions::Actions Tank::getAction() const
{
    actions::Actions res = actions::Move;
    for(int i = 0; i < Tank::actionsToDO.size(); i++)
    {
        std::cout << i << " - " << actions::getActionName(Tank::actionsToDO[i]) << std::endl;
    }
    while (true)
    {
        int i = 0;
        std::cin >> i;
        if (i>=0 && i <= Tank::actionsToDO.size())
            {
                res = Tank::actionsToDO[i];
                break;
            }
    }
    return res;
}

Tank::Tank(Cell* c) : Military(units::Tank, c, units::TANK_SOUND, units::TANK_HEALTH, units::TANK_POWER)
{
    std::cout << "Tank::Tank(Cell* c) : Military(units::Tank..." << std::endl;
}

Tank::Tank (Cell* c, int h, int p, bool isDigIn) : Military(units::Tank, c, units::TANK_SOUND, h, p)
{
    std::cout << "Tank::Tank (Cell* c, int h, int p, bool isDigIn) : Military(units::Tank, c, units::TANK_SOUND, h, p)" << std::endl;
    if(isDigIn)
    {
        digIn();
    }
}

Tank::~Tank()
{
    std::cout << "Tank::~Tank()" << std::endl;
}
//-----------------------------------------------
int Tank::getPowerBonus() const
{
    /*Cell* cell = nullptr;
    cell = getCell();
    int res = 0;
    if (cell)
        res = Tank::powerBonus[cell->getCellElementType()];
    else
        std::cout << "You are not in cell." << std::endl;
    return res;*/
    return Tank::powerBonus[getCell()->getCellLandscape()];
}

int Tank::getDefenceBonus() const
{
    /*Cell* cell = nullptr;
    cell = getCell();
    int res = 0;
    if (cell)
        res = Tank::defenceBonus[cell->getCellType()];
    else
        std::cout << "You are not in cell." << std::endl;
    return res;*/
    return Tank::defenceBonus[getCell()->getCellLandscape()];
}

int Tank::getDigInBonus() const
{
    /*Cell* cell = nullptr;
    cell = getCell();
    int res = 0;
    if (cell)
        res = Tank::digInBonus[cell->getCellType()];
    else
        std::cout << "You are not in cell." << std::endl;
    return res;*/
    return Tank::digInBonus[getCell()->getCellLandscape()];
}
