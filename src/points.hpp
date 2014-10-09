#ifndef POINTS_HPP_
#define POINTS_HPP_

#include <vector>

typedef unsigned long long int Int;
typedef std::vector<Int> Ints;
    
struct Point {
    int col;
    int row;
};

struct Points {
    Point p1;
    Point p2;
};

#endif
