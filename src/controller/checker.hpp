#ifndef CHECKER_HPP_
#define CHECKER_HPP_

#include "game_desk.hpp"
#include "points.hpp"

class Checker {
public:
    bool checkStep(GameDesk& desk, Move& move);

    bool checkIndex(int max, Move& move);

    bool checkRange(int max, Move& move);
};

#endif

