/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "Game.hpp"

GamePtr Game::make(GameDeskPtr desk,
                   GameControllerPtr controller) {
    if (!desk || !controller) {
        throw Exception("No desk or no controller");
    }
    GamePtr game(new Game());
    game->desk = desk;
    game->controller = controller;
    return game;
}

Game::Game() {
}
