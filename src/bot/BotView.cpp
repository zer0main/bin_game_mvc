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

#include "BotView.hpp"

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
    deskSizeMessage();
    return getBaseParameter(BOARDS_SIZE, "getDeskSize");
}

int BotView::getWinNumber_impl() const {
    winNumberMessage();
    return getBaseParameter(SCORE, "getWinNumber");
}

int BotView::getTimeNumber_impl() const {
    timeNumberMessage();
    return getBaseParameter(TIME, "getTimeNumber");
}

Points BotView::getIndex_impl() const {
    Points points;
    std::cout << "Please enter index of the first number."
              << std::endl;
    prompt();
    lua_getglobal(L_, "getIndex");
    lua_call(L_, 0, 4);
    points.p1.col = lua_tonumber(L_, -4);
    points.p1.row = lua_tonumber(L_, -3);
    points.p2.col = lua_tonumber(L_, -2);
    points.p2.row = lua_tonumber(L_, -1);
    lua_pop(L_, 4);
    std::cout << points.p1.col << ' ' << points.p1.row << std::endl;
    std::cout << "Please enter index of the second "
                 "number." << std::endl;
    prompt();
    std::cout << points.p2.col << ' ' << points.p2.row << std::endl;
    return points;
}

void BotView::output_impl() const {
    outputGeneral();
    globals(L_)["output"](getDesk());
}

int BotView::getBaseParameter(TypeOfChecking type,
                              const char* function_name) const {
    int parameter;
    while (true) {
        parameter = object_cast<int>(globals(L_)[function_name]());
        std::cout << parameter << std::endl;
        if (checkRange(parameter, type)) {
            break;
        } else {
            rangeError(type);
        }
    }
    return parameter;
}
