/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "game_desk.hpp"
#include "game_controller.hpp"
#include "TableModel.hpp"
#include "ioview.hpp"

/** Contains all classes necessary for game */
struct Game {
    IoView* view;
    GameDesk* desk;
    TableModel* t_model;
    GameController* controller;
};

#endif
