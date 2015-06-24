/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "desk_functions.hpp"

int score(const GameDesk& desk) {
    Point point;
    int score = 0;
    for (int i = 0; i < desk.getRowNumber(); i++) {
        for (int x = 0; x < desk.getRowNumber(); x++) {
            point.col = i;
            point.row = x;
            score += desk.getDeskNumber(point);
        }
    }
    return score;
}
