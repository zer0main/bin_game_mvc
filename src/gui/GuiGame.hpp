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
    \param window MainWindow
    \param row_number Width/length of game board
    */
    static GuiGamePtr make(QObject* window,
                           int row_number);

    TableModelPtr t_model;

private:
    GuiGame();
};

#endif
