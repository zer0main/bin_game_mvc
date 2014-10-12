#ifndef GAME_MODES_HPP_
#define GAME_MODES_HPP_

#include "checker.hpp"
#include "points.hpp"
#include "game_desk.hpp"
#include "ioview.hpp"

class GameModes {
public:
    GameModes(GameDesk* desk, IoView* view);

    void start(int argc, char* argv[]);
private:
    GameDesk* desk_;
    const IoView* ioview_;

    long long int score();

    bool checkFail();

    bool checkWin(int for_win);

    void setDesk(int desk_size);

    void play();

    void replace(Points& points);

    void gameForWin();

    void gameForScore();

    void gameWithTime();

    void help();
};

#endif

