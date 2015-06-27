/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include <QtCore>

class GameDesk;
class TableModel;
class GameController;
struct Game;

typedef QSharedPointer<GameDesk> GameDeskPtr;
typedef QSharedPointer<TableModel> TableModelPtr;
typedef QSharedPointer<GameController> GameControllerPtr;
typedef QSharedPointer<Game> GamePtr;

#endif
