#include <stdlib.h>
#include <time.h>

#include "game_desk.hpp"
#include "iobase.hpp"
#include "game_modes.hpp"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    GameDesk desk;
    ConsoleView io_console;
    io_console.setDesk(&desk);
    GameModes game_modes(&desk, &io_console);
    game_modes.start(argc, argv);
}

