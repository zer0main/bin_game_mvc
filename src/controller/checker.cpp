#include "checker.hpp"

bool Checker::checkStep(GameDesk& a, Points& points) {
    int rownumber = a.getRowNumber();
    if (checkIndex(rownumber, points)) {
        if (a.getDeskNumber(points.p1) == a.getDeskNumber(points.p2)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

bool Checker::checkIndex(int max, Points& points) {
    if (checkRange(max, points)) {
        if ((points.p1.col == points.p2.col) && ((points.p1.row == points.p2.row + 1) || (points.p1.row == points.p2.row - 1))) {
            return 1;
        }
        else if ((points.p1.row == points.p2.row) && ((points.p1.col == points.p2.col + 1) || (points.p1.col == points.p2.col - 1))) {
            return 1;
        }
        return 0;
    }
    return 0;
}

bool Checker::checkRange(int max, Points& points) {
    if ((points.p1.row >= 0) && (points.p1.col >= 0) && (points.p2.row >= 0) && (points.p2.col >= 0)) {
        if ((points.p1.row < max) && (points.p1.col < max) && (points.p2.row < max) && (points.p2.col < max)) {
            return 1;
        }
        return 0;
    }
    return 0;
}
