#include <iostream>
#include "Element.h"
#include "Air.h"
#include "Water.h"
#include "Earth.h"
#include "Fire.h"
#include "gameSets.h"
#include "Unit.h"
#include "Civil.h"
#include "Builder.h"
#include "Military.h"
#include "Cell.h"
#include "Tank.h"
#include "BuilderFactory.h"
#include "TankFactory.h"
#include "BuilderBF.h"
#include "CellsMap.h"
#include <string>
#include "Gamer.h"
#include "fstream"
#include "Game.h"

//void loadGame(std::string, CellsMap*);

//Game* loadGame(std::string, CellsMap*);
int main()
{
    Air* air = new Air();
    Water* water = new Water();
    Earth* earth = new Earth();
    Fire* fire = new Fire();

    CellsMap* cellsMap = new CellsMap(air, earth, water, fire);

    Game* game = new Game("first game", cellsMap);


    std::cout << "New game(Y)? or load game(N)? ";
    if(common::askYesNo())
    {
        game->createGamer("David", cellsMap->cell[0][0][1]);
        game->createGamer("Tomm", cellsMap->cell[4][4][1]);
        game->printGamers();
        game->startGame();
    }
    else
    {
        std::string fName = "saveObjects001.ttt";
        game->loadGame(fName);
        std::cout << " ------------- print loaded gamers -----------------------------" << std::endl;
        game->printGamers();
        game->startGame();

    }




    /*
        gamer_01->printInfo();

        CellsMap* cellsMap = new CellsMap(air, earth, water, fire);

        Builder* builder01 = new Builder(cellsMap->cell[0][2][1]);
        builder01->setCell(cellsMap->cell[0][3][1]);
        BuilderFactory* builderFactory01 = builder01->createBuilderFactory();


        Builder* builder02 = builderFactory01->getUnit();
        builder02->setCell(cellsMap->cell[3][2][1]);
        TankFactory* tankFactory01 = builder02->createTankFactory();
        Tank* tank01 = tankFactory01->getUnit();
        std::cout << std::endl << "-- builderFactory01 --" << std::endl;
        builderFactory01->printInfo();
        std::cout << "-- builderFactory01 --" << std::endl << std::endl;
        std::cout << std::endl << "-- tankFactory01 --" << std::endl;
        tankFactory01->printInfo();
        std::cout << "-- tankFactory01 --" << std::endl << std::endl;
        std::cout << std::endl << "-- tank01 --" << std::endl;
        tank01->printInfo();
        std::cout << tank01->toString() << std::endl;
        std::cout << "-- tank01 --" << std::endl << std::endl;

        //saveUnit(tank01);
        saveUnit(builder01);
        std::string fName = "save001.ttt";
        loadGame(fName, cellsMap);
        //saveObjects(tank01);

        std::cout << std::endl << " ---------------------------------------------------- " << std::endl << std::endl;
        gamer_01->createUnit(builderFactory01);
        gamer_01->createUnit(builderFactory01);
        gamer_01->createUnit(builderFactory01);
        gamer_01->createUnit(tankFactory01);
        gamer_01->createUnit(tankFactory01);

        std::cout << std::endl << " ---------------------------------------------------- " << std::endl;
        //gamer_01->units.
        std::cout << std::endl << " -------------------Units--------------------------------- " << std::endl << std::endl;
        gamer_01->printUnits();
        //gamer_01->pitUnits();
        std::cout << std::endl << " ---------------------------------------------------- " << std::endl;
        std::cout << std::endl << " -------------- Unit 3 -------------------------------------- " << std::endl << std::endl;
        gamer_01->takeUnit(3);
        gamer_01->currUnit->printInfo();
        std::cout << std::endl << " -------------- Unit 3 actions -------------------------------------- " << std::endl;
        gamer_01->takeUnitAction();

        std::cout << std::endl << " -------------- Unit 0 -------------------------------------- " << std::endl << std::endl;
        gamer_01->takeUnit(0);
        gamer_01->currUnit->printInfo();
        std::cout << std::endl << " -------------- Unit 0 actions -------------------------------------- " << std::endl;
        gamer_01->takeUnitAction();
        std::cout << std::endl << " ---------------------------------------------------- " << std::endl;
        std::cout << std::endl << " ------------------ FACTORES ---------------------------------- " << std::endl;
        gamer_01->createFactory();
        gamer_01->createFactory();
        gamer_01->createFactory();
        gamer_01->createFactory();
        gamer_01->createFactory();
        std::cout << std::endl << " ---------------------------------------------------- " << std::endl;
        gamer_01->printFactoriesLine();

        gamer_01->takeFactory(1);

        gamer_01->printUnitsLine();

        saveGamer(gamer_01);


        std::cout << std::endl << " ---------------------------------------------------- " << std::endl;


        delete air;
        delete earth;
        delete water;
        delete fire;
        delete builder01;
        delete builder02;
        delete builderFactory01;
        delete tankFactory01;
        delete tank01;
        delete gamer_01;
        */
    delete game;

    return 0;
}
