/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <time.h>
#include <stdlib.h>

#include "game_modes.hpp"

static bool getOneHalf() {
    return rand() <= (RAND_MAX / 2);
}

GameModes* GameModes::make(GameDesk* desk) {
    if (desk == NULL) {
        throw Exception("Received NULL pointer to "
                        "GameDesk when try to create "
                        "GameModes");
    }
    GameModes* controller = new GameModes();
    controller->desk_ = desk;
    return controller;
}

void GameModes::setDesk(int desk_size) {
    Point point;
    desk_->resize(desk_size);
    for (int i = 0; i < desk_size; i++) {
        for (int x = 0; x < desk_size; x++) {
            point.col = i;
            point.row = x;
            newRandomNumber(point);
        }
    }
}

void GameModes::replace(Points& points) {
    int n1 = desk_->getDeskNumber(points.p1);
    int n2 = desk_->getDeskNumber(points.p2);
    desk_->setDeskNumber(points.p2, n2 * 2);
    gravity(points.p1);
    newRandomNumber(points.p1);
}

void GameModes::newRandomNumber(const Point& point) {
    bool rand = getOneHalf();
    int new_number = (rand) ? 2 : 1;
    desk_->setDeskNumber(point, new_number);
}

void GameModes::gravity(Point& free_space) {
    while (free_space.col < (desk_->getRowNumber() - 1)) {
        Point next = free_space;
        next.col += 1;
        desk_->setDeskNumber(free_space,
                             desk_->getDeskNumber(next));
        free_space.col = next.col;
    }
}

GameModes::GameModes() {
}
