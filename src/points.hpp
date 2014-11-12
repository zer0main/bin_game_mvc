#ifndef POINTS_HPP_
#define POINTS_HPP_

#include <vector>

struct Point {
    int col;
    int row;
};

struct Move {
    Point p1;
    Point p2;

    bool undo_action;
    int undo_steps_number;
    int random_number;
};

typedef std::vector<Move> Moves;

typedef unsigned long long int Int;
typedef std::vector<Int> Ints;

#endif

