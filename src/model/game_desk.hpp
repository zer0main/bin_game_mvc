/** ..., ...
  * Copyright (C) 2014, ....
  * ....
  */

#ifndef GAME_DESK_HPP_
#define GAME_DESK_HPP_

#include <vector>

#include "points.hpp"

class GameDesk {
public:
    int getRowNumber() const;

    int getDeskNumber(const Point& point) const;

    void setDeskNumber(const Point& point, int number);

    void resize(int row_number);

private:
    typedef unsigned long long int Int;
    typedef std::vector<Int> Ints;
    
    Ints desk_;
    int rownumber_;
};        

#endif
