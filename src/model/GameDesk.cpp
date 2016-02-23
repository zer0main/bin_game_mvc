/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <stdlib.h>

#include "GameDesk.hpp"

/* get global coordinate from horizontal and
   vertical coordinates
*/
static int getIndex(const Point& point, int row_number) {
    bool less = ((point.col < 0) || (point.row < 0));
    bool greater = ((point.col >= row_number) ||
                    (point.row >= row_number));
    if (less || greater) {
        throw Exception("This index is out of allowable "
                        "range.");
    }
    int index = point.col * row_number + point.row;
    return index;
}

GameDesk* GameDesk::make(int row_number) {
    if ((row_number < Rules::MIN_WIDTH) ||
        (row_number > Rules::MAX_WIDTH)) {
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
    int index = getIndex(point, row_number_);
    return desk_[index];
}

void GameDesk::setDeskNumber(const Point& point,
                             int number) {
    int index = getIndex(point, row_number_);
    desk_[index] = number;
}

GameDesk::GameDesk() {
}
