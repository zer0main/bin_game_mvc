/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GUI_GAME_HPP_
#define GUI_GAME_HPP_

#include "TableModel.hpp"
#include "Game.hpp"

/** Contains all classes necessary for game */
struct GuiGame : public Game {
    /** Create new instance.
    \param desk Model
    \param controller Controller
    \param t_model Table model
    */
    static GuiGamePtr make(GameDeskPtr desk,
                           GameControllerPtr controller,
                           TableModelPtr t_model);

    TableModelPtr t_model;

private:
    GuiGame();
};

#endif
