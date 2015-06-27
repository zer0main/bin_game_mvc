/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "global.hpp"
#include "game_desk.hpp"
#include "game_controller.hpp"

/** Contains all classes necessary for game */
struct Game {
    /** Create new instance.
    \param desk Model
    \param controller Controller
    */
    static GamePtr make(GameDeskPtr desk,
                        GameControllerPtr controller);

    GameDeskPtr desk;
    GameControllerPtr controller;

private:
    Game();
};

#endif
