/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_DESK_HPP_
#define GAME_DESK_HPP_

#include <vector>

#include "constants.hpp"
#include "Points.hpp"
#include "Exception.hpp"

class GameDesk {
public:
    /** Create new instance.
    \param row_number Width/Length of game board
    */
    static GameDesk* make(int row_number);

    int getRowNumber() const;

    int getDeskNumber(const Point& point) const;

    void setDeskNumber(const Point& point, int number);

private:
    Ints desk_;
    int row_number_;

    GameDesk();
};

#endif

