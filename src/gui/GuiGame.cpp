/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "GuiGame.hpp"

GuiGamePtr GuiGame::make(GameDeskPtr desk,
                         GameControllerPtr controller,
                         TableModelPtr t_model) {
    if (!desk || !controller || !t_model) {
        throw Exception("No desk or no controller or no "
                        "table model");
    }
    GuiGamePtr gui_game(new GuiGame());
    gui_game->desk = desk;
    gui_game->controller = controller;
    gui_game->t_model = t_model;
    return gui_game;
}

GuiGame::GuiGame() {
}
