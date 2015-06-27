/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef START_GAME_HPP_
#define START_GAME_HPP_

#include "Game.hpp"

/** Create all objects necessary for every type of game.
\param window MainWindow
\param row_number Width/length of game board
*/
QSharedPointer<Game> startGame(QObject* window,
                               int row_number);

#endif
