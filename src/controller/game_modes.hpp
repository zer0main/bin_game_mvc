/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_MODES_HPP_
#define GAME_MODES_HPP_

#include "checker.hpp"
#include "points.hpp"
#include "game_desk.hpp"
#include "ioview.hpp"

class GameModes {
public:
    GameModes(GameDesk* desk, IoView* view);

    void setDesk(int desk_size);

    void replace(Points& points);

private:
    GameDesk* desk_;
    const IoView* ioview_;
};

#endif

