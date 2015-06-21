/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <time.h>
#include <stdlib.h>

#include "game_modes.hpp"

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
            if (rand() <= (RAND_MAX / 2)) {
                desk_->setDeskNumber(point, 1);
            } else {
                desk_->setDeskNumber(point, 2);
            }
        }
    }
}

void GameModes::replace(Points& points) {
    int n1 = desk_->getDeskNumber(points.p1);
    int n2 = desk_->getDeskNumber(points.p2);
    desk_->setDeskNumber(points.p2, n2 * 2);
    while (points.p1.col < (desk_->getRowNumber() - 1)) {
        Points points_local;
        points_local = points;
        points_local.p1.col += 1;
        desk_->setDeskNumber(points.p1, desk_->getDeskNumber(points_local.p1));
        points.p1.col = points_local.p1.col;
    }
    if (rand() <= (RAND_MAX / 2)) {
        desk_->setDeskNumber(points.p1, 2);
    } else {
        desk_->setDeskNumber(points.p1, 1);
    }
}

GameModes::GameModes() {
}
