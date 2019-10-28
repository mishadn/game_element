#include <iostream>
#include <string.h>
#include <fstream>
#include "Tank.h"
#include "Builder.h"
#include "Unit.h"
#include "CellsMap.h"
#include "Cell.h"
#include "Game.h"
#include "Gamer.h"

Unit* loadUnit(units::UnitTypes unitType, units::Units unit, int x, int y, int z, int health, int power, int isDigIn, CellsMap* cellsMap)
{
    std::cout << "create unit" << std::endl;
    Unit* res;
    switch(unit)
    {
    case units::Tank :
    {
        res = new Tank(cellsMap->cell[x][y][z], health, power, isDigIn);
        break;
    }
    case units::Builder :
    {
        res = new Builder(cellsMap->cell[x][y][z], health, power, isDigIn);
        break;
    }
    }
    return res;
}



Game* loadGame(std::string fileInName, CellsMap* cellsMap)
{
    Game* game = new Game("first game", cellsMap);
    std::ifstream fileIn;
    std::cout << "fileInName = " << fileInName << std::endl;
    fileIn.open(fileInName);
    while(!fileIn.eof())
    {
        //  std::string strIn;
        char buff[100];
        char* pch;
        pch = "";
        char* gamerName;
        gamerName = "";
        fileIn.getline(buff, 100);
        std::string strBuff = buff;
        //strBuff.lenght();
        if(strBuff.empty())
        {
            break;
        }
        std::string strGamerName = "";
        std::string strCurrGamerName = "";
        //    strIn = buff;
        std::cout << " OOOOO " << buff << std::endl << std::endl;
        pch = strtok(buff, ";");
        strGamerName = pch;
        std::cout << " gamer is " << strGamerName << std::endl;
        std::cout << " gamerName before if " << strCurrGamerName << std::endl;
        if(strGamerName != strCurrGamerName)
        {
            std::cout << " old gamer is " << strCurrGamerName << std::endl;
            std::cout << " gamer is " << strGamerName << std::endl;
            strCurrGamerName = strGamerName;
            game->loadGamer(strCurrGamerName);
            std::cout << "after create gamer " << std::endl;
            pch = strtok(nullptr, ";");
            game->takeGamer(strCurrGamerName);
        }


        std::cout << " For gamer  " << strCurrGamerName << std::endl;
        pch = strtok(nullptr, ";");
        if (strcmp(pch, "Unit"))
            //while (pch)
        {
            std::cout << pch << std::endl;
            //std::cout << "NULL = " << NULL << std::endl;
            pch = strtok(nullptr, ";");
            units::UnitTypes unitType = units::intToUnitTypes(atoi(pch));
            std::cout << units::getUnitTypeName(unitType) << std::endl;
            pch = strtok(nullptr, ";");
            units::Units unit = units::intToUnits(atoi(pch));
            std::cout <<units::getUnitName(unit) << std::endl;
            pch = strtok(nullptr, ";");
            int x = atoi(pch);
            std::cout << "x = " << x << std::endl;
            pch = strtok(nullptr, ";");
            int y = atoi(pch);
            std::cout << "y = " << y << std::endl;
            pch = strtok(nullptr, ";");
            int z = atoi(pch);
            std::cout << "z = " << z << std::endl;
            pch = strtok(nullptr, ";");
            int health = atoi(pch);
            std::cout << "health = " << health << std::endl;
            pch = strtok(nullptr, ";");
            int power = atoi(pch);
            std::cout << "power = " << power << std::endl;
            pch = strtok(nullptr, ";");
            bool isDigIn = atoi(pch);
            std::cout << "isDigIn = " << std::boolalpha << isDigIn << std::endl;

            game->getCurrGamer()->pushUnit(loadUnit(unitType, unit, x, y, z, health, power, isDigIn, cellsMap));

            //Unit* u01 = loadUnit(unitType, unit, x, y, z, health, power, isDigIn, cellsMap);
            //u01->printInfo();
            //    std::cout << "u01->getPowerBonus() = " << u01->getPowerBonus() << std::endl;

        }
        else
        {
        if (strcmp(pch, "Factory"))
        {
            std::cout << pch << std::endl;
            //std::cout << "NULL = " << NULL << std::endl;
            pch = strtok(nullptr, ";");
            factory::FactoryTypes FactoryType = factory::intToFactoryTypes(atoi(pch));
            std::cout << factory::getFactoryTypeName(FactoryType) << std::endl;
            pch = strtok(nullptr, ";");
            factory::Factorys factoryName = factory::intToFactory(atoi(pch));
            std::cout << factory::getFactoryName(factoryName) << std::endl;
            pch = strtok(nullptr, ";");
            int x = atoi(pch);
            std::cout << "x = " << x << std::endl;
            pch = strtok(nullptr, ";");
            int y = atoi(pch);
            std::cout << "y = " << y << std::endl;
            pch = strtok(nullptr, ";");
            int z = atoi(pch);
            std::cout << "z = " << z << std::endl;
            pch = strtok(nullptr, ";");
            int health = atoi(pch);
            std::cout << "health = " << health << std::endl;
            pch = strtok(nullptr, ";");
            int power = atoi(pch);
            std::cout << "power = " << power << std::endl;
            pch = strtok(nullptr, ";");
            bool isDigIn = atoi(pch);
            std::cout << "isDigIn = " << std::boolalpha << isDigIn << std::endl;

           // game->getCurrGamer()->pushUnit(loadUnit(unitType, unit, x, y, z, health, power, isDigIn, cellsMap));

        }
        }
    }
    fileIn.close();
    std::cout << "close file" << std::endl;
    return game;

}


