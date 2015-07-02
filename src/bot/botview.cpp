/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

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
        class_<Points>("Points")
        .def(constructor<>())
        .def_readwrite("p1", &Points::p1)
        .def_readwrite("p2", &Points::p2)
    ];
}

BotView::~BotView() {
    lua_close(L_);
}

int BotView::getDeskSize_impl() const {
    std::cout << "Enter the size of game desk "
                 "(desk's size >= 3 and <= 16!)" << std::endl;
    prompt();
    int size = object_cast<int>(globals(L_)["getDeskSize"]());
    std::cout << size << std::endl;
    return size;
}

int BotView::getWinNumber_impl() const {
    std::cout << "What score you want to finish the "
                 "game?" << std::endl;
    std::cout << "Minimum is 10 and maximum is 9999999" << std::endl;
    prompt();
    int winNumber = object_cast<int>(globals(L_)["getWinNumber"]());
    std::cout << winNumber << std::endl;
    return winNumber;
}

int BotView::getTimeNumber_impl() const {
    std::cout << "How many minutes you want to play?" << std::endl;
    std::cout << "Minimum is 1 and maximum is 1000" << std::endl;
    prompt();
    int timeNumber = object_cast<int>(globals(L_)["getTimeNumber"]());
    std::cout << timeNumber << std::endl;
    return timeNumber;
}

Points BotView::getIndex_impl() const {
    Points points;
    std::cout << "Enter index of number1" << std::endl;
    prompt();
    lua_getglobal(L_, "getIndex");
    lua_call(L_, 0, 4);
    points.p1.col = lua_tonumber(L_, -4);
    points.p1.row = lua_tonumber(L_, -3);
    points.p2.col = lua_tonumber(L_, -2);
    points.p2.row = lua_tonumber(L_, -1);
    lua_pop(L_, 4);
    std::cout << points.p1.col << ' ' << points.p1.row << std::endl;
    std::cout << "And of number2" << std::endl;
    prompt();
    std::cout << points.p2.col << ' ' << points.p2.row << std::endl;
    return points;
}

void BotView::output_impl() const {
    outputGeneral();
    globals(L_)["output"](getDesk());
}
