/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Trantorians
*/

#include "Trantorians.hpp"

Trantorian::Trantorian(Stock stock, int id, int orientation, int lvl, bool canEvolve, int x, int y, std::string team)
{
    this->x = x;
    this->y = y;
    this->orientation = orientation;
    this->lvl = lvl;
    this->team = team;
    this->stock = stock;
    this->id = id;
    this->canEvolve = canEvolve;
    this->team = team;
    this->message = "";
}

Trantorian::Trantorian()
{
}

Trantorian::~Trantorian()
{
}

void Trantorian::setX(int x)
{
    this->x = x;
}

void Trantorian::setY(int y)
{
    this->y = y;
}

void Trantorian::setOrientation(int orientation)
{
    this->orientation = orientation;
}

void Trantorian::setLvl(int lvl)
{
    this->lvl = lvl;
}

void Trantorian::setTeam(std::string team)
{
    this->team = team;
}

int Trantorian::getX()
{
    return (this->x);
}

int Trantorian::getY()
{
    return (this->y);
}

int Trantorian::getOrientation()
{
    return (this->orientation);
}

int Trantorian::getLvl()
{
    return (this->lvl);
}

std::string Trantorian::getTeam()
{
    return (this->team);
}

void Trantorian::setStock(Stock stock)
{
    this->stock = stock;
}

Stock Trantorian::getStock()
{
    return (this->stock);
}

void Trantorian::setId(int id)
{
    this->id = id;
}

int Trantorian::getId()
{
    return (this->id);
}
void Trantorian::setCanEvolve(bool canEvolve)
{
    this->canEvolve = canEvolve;
}

bool Trantorian::getCanEvolve()
{
    return (this->canEvolve);
}

void Trantorian::setMessage(std::string message)
{
    this->message = message;
}

std::string Trantorian::getMessage()
{
    return (this->message);
}

int Trantorian::getLevel()
{
    return (this->lvl);
}
