#include <iostream>
#include <limits>
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
        class_<GameDesk>("GameDesk")
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

Points BotView::getIndex_impl() const {
    Points points;
    std::cout << "Enter index of number1: " << std::endl;
    lua_getglobal(L_, "getIndex");
    lua_call(L_, 0, 4);
    points.p1.col = lua_tonumber(L_, -4);
    points.p1.row = lua_tonumber(L_, -3);
    points.p2.col = lua_tonumber(L_, -2);
    points.p2.row = lua_tonumber(L_, -1);
    lua_pop(L_, 4);
    std::cout << points.p1.col << ' ' << points.p1.row << std::endl;
    std::cout << "And of number2: " << std::endl;
    std::cout << points.p2.col << ' ' << points.p2.row << std::endl;
    return points;
}

void BotView::typeError_impl() const {
}

void BotView::output_impl() const {
    const GameDesk* desk = getDesk();
    Point point;
    int i, x;
    for (i = desk->getRowNumber() - 1; i >= 0; i--) {
        for (x = 0; x < desk->getRowNumber(); x++) {
            point.col = i;
            point.row = x;
            char prev_fill = std::cout.fill(' ');
            int prev_width = std::cout.width(5);
            std::cout << desk->getDeskNumber(point);
            std::cout.width(prev_width);
            std::cout.fill(prev_fill);
        }
        std::cout << std::endl;
    }
    // TODO ^^ move to base class
    //
    globals(L_)["output"](getDesk());
}

void BotView::indexError_impl() const {
}

void BotView::finish_impl(bool check_fail, long long int score) const {
    if (check_fail) {
        std::cout << "You are loser... Your score is " << score << std::endl;
    } else {
        std::cout << "You are winner! You score is " << score << std::endl;
    }
}

void BotView::sendHelpMessage_impl() const {
    std::cout << "To play this game you must use the options: -w for play to win\n"
              "-t for game with real time and -s to play while not lose." << std::endl;
}

