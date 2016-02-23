/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "Game.hpp"

GamePtr Game::make(int row_number) {
    GamePtr game(new Game());
    game->desk = GameDeskPtr(GameDesk::make(row_number));
    game->controller =
        GameControllerPtr
        (GameController::make(game->desk.data()));
    return game;
}

Game::Game() {
}
