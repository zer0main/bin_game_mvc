#include <stdlib.h>
#include <time.h>

#include "game_desk.hpp"
#include "iobase.hpp"
#include "game_modes.hpp"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    GameDesk desk;
    IoBase io_base;
    io_base.setDesk(&desk);
    GameModes game_modes(&desk, &io_base);
    game_modes.start(argc, argv);
}

