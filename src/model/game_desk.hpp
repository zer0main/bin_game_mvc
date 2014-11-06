/** ..., ...
  * Copyright (C) 2014, ....
  * ....
  */

#ifndef GAME_DESK_HPP_
#define GAME_DESK_HPP_

#include "points.hpp"

class GameDesk {
public:
    int getRowNumber() const;

    int getDeskNumber(const Point& point) const;

    void setDeskNumber(const Point& point, int number);

    void resize(int row_number);

    void saveStep(Move& move);

    void getStep(int step_number);

private:
    Moves moves_;
    Ints desk_;
    int row_number_;
};

#endif

