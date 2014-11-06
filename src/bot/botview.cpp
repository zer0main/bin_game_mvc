#include <iostream>
#include <boost/bind.hpp>

#include "luabind-format-signature.hpp"
#include <lua.hpp>
#include <luabind/luabind.hpp>
#include <luabind/object.hpp>

#include "botview.hpp"
#include "game_desk.hpp"

using namespace luabind;

BotView::BotView() {
    L_ = luaL_newstate();
    luaL_openlibs(L_);
    int status = luaL_dofile(L_, "bin_game_bot.lua");
    if (status) {
        std::cerr << lua_tostring(L_, -1) << "\n";
    }
    luabind::open(L_);
    module(L_) [
        class_<const GameDesk>("GameDesk")
        .def("getDeskNumber", &GameDesk::getDeskNumber)
        ,
        class_<Point>("Point")
        .def(constructor<>())
        .def_readwrite("col", &Point::col)
        .def_readwrite("row", &Point::row)
        ,
        class_<Move>("Move")
        .def(constructor<>())
        .def_readwrite("p1", &Move::p1)
        .def_readwrite("p2", &Move::p2)
        .def_readwrite("undo_action", &Move::undo_action)
    ];
}

BotView::~BotView() {
    lua_close(L_);
}

int BotView::getDeskSize_impl() const {
    std::cout << "Choose the size of game desk: " << std::endl;
    int size = object_cast<int>(globals(L_)["getDeskSize"]());
    std::cout << size << std::endl;
    return size;
}

int BotView::getWinNumber_impl() const {
    std::cout << "What number you want to finish the game? " << std::endl;
    int winNumber = object_cast<int>(globals(L_)["getWinNumber"]());
    std::cout << winNumber << std::endl;
    return winNumber;
}

int BotView::getTimeNumber_impl() const {
    std::cout << "How many time you want to play (min)? " << std::endl;
    int timeNumber = object_cast<int>(globals(L_)["getTimeNumber"]());
    std::cout << timeNumber << std::endl;
    return timeNumber;
}

Move BotView::getIndex_impl() const {
    Move move;
    move.undo_action = false;
    std::cout << "Enter index of number1: " << std::endl;
    lua_getglobal(L_, "getIndex");
    lua_call(L_, 0, 4);
    move.p1.col = lua_tonumber(L_, -4);
    move.p1.row = lua_tonumber(L_, -3);
    move.p2.col = lua_tonumber(L_, -2);
    move.p2.row = lua_tonumber(L_, -1);
    lua_pop(L_, 4);
    std::cout << move.p1.col << ' ' << move.p1.row << std::endl;
    std::cout << "And of number2: " << std::endl;
    std::cout << move.p2.col << ' ' << move.p2.row << std::endl;
    return move;
}

void BotView::output_impl() const {
    outputGeneral();
    globals(L_)["output"](getDesk());
}
