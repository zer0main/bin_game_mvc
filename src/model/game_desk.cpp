#include <stdlib.h>

#include "game_desk.hpp"

int GameDesk::getRowNumber() const {
    return row_number_;
}

int GameDesk::getDeskNumber(const Point& point) const {
    return desk_[point.col * row_number_ + point.row];
}

void GameDesk::setDeskNumber(const Point& point, int number) {
    desk_[point.col * row_number_ + point.row] = number;
}

void GameDesk::resize(int row_number) {
    int square = row_number * row_number;
    desk_.resize(square);
    row_number_ = row_number;
}

void GameDesk::saveStep(const Move& move) {
    moves_.push_back(move);
}

Move GameDesk::getStep(int step_number) const {
    return moves_[step_number];
}
