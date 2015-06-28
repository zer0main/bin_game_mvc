/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "GuiGame.hpp"

GuiGamePtr GuiGame::make(QObject* window, int row_number) {
    GuiGamePtr gui_game(new GuiGame());
    gui_game->desk =
        GameDeskPtr(GameDesk::make(row_number));
    gui_game->controller =
        GameControllerPtr
        (GameController::make(gui_game->desk.data()));
    gui_game->t_model =
        TableModelPtr
        (new TableModel(window, gui_game->desk.data()));
    return gui_game;
}

GuiGame::GuiGame() {
}
