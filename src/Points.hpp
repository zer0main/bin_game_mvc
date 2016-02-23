/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

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

