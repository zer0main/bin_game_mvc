#include <cmath>

#include "checker.hpp"

bool Checker::checkStep(GameDesk& a, Points& points) {
    if (points.undo_action = true) {
        return true;
    }
    int rownumber = a.getRowNumber();
    int n1 = a.getDeskNumber(points.p1);
    int n2 = a.getDeskNumber(points.p2);
    return checkIndex(rownumber, points) && n1 == n2;
}

bool Checker::checkIndex(int max, Points& points) {
    int p1c = points.p1.col;
    int p2c = points.p2.col;
    int p1r = points.p1.row;
    int p2r = points.p2.row;
    if (checkRange(max, points)) {
        if ((p1c == p2c) && (std::abs((p1r - p2r)) == 1)) {
            return true;
        } else if ((p1r == p2r) && (std::abs(p1c - p2c) == 1)) {
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
    bool gt0 = p1r >= 0 && p1c >= 0 && p2r >= 0 && p2c >= 0;
    bool ltm = p1r < max && p1c < max && p2r < max && p2c < max;
    return gt0 && ltm;
}

