/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_MODES_HPP_
#define GAME_MODES_HPP_

#include "Exception.hpp"
#include "checker.hpp"
#include "points.hpp"
#include "game_desk.hpp"
#include "ioview.hpp"

class GameModes {
public:
    /** Create new instance.
    \param desk Model that will be changeable by GameModes
    */
    static GameModes* make(GameDesk* desk);

    void setDesk(int desk_size);

    void replace(Points& points);

private:
    GameDesk* desk_;

    /* Set new random number (1 or 2) in cell with
    coordinates specified in point argument
    */
    void newRandomNumber(const Point& point);

    GameModes();
};

#endif

