#ifndef POINTS_HPP_
#define POINTS_HPP_

#include <vector>

struct Point {
    int col;
    int row;
};

struct Points {
    Point p1;
    Point p2;

    int undo_steps_number;
    bool undo_action;
};

typedef std::vector<Points> Moves;

typedef unsigned long long int Int;
typedef std::vector<Int> Ints;

#endif

