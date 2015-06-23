/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <stdlib.h>

#include "game_desk.hpp"

GameDesk* GameDesk::make(int row_number) {
    if ((row_number < MIN_WIDTH) || (row_number >
                                     MAX_WIDTH)) {
        throw Exception("width (length) of desk is out of "
                        "allowable range");
    }
    GameDesk* desk = new GameDesk();
    int square = row_number * row_number;
    desk->row_number_ = row_number;
    desk->desk_.resize(square);
    return desk;
}

int GameDesk::getRowNumber() const {
    return row_number_;
}

int GameDesk::getDeskNumber(const Point& point) const {
    return desk_[point.col * row_number_ + point.row];
}

void GameDesk::setDeskNumber(const Point& point, int number) {
    desk_[point.col * row_number_ + point.row] = number;
}

GameDesk::GameDesk() {
}
