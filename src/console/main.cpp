#include <stdlib.h>
#include <time.h>

#include "game_desk.hpp"
#include "iobase.hpp"
#include "game_modes.hpp"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    GameDesk desk;
    GameDesk *desk_point = &desk;
    IoBase io_base;
    IoBase *io_base_point = &io_base;
    io_base.setDesk(desk_point);
    GameModes game_modes(desk_point, io_base_point);
    game_modes.start(argc, argv);
}
