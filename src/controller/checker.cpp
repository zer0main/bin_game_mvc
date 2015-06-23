/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "checker.hpp"

static int myAbs(int number) {
    if (number >= 0) {
        return number;
    } else {
        return -number;
    }
}

bool Checker::checkStep(const GameDesk& a,
                        const Points& points) const {
    if (checkIndex(points)) {
        int n1 = a.getDeskNumber(points.p1);
        int n2 = a.getDeskNumber(points.p2);
        if (n1 == n2) {
            return true;
        }
    }
    return false;
}

bool Checker::checkIndex(const Points& points) const {
    int p1c = points.p1.col;
    int p2c = points.p2.col;
    int p1r = points.p1.row;
    int p2r = points.p2.row;
    if ((p1c == p2c) && (myAbs((p1r - p2r)) == 1)) {
        return true;
    } else if ((p1r == p2r) && (myAbs(p1c - p2c) == 1)) {
        return true;
    }
    return false;
}
