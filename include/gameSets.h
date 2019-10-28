#ifndef GAMESETS_H_INCLUDED
#define GAMESETS_H_INCLUDED

#include <map>
#include <string>


namespace common
{
    bool askYesNo();
}

namespace actions
{
    enum Actions {Move=0, BuildTankFactory, BuildBuilderFactory, Attack, MakeUnit};
    std::string getActionName(Actions);
}

namespace gameobj
{
    enum Gameobj {Unit=0, Factory};
    std::string getGameObjName(Gameobj);
}

namespace elements
{
enum Elements {Element, Air, Water, Earth, Fire};
enum Landscape {AirLand, WaterLand, EarthLand, SandLand, ForestLand, MountLand};


std::string getLandscapeName(Landscape);
std::string getElementTypeName(Elements);
}

namespace units
{
enum UnitTypes {Unit, Civil, Military};
enum Units {Cavalry, Navy, Builder, Tank, Scavenger, Aircraft, Medic, Infantry, Badunit};

std::string getUnitTypeName(UnitTypes);
std::string getUnitName(Units);
UnitTypes intToUnitTypes(int);
Units intToUnits(int);


//BASE
const int BASE_HEALTH = 100;
const int BASE_POWER = 1;


// CAVARLY
const std::string CAVALRY = "cavalry";
const std::string CAVALRY_SOUND = "Tyg-Dyck";
const int CAVALRY_HEALTH = 100;
const int CAVALRY_POWER = 2;

//INFANTRY
const std::string INFANTRY = "infantry";
const std::string INFANTRY_SOUND = "Huraaa";
const int INFANTRY_HEALTH = 100;
const int INFANTRY_POWER = 1;

//MEDIC
const std::string MEDIC = "medic";
const std::string MEDIC_SOUND = "Ts-ts";
const int MEDIC_HEALTH = 100;
const int MEDIC_POWER = 1;

//SCAVENGER
const std::string SCAVENGER = "scavenger";
const std::string SCAVENGER_SOUND = "Hehhh...";
const int SCAVENGER_HEALTH = 100;
const int SCAVENGER_POWER = 100;

//TANK
const std::string TANK = "tank";
const std::string TANK_SOUND = "Tyr-tyr";
const int TANK_HEALTH = 100;
const int TANK_POWER = 3;

//BUILDER
const std::string BUILDER = "builder";
const std::string BUILDER_SOUND = "Eh-ohhh...";
const int BUILDER_HEALTH = 1;
const int BUILDER_POWER = 1;

}

namespace factory
{
enum FactoryTypes {Civil, Military};
enum Factorys {Cavalry, Navy, Builder, Tank, Scavenger, Aircraft, Medic, Infantry, BadFactoryName};



std::string getFactoryTypeName(FactoryTypes factoryType);
std::string getFactoryName(Factorys);
//Factorys intToFactoryName(int);
Factorys intToFactory(int);
FactoryTypes intToFactoryTypes(int);
//Factorys intFactorys(int);

//BASE
const int BASE_HEALTH = 100;
const int BASE_POWER = 1;


// CAVARLY
const std::string CAVALRY = "cavalry";
const std::string CAVALRY_SOUND = "Ph-Ph-Tyg-Dyck";
const int CAVALRY_HEALTH = 100;
const int CAVALRY_POWER = 1;

//INFANTRY
const std::string INFANTRY = "infantry";
const std::string INFANTRY_SOUND = "Ph-Ph-Huraaa";
const int INFANTRY_HEALTH = 100;
const int INFANTRY_POWER = 1;

//MEDIC
const std::string MEDIC = "medic";
const std::string MEDIC_SOUND = "Ph-Ph-Ts-ts";
const int MEDIC_HEALTH = 100;
const int MEDIC_POWER = 1;

//SCAVENGER
const std::string SCAVENGER = "scavenger";
const std::string SCAVENGER_SOUND = "Ph-Ph-Hehhh...";
const int SCAVENGER_HEALTH = 100;
const int SCAVENGER_POWER = 1;

//TANK
const std::string TANK = "tank";
const std::string TANK_SOUND = "Ph-Ph-Tyr-tyr";
const int TANK_HEALTH = 100;
const int TANK_POWER = 1;

//BUILDER
const std::string BUILDER = "builder";
const std::string BUILDER_SOUND = "Ph-Ph-Eh-ohhh...";
const int BUILDER_HEALTH = 100;
const int BUILDER_POWER = 1;

}


#endif // GAMESETS_H_INCLUDED
