/*
** EPITECH PROJECT, 2022
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Parsing.cpp
*/

#include "Parsing.hpp"

Parsing::Parsing()
{
}

Parsing::~Parsing()
{
}

void Parsing::parse(std::string str)
{
    std::string delimiter = " ";
    int pos = str.find(delimiter);
    std::string cmd = str.substr(0, pos);
    std::string arg = str.substr(4, str.length() - 1);
    if (cmd == "msz")
        msz(arg);
    if (cmd == "bct")
        bct(arg);
    if (cmd == "tna")
        tna(arg);
    if (cmd == "pnw")
        pnw(arg);
    if (cmd == "ppo")
        ppo(arg);
    if (cmd == "plv")
        plv(arg);
    if (cmd == "pin")
        pin(arg);
    if (cmd == "pex")
        pex(arg);
    if (cmd == "pbc")
        pbc(arg);
    if (cmd == "pic")
        pic(arg);
    if (cmd == "pie")
        pie(arg);
    if (cmd == "pfk")
        pfk(arg);
    if (cmd == "pdr")
        pdr(arg);
    if (cmd == "pgt")
        pgt(arg);
    if (cmd == "pdi")
        pdi(arg);
    if (cmd == "enw")
        enw(arg);
    if (cmd == "eht")
        eht(arg);
    if (cmd == "ebo")
        ebo(arg);
    if (cmd == "edi")
        edi(arg);
    if (cmd == "sgt")
        sgt(arg);
    if (cmd == "seg")
        seg(arg);
    if (cmd == "smg")
        smg(arg);
    if (cmd == "suc")
        suc(arg);
    if (cmd == "sbp")
        sbp(arg);
}

void Parsing::msz(std::string arg)
{
    std::string delimiter = " ";
    int pos = arg.find(delimiter);
    mapt.setX(std::stoi(arg.substr(0, pos)));
    mapt.setY(std::stoi(arg.substr(pos + 1, arg.length())));
}

void Parsing::bct(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    Stock stock(std::stoi(parts[2]), std::stoi(parts[3]), std::stoi(parts[4]), std::stoi(parts[5]), std::stoi(parts[6]), std::stoi(parts[7]), std::stoi(parts[8]));
    Tile tile(stock);
    std::tuple<double, double> tuple = std::make_tuple(std::stoi(parts[0]), std::stoi(parts[1]));
    mapt.setTile(tuple, tile);
}

void Parsing::tna(std::string arg)
{
    std::cout << "Teams names: " << arg << std::endl;
}

void Parsing::pnw(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    Stock stock(0, 0, 0, 0, 0, 0, 0);
    Trantorian trantorian(stock, std::stoi(parts[0]), parts[3][0], 1, false, std::stoi(parts[1]), std::stoi(parts[2]), parts[4]);
    mapt.addTrantorian(trantorian);
}

void Parsing::ppo(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    mapt.setTrantorianPos(std::stoi(parts[0]), std::stoi(parts[1]), std::stoi(parts[2]), parts[3][0]);
}

void Parsing::plv(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    mapt.setTrantorianLvl(std::stoi(parts[0]), std::stoi(parts[1]));
}

void Parsing::pin(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    Stock stock(std::stoi(parts[3]), std::stoi(parts[4]), std::stoi(parts[5]), std::stoi(parts[6]), std::stoi(parts[7]), std::stoi(parts[8]), std::stoi(parts[10]));
    mapt.setTrantorianStock(std::stoi(parts[0]), std::stoi(parts[1]), std::stoi(parts[2]), stock);
}

void Parsing::pex(std::string arg)
{
    mapt.removeTrantorian(std::stoi(arg));
}

void Parsing::pbc(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    mapt.setTrantorianMessage(std::stoi(parts[0]), parts[1]);
}

void Parsing::pic(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    std::tuple<double, double> tuple;
    while (ss >> part) {
        parts.push_back(part);
    }
    Tile tile = mapt.getTile(std::stoi(parts[0]), std::stoi(parts[1]));
    tile.setLvlEvo(std::stoi(parts[2]));
    std::vector<int> trantorian;
    for (int i = 3; i < parts.size(); i++) {
        trantorian.push_back(std::stoi(parts[i]));
    }
    tile.setPlayers(trantorian);
    tuple = std::make_tuple(std::stoi(parts[0]), std::stoi(parts[1]));
    mapt.setTile(tuple, tile);
    std::cout << "incantation from";
    for (int i = 3; i < parts.size(); i++) {
        std::cout << " " << parts[i];
    }
    std::cout << "for lvl" << parts[2] << std::endl;
}

void Parsing::pie(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    std::tuple<double, double> tuple;
    while (ss >> part) {
        parts.push_back(part);
    }
    Tile tile = mapt.getTile(std::stoi(parts[0]), std::stoi(parts[1]));
    if (parts[2] == "1") {
        for (int i = 0; i < tile.getPlayers().size(); i++) {
            mapt.setTrantorianLvl(tile.getPlayers()[i], tile.getLvlEvo());
        }
    }
    tile.setLvlEvo(0);
    tile.setPlayers({});
    std::cout << std::endl;
}

void Parsing::pfk(std::string arg)
{
    std::cout << "inutile" << std::endl;
}

