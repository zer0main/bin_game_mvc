/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iostream>
#include <limits>

#include "ConsoleBotView.hpp"

void ConsoleBotView::view() {
    while (true) {
    }
}

void ConsoleBotView::errorHandling(std::exception& e) const {
    std::cout << e.what() << std::endl;
}

void ConsoleBotView::outputGeneral() const {
    Point point;
    int row_number = game_->desk->getRowNumber();
    for (int i = row_number - 1; i >= 0; i--) {
        for (int x = 0; x < row_number; x++) {
            point.col = i;
            point.row = x;
            char prev_fill = std::cout.fill(' ');
            int prev_width = std::cout.width(5);
            std::cout << game_->desk->getDeskNumber(point);
            std::cout.width(prev_width);
            std::cout.fill(prev_fill);
        }
        std::cout << std::endl;
    }
}

void ConsoleBotView::prompt() const {
    std::cout << ">>> ";
}

const GameDesk* ConsoleBotView::getDesk() const {
    return game_->desk.data();
}

void ConsoleBotView::typeError() const {
    std::cout << "Error: you must enter the NUMBER" << std::endl;
    std::cout << "Try again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void ConsoleBotView::rangeError() const {
    std::cout << "This number is out of allowable "
                 "range." << std::endl;
    std::cout << "Try again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void ConsoleBotView::finish_impl(bool fail, int score,
                                 int steps_number) const {
    if (fail) {
        std::cout << "You are loser... Your score is " << score << std::endl;
    } else {
        std::cout << "You are winner! Your score is " << score << std::endl;
    }
    std::cout << "You have completed the game in " << steps_number << " steps." << std::endl;
}

void ConsoleBotView::sendHelpMessage_impl() const {
    std::cout << "You must enter t, w, s or q" << std::endl;
    std::cout << "Try again please." << std::endl;
}

void ConsoleBotView::startGame_impl(int row_number) {
    try {
        game_ = Game::make(row_number);
        game_->controller->initialStateOfBoard();
    } catch (std::exception& e) {
        errorHandling(e);
    }
}

void ConsoleBotView::start() const {
    std::cout << "*** BIN_GAME ***" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "t: time mode | w: play for score | s: "
                 "play while not lose" << std::endl;
    std::cout << "q: quit" << std::endl;
    prompt();
}

void ConsoleBotView::gameForWin() {
    int desk_size = getDeskSize_impl();
    int win_number = getWinNumber_impl();
    startGame_impl(desk_size);
    const GameDesk* desk = game_->desk.data();
    output_impl();
    int steps_number = 0;
    while (!checkFail(*desk) && !checkWin(*desk,
                                          win_number)) {
        steps_number += 1;
        play();
    }
    finish_impl(checkFail(*desk), score(*desk),
                steps_number);
}

void ConsoleBotView::gameForScore() {
    int desk_size = getDeskSize_impl();
    startGame_impl(desk_size);
    const GameDesk* desk = game_->desk.data();
    output_impl();
    int steps_number = 0;
    while (!checkFail(*desk)) {
        steps_number += 1;
        play();
    }
    finish_impl(checkFail(*desk), score(*desk),
                steps_number);
}

void ConsoleBotView::gameWithTime() {
    int desk_size = getDeskSize_impl();
    int time_number = getTimeNumber_impl();
    startGame_impl(desk_size);
    int t1 = time(NULL);
    int t2 = 0;
    const GameDesk* desk = game_->desk.data();
    output_impl();
    int steps_number = 0;
    while (!checkFail(*desk) &&
           ((t2 - t1) < time_number * 60)) {
        steps_number += 1;
        play();
        t2 = time(NULL);
    }
    finish_impl(checkFail(*desk), score(*desk),
                steps_number);
}

void ConsoleBotView::play() {
    Points points = getIndex_impl();
    try {
        game_->controller->replace(points);
    } catch (std::exception& e) {
        errorHandling(e);
    }
    output_impl();
}
