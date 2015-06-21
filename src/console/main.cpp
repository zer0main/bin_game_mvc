/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <stdlib.h>
#include <time.h>

#include "game_desk.hpp"
#include "consoleview.hpp"
#include "game_modes.hpp"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    GameDesk desk;
    ConsoleView io_console;
    io_console.setDesk(&desk);
    GameModes* controller = GameModes::make(&desk);
}
