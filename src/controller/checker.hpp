/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef CHECKER_HPP_
#define CHECKER_HPP_

#include "game_desk.hpp"
#include "points.hpp"

class Checker {
public:
    bool checkStep(const GameDesk& desk,
                   const Points& points) const;

    bool checkIndex(const Points& points) const;
};

#endif

