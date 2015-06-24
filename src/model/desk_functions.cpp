/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "desk_functions.hpp"

static bool neighboringGoodCell(const GameDesk& desk,
                                const Point& p) {
    Checker checker;
    for (int i = p.row - 1; i <= p.row + 1; i++) {
        if (i < 0) {
            continue;
        } else if (i >= desk.getRowNumber()) {
            break;
        }
        for (int j = p.col - 1; j <= p.col + 1; j++) {
            if (j < 0) {
                continue;
            } else if (j >= desk.getRowNumber()) {
                break;
            }
            Point pt;
            pt.col = j;
            pt.row = i;
            Points points;
            points.p1 = p;
            points.p2 = pt;
            if (checker.checkStep(desk, points)) {
                return true;
            }
        }
    }
    return false;
}

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

bool checkWin(const GameDesk& desk, int win_number) {
    bool win = win_number <= score(desk);
    return (win) ? true : false;
}
