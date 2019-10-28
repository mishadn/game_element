#include "CellsMap.h"
#include "Cell.h"
#include "Air.h"
#include "Water.h"
#include "Earth.h"
#include "Fire.h"
#include "gameSets.h"

CellsMap::CellsMap(Air* air, Earth* earth, Water* water, Fire* fire)
{
/*    map = {
    {new Cell(water, elements::WaterLand, 0, 0, 0)    }
    }*/
    cell[0][0][1] = new Cell(water, elements::WaterLand, 0, 0, 1, 0);
    cell[0][1][1] = new Cell(water, elements::WaterLand, 0, 1, 1, 0);
    cell[0][2][1] = new Cell(earth, elements::EarthLand, 0, 2, 1, 0);
    cell[0][3][1] = new Cell(earth, elements::EarthLand, 0, 3, 1, 0);
    cell[0][4][1] = new Cell(earth, elements::EarthLand, 0, 4, 1, 0);

    cell[1][0][1] = new Cell(water, elements::WaterLand, 1, 0, 1, 0);
    cell[1][1][1] = new Cell(water, elements::WaterLand, 1, 1, 1, 0);
    cell[1][2][1] = new Cell(earth, elements::MountLand, 1, 2, 1, 2);
    cell[1][3][1] = new Cell(earth, elements::MountLand, 1, 3, 1, 5);
    cell[1][4][1] = new Cell(earth, elements::MountLand, 1, 4, 1, 2);

    cell[2][0][1] = new Cell(water, elements::WaterLand, 2, 0, 1, 0);
    cell[2][1][1] = new Cell(earth, elements::SandLand, 2, 1, 1, 0);
    cell[2][2][1] = new Cell(earth, elements::ForestLand, 2, 2, 1, 1);
    cell[2][3][1] = new Cell(water, elements::WaterLand, 2, 3, 1, 0);
    cell[2][4][1] = new Cell(earth, elements::MountLand, 2, 4, 1, 1);

    cell[3][0][1] = new Cell(water, elements::WaterLand, 3, 0, 1, 0);
    cell[3][1][1] = new Cell(earth, elements::SandLand, 3, 1, 1, 0);
    cell[3][2][1] = new Cell(earth, elements::ForestLand, 3, 2, 1, 0);
    cell[3][3][1] = new Cell(water, elements::WaterLand, 3, 3, 1, 0);
    cell[3][4][1] = new Cell(earth, elements::ForestLand, 3, 4, 1, 0);

    cell[4][0][1] = new Cell(water, elements::WaterLand, 4, 0, 1, 0);
    cell[4][1][1] = new Cell(water, elements::WaterLand, 4, 1, 1, 0);
    cell[4][2][1] = new Cell(water, elements::WaterLand, 4, 2, 1, 0);
    cell[4][3][1] = new Cell(water, elements::WaterLand, 4, 3, 1, 0);
    cell[4][4][1] = new Cell(earth, elements::ForestLand, 4, 4, 1, 0);
}

CellsMap::~CellsMap()
{
    //dtor
}
