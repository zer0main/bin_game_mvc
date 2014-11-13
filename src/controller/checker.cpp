#include <cmath>

#include "checker.hpp"

bool Checker::checkStep(GameDesk& a, Move& move) {
    if (move.undo_action == true) {
        return true;
    }
    int rownumber = a.getRowNumber();
    int n1 = a.getDeskNumber(move.p1);
    int n2 = a.getDeskNumber(move.p2);
    return checkIndex(rownumber, move) && n1 == n2;
}

bool Checker::checkIndex(int max, Move& move) {
    int p1c = move.p1.col;
    int p2c = move.p2.col;
    int p1r = move.p1.row;
    int p2r = move.p2.row;
    if (checkRange(max, move)) {
        if ((p1c == p2c) && (std::abs((p1r - p2r)) == 1)) {
            return true;
        } else if ((p1r == p2r) && (std::abs(p1c - p2c) == 1)) {
            return true;
        }
        return false;
    }
    return false;
}

bool Checker::checkRange(int max, Move& move) {
    int p1c = move.p1.col;
    int p2c = move.p2.col;
    int p1r = move.p1.row;
    int p2r = move.p2.row;
    bool gt0 = p1r >= 0 && p1c >= 0 && p2r >= 0 && p2c >= 0;
    bool ltm = p1r < max && p1c < max && p2r < max && p2c < max;
    return gt0 && ltm;
}

