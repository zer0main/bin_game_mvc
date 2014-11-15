#ifndef POINTS_HPP_
#define POINTS_HPP_

#include <vector>

typedef std::vector<int> Ints;

struct Point {
    int col;
    int row;
};

struct Points {
    Point p1;
    Point p2;
};

#endif

