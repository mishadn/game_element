#ifndef CELLSMAP_H
#define CELLSMAP_H


#include "Cell.h"
#include "Air.h"
#include "Water.h"
#include "Earth.h"
#include "Fire.h"
#include "gameSets.h"


class CellsMap
{
    public:
        CellsMap(Air*, Earth*, Water*, Fire*);
        virtual ~CellsMap();
    //private:
        Cell* cell[5][5][3];
        //int getIndexX();
};

#endif // CELLSMAP_H