/*
void loadGame(std::string fileInName, CellsMap* cellsMap)
{
    std::ifstream fileIn;
    fileIn.open(fileInName);
    while(!fileIn.eof())
    {
      //  std::string strIn;
        char buff[100];
        char* pch;
        fileIn.getline(buff, 100);
    //    strIn = buff;
        std::cout << " OOOOO " << buff << std::endl << std::endl;
        pch = strtok(buff, ";");
        if (!strcmp(pch, "Unit"))
        //while (pch)
        //{
            std::cout << pch << std::endl;
            //std::cout << "NULL = " << NULL << std::endl;
            pch = strtok(nullptr, ";");
            units::UnitTypes unitType = units::intToUnitTypes(atoi(pch));
            std::cout << units::getUnitTypeName(unitType) << std::endl;
            pch = strtok(nullptr, ";");
            units::Units unit = units::intToUnits(atoi(pch));
            std::cout <<units::getUnitName(unit) << std::endl;
            pch = strtok(nullptr, ";");
            int x = atoi(pch);
            std::cout << "x = " << x << std::endl;
            pch = strtok(nullptr, ";");
            int y = atoi(pch);
            std::cout << "y = " << y << std::endl;
            pch = strtok(nullptr, ";");
            int z = atoi(pch);
            std::cout << "z = " << z << std::endl;
            pch = strtok(nullptr, ";");
            int health = atoi(pch);
            std::cout << "health = " << health << std::endl;
            pch = strtok(nullptr, ";");
            int power = atoi(pch);
            std::cout << "power = " << power << std::endl;
            pch = strtok(nullptr, ";");
            bool isDigIn = atoi(pch);
            std::cout << "isDigIn = " << std::boolalpha << isDigIn << std::endl;

            Unit* u01 = loadUnit(unitType, unit, x, y, z, health, power, isDigIn, cellsMap);
            u01->printInfo();
            std::cout << "u01->getPowerBonus() = " << u01->getPowerBonus() << std::endl;
        //}
    }
    fileIn.close();

}
*/
Builder* makeUnitBuilder(std::string);
Tank* makeUnitTank(std::string);
