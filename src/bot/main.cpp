#include <stdlib.h>
#include <time.h>

#include "game_desk.hpp"
#include "botview.hpp"
#include "game_modes.hpp"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    GameDesk desk;
    BotView bot;
    bot.setDesk(&desk);
    GameModes game_modes(&desk, &bot);
    game_modes.start(argc, argv);
}

