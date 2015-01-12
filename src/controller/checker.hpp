#ifndef CHECKER_HPP_
#define CHECKER_HPP_

#include "game_desk.hpp"
#include "points.hpp"

class Checker {
public:
    bool checkStep(const GameDesk& desk,
                   const Points& points) const;

    bool checkIndex(int max, const Points& points) const;

    bool checkRange(int max, const Points& points) const;
};

#endif

