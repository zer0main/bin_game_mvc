#include <stdlib.h>

#include "game_desk.hpp"

const int GameDesk::getRowNumber() {
    return rownumber_;
}

const int GameDesk::getDeskNumber(Point& point) {
    return desk_[point.col * rownumber_ + point.row];
}

void GameDesk::setDeskNumber(Point& point, int number) {
    desk_[point.col * rownumber_ + point.row] = number;
}

void GameDesk::resize(int row_number) {
    desk_.resize(row_number * row_number);
}
