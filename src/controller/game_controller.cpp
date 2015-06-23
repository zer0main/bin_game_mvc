/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <stdlib.h>

#include "game_controller.hpp"

static bool getOneHalf() {
    return rand() <= (RAND_MAX / 2);
}

GameController* GameController::make(GameDesk* desk) {
    if (desk == NULL) {
        throw Exception("Received NULL pointer to "
                        "GameDesk when try to create "
                        "GameController");
    }
    GameController* controller = new GameController();
    controller->desk_ = desk;
    return controller;
}

void GameController::setDesk(int desk_size) {
    Point point;
    for (int i = 0; i < desk_size; i++) {
        for (int x = 0; x < desk_size; x++) {
            point.col = i;
            point.row = x;
            newRandomNumber(point);
        }
    }
}

void GameController::replace(Points& points) {
    Checker checker;
    if (!checker.checkStep(*desk_, points)) {
        throw Exception("Error: wrong index of numbers "
                        "or numbers with this index "
                        "aren't neighboring or equal");
    }
    int n1 = desk_->getDeskNumber(points.p1);
    int n2 = desk_->getDeskNumber(points.p2);
    desk_->setDeskNumber(points.p2, n2 * 2);
    gravity(points.p1);
    newRandomNumber(points.p1);
}

void GameController::newRandomNumber(const Point& point) {
    bool rand = getOneHalf();
    int new_number = (rand) ? 2 : 1;
    desk_->setDeskNumber(point, new_number);
}

void GameController::gravity(Point& free_space) {
    while (free_space.col < (desk_->getRowNumber() - 1)) {
        Point next = free_space;
        next.col += 1;
        desk_->setDeskNumber(free_space,
                             desk_->getDeskNumber(next));
        free_space.col = next.col;
    }
}

GameController::GameController() {
}
