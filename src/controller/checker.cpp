#include <cmath>

#include "checker.hpp"

bool Checker::checkStep(GameDesk& a, Points& points) {
    int rownumber = a.getRowNumber();
    if (checkIndex(rownumber, points)) {
        if (a.getDeskNumber(points.p1) == a.getDeskNumber(points.p2)) {
            return true;
        }
        return false;
    }
    return false;
}

bool Checker::checkIndex(int max, Points& points) {
    int p1c = points.p1.col;
    int p2c = points.p2.col;
    int p1r = points.p1.row;
    int p2r = points.p2.row;
    if (checkRange(max, points)) {
        if ((p1c == p2c) && (std::abs((p1r - p2r)) == 1)) {
            return true;
        }
        else if ((p1r == p2r) && std::abs((p1c - p2c) == 1)) {
            return true;
        }
        return false;
    }
    return false;
}

bool Checker::checkRange(int max, Points& points) {
    int p1c = points.p1.col;
    int p2c = points.p2.col;
    int p1r = points.p1.row;
    int p2r = points.p2.row;
    if ((p1r >= 0) && (p1c >= 0) && (p2r >= 0) && (p2c >= 0)) {
        if ((p1r < max) && (p1c < max) && (p2r < max) && (p2c < max)) {
            return true;
        }
        return false;
    }
    return false;
}
