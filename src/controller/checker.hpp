#ifndef CHECKER_HPP_
#define CHECKER_HPP_

#include "game_desk.hpp"
#include "points.hpp"

class Checker {
public:
    bool checkStep(GameDesk& desk, Points& points);

    bool checkIndex(int max, Points& points);

    bool checkRange(int max, Points& points);
};

#endif
