/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "global.hpp"
#include "GameDesk.hpp"
#include "GameController.hpp"

/** Contains all classes necessary for game */
struct Game {
    /** Create new instance.
    \param row_number Width/length of game board
    */
    static GamePtr make(int row_number);

    GameDeskPtr desk;
    GameControllerPtr controller;

protected:
    Game();
};

#endif
