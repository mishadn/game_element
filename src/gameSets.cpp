#include "gameSets.h"
#include <iostream>


std::string actions::getActionName(actions::Actions act)
{
    std::string res;
    switch (act)
    {
    case actions::Move :
        {
            res = "Move";
            break;
        }
    case actions::BuildBuilderFactory :
        {
            res = "BuildBuilderFactory";
            break;
        }
    case actions::BuildTankFactory :
        {
            res = "BuildTankFactory";
            break;
        }
    case actions::MakeUnit :
        {
            res = "MakeUnit";
            break;
        }
    case actions::Attack :
        {
            res = "Attack";
            break;
        }
    }
    return res;
}


std::string gameobj::getGameObjName(Gameobj gobj)
{
    std::string res = "";
    switch (gobj)
    {
    case gameobj::Unit :
        {
            res = "Unit";
            break;
        }
    case gameobj::Factory :
        {
            res = "Factroy";
            break;
        }
    default :
        {
            res = "No game object type.";
            break;
        }
    }
    return res;
}



std::string units::getUnitTypeName(UnitTypes uT)
{
    std::string res = "";

    switch (uT)
    {
    case units::Civil :
    {
        res = "Civil";
        break;
    }
    case units::Military :
    {
        res = "Military";
        break;
    }
    default :
    {
        res = "No civil Type of unit";
        break;
    }
    }

    return res;
}

std::string units::getUnitName(Units u)
{
    std::string res = "";

    switch(u)
    {
    case units::Builder :
    {
        res = "Builder";
        break;
    }
    case units::Medic :
    {
        res = "Medic";
        break;
    }
    case units::Cavalry :
    {
        res = "Cavalry";
        break;
    }
    case units::Navy :
    {
        res = "Navy";
        break;
    }
    case units::Tank :
    {
        res = "Tank";
        break;
    }
    case units::Scavenger :
    {
        res = "Scavenger";
        break;
    }
    case units::Aircraft :
    {
        res = "Aircraft";
        break;
    }
    case units::Infantry :
    {
        res = "Infantry";
        break;
    }
    default :
    {
        res = "No Unit Name";
        break;
    }
    }
    return res;
}


std::string factory::getFactoryTypeName(FactoryTypes factoryType)
{
    std::string res = "";

    switch (factoryType)
    {
    case factory::Civil :
    {
        res = "Civil";
        break;
    }
    case factory::Military :
    {
        res = "Military";
        break;
    }
    default :
    {
        res = "No Type of Factory";
        break;
    }
    }

    return res;
}

std::string factory::getFactoryName(Factorys factoryName)
{
    std::string res = "";

    switch(factoryName)
    {
    case factory::Builder :
    {
        res = "Builder";
        break;
    }
    case factory::Medic :
    {
        res = "Medic";
        break;
    }
    case factory::Cavalry :
    {
        res = "Cavalry";
        break;
    }
    case factory::Navy :
    {
        res = "Navy";
        break;
    }
    case factory::Tank :
    {
        res = "Tank";
        break;
    }
    case factory::Scavenger :
    {
        res = "Scavenger";
        break;
    }
    case factory::Aircraft :
    {
        res = "Aircraft";
        break;
    }
    case factory::Infantry :
    {
        res = "Infantry";
        break;
    }
    default :
    {
        res = "No Factory Name";
        break;
    }
    }
    return res;
}

std::string elements::getLandscapeName(Landscape l)
{
    std::string res = "";

    switch(l)
    {
    case elements::AirLand :
    {
        res = "AirLand";
        break;
    }
    case elements::EarthLand :
    {
        res = "EarthLand";
        break;
    }
    case elements::ForestLand :
    {
        res = "ForestLand";
        break;
    }
    case elements::MountLand :
    {
        res = "MountLand";
        break;
    }
    case elements::SandLand :
    {
        res = "SandLand";
        break;
    }
    case elements::WaterLand :
    {
        res = "WaterLand";
        break;
    }
    default :
    {
        res = "No Landscape Name";
        break;
    }
    }
    return res;
}

std::string elements::getElementTypeName(elements::Elements eT)
{
    std::string res = "";

    switch (eT)
    {
    case elements::Air :
    {
        res = "Air";
        break;
    }
    case elements::Earth :
    {
        res = "Earth";
        break;
    }
    case elements::Fire :
    {
        res = "Fire";
        break;
    }
    case elements::Water :
    {
        res = "Water";
        break;
    }
    default :
    {
        res = "No Type of Element";
        break;
    }
    }

    return res;
}

units::UnitTypes units::intToUnitTypes(int n)
{
    units::UnitTypes res;
    switch(n)
    {
    case 1 :
        {
            res = units::Civil;
            break;
        }
    case 2 :
        {
            res = units::Military;
            break;
        }
    default :
        {
            res = units::Unit;
            break;
        }
    }
    return res;
}

units::Units units::intToUnits(int n)
{
    units::Units res;

    switch(n)
    {
    case 2 :
    {
        res = units::Builder;
        break;
    }
    case 6 :
    {
        res = units::Medic;
        break;
    }
    case 0 :
    {
        res = units::Cavalry;
        break;
    }
    case 1 :
    {
        res = units::Navy;
        break;
    }
    case 3 :
    {
        res = units::Tank;
        break;
    }
    case 4 :
    {
        res = units::Scavenger;
        break;
    }
    case 5 :
    {
        res = units::Aircraft;
        break;
    }
    case 7 :
    {
        res = units::Infantry;
        break;
    }
    default :
    {
        res = units::Badunit;
        break;
    }
    }
    return res;

}

factory::Factorys factory::intToFactory(int f)
{
    factory::Factorys res;

    switch(f)
    {
    case 0 :
        {
            res = factory::Cavalry;
            break;
        }
    case 1 :
        {
            res = factory::Navy;
            break;
        }
    case 2 :
        {
            res = factory::Builder;
            break;
        }
    case 3 :
        {
            res = factory::Tank;
            break;
        }
    case 4 :
        {
            res = factory::Scavenger;
            break;
        }
    case 5 :
        {
            res = factory::Aircraft;
            break;
        }
    case 6 :
        {
            res = factory::Medic;
            break;
        }
    case 7 :
        {
            res = factory::Infantry;
            break;
        }
    default :
        {
            res = factory::BadFactoryName;
        }
    }
    return res;
}

factory::FactoryTypes factory::intToFactoryTypes(int n)
{
    factory::FactoryTypes res;
    switch(n)
    {
    case 0 :
        {
            res = factory::Civil;
            break;
        }
    case 1 :
        {
            res = factory::Military;
            break;
        }
    }
    return res;
}

bool common::askYesNo()
{
    bool res = true;
    char yn = 'Y';
    std::cout << "(Y/N)";
    std::cin >> yn;
    if (yn == 'N' || yn == 'n')
    {
            res = false;
    }
    return res;
}
