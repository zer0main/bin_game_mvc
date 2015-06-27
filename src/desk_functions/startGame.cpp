/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "startGame.hpp"

QSharedPointer<Game> startGame(QObject* window,
                               int row_number) {
    QSharedPointer<Game> game =
        QSharedPointer<Game>(new Game());
    game->desk = QSharedPointer<GameDesk>
                 (GameDesk::make(row_number));
    game->t_model = QSharedPointer<TableModel>
                    (new TableModel(window,
                                    game->desk.data()));
    game->controller =
        QSharedPointer<GameController>
        (GameController::make(game->desk.data()));
    return game;
}
