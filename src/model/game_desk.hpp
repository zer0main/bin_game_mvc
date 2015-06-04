/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_DESK_HPP_
#define GAME_DESK_HPP_

#include <vector>

#include "points.hpp"

class GameDesk {
public:
    int getRowNumber() const;

    int getDeskNumber(const Point& point) const;

    void setDeskNumber(const Point& point, int number);

    void resize(int row_number);

private:
    Ints desk_;
    int row_number_;
};

#endif

