#include <time.h>
#include <stdlib.h>

#include "game_modes.hpp"

GameModes::GameModes(GameDesk *desk_point, IoBase *io_base_point) {
    desk_ = desk_point;
    iobase_ = io_base_point;
}

void GameModes::start(int argc, char *argv[]) {
    if (argc == 1) {
        help();
    }
    else if (*++argv[1] == 'w') {
        gameForWin();
    }
    else if (*argv[1] == 's') {
        gameForScore();
    }
    else if (*argv[1] == 't') {
        gameWithTime();
    }
    else {
        help();
    }
}

void GameModes::gameForWin() {
    int desk_size;
    desk_size = iobase_->getDeskSize();
    int win_number;
    win_number = iobase_->getWinNumber();
    setDesk(desk_size);
    iobase_->output();
    while (!checkFail() && !checkWin(win_number)) {
        play();
    }
    iobase_->finish(checkFail(), score());
}

void GameModes::gameForScore() {
    int desk_size;
    desk_size = iobase_->getDeskSize();
    setDesk(desk_size);
    iobase_->output();
    while (!checkFail()) {
        play();
    }
    iobase_->finish(checkFail(), score());
}

void GameModes::gameWithTime() {
    int desk_size;
    desk_size = iobase_->getDeskSize();
    int time_number;
    time_number = iobase_->getTimeNumber();
    setDesk(desk_size);
    int t1 = time(NULL);
    int t2 = 0;
    iobase_->output();
    while (!checkFail() && ((t2 - t1) < time_number * 60)) {
        play();
        t2 = time(NULL);
    }
    iobase_->finish(checkFail(), score());
}

void GameModes::help() {
    iobase_->sentHelpMessage();
}

void GameModes::setDesk(int desk_size) {
    int i, x;
    Point point;
    desk_->resize(desk_size);
    for (i = 0; i < desk_size; i++) {
        for (x = 0; x < desk_size; x++) {
            point.col = i;
            point.row = x; 
            if (rand() <= (RAND_MAX / 2)) {
                desk_->setDeskNumber(point, 1);
            }
            else {
                desk_->setDeskNumber(point, 2);
            }
        }
    }
}

void GameModes::play() {
    Points points;
    Checker checker;
    points = iobase_->getIndex();
    if (checker.checkStep(*desk_, points)) {
        replace(points);
        iobase_->output();
    }
    else {
        iobase_->indexError();
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
    }
    else {
        desk_->setDeskNumber(points.p1, 1);
    }
}

long long int GameModes::score() {
    Point point;
    long long int all_score = 0;
    long long int row_score = 0;
    int i, x;
    for (i = 0; i < desk_->getRowNumber(); i++) {
        for (x = 0; x < desk_->getRowNumber(); x++) {
            point.col = i;
            point.row = x;
            row_score += desk_->getDeskNumber(point);
        }
        all_score += row_score;
        row_score = 0;
    }
    return all_score;
}

bool GameModes::checkWin(int for_win) {
    if (for_win <= score()) {
        return true;
    }
    return false;
}

bool GameModes::checkFail() {
    Points points;
    Checker checker;
    int i, x, z, t;
    for (i = 0; i < desk_->getRowNumber(); i++) {
        points.p1.col = i;
        for (x = 0; x < desk_->getRowNumber(); x++) {
            points.p1.row = x;
            for (z = 0; z < desk_->getRowNumber(); z++) {
                points.p2.col = z;
                for (t = 0; t < desk_->getRowNumber(); t++) {
                    points.p2.row = t;
                    if (checker.checkStep(*desk_, points)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
