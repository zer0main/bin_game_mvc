/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iostream>
#include <limits>

#include "consolebotview.hpp"

void ConsoleBotView::view() const {
    while (true) {
    }
}

void ConsoleBotView::start() const {
    std::cout << "*** BIN_GAME ***" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "t: time mode | w: play for score | s: "
                 "play while not lose" << std::endl;
    std::cout << "q: quit" << std::endl;
    std::cout << ">>> ";
}

void ConsoleBotView::outputGeneral() const {
    const GameDesk* desk = getDesk();
    Point point;
    for (int i = desk->getRowNumber() - 1; i >= 0; i--) {
        for (int x = 0; x < desk->getRowNumber(); x++) {
            point.col = i;
            point.row = x;
            char prev_fill = std::cout.fill(' ');
            int prev_width = std::cout.width(5);
            std::cout << desk->getDeskNumber(point);
            std::cout.width(prev_width);
            std::cout.fill(prev_fill);
        }
        std::cout << std::endl;
    }
}

void ConsoleBotView::prompt() const {
    std::cout << ">>> ";
}

void ConsoleBotView::sendHelpMessage_impl() const {
    std::cout << "To play this game you must use the options: -w for play to win\n"
              "-t for game with real time and -s to play while not lose." << std::endl;
}

void ConsoleBotView::finish_impl(bool check_fail, int score, int steps_number) const {
    if (check_fail) {
        std::cout << "You are loser... Your score is " << score << std::endl;
    } else {
        std::cout << "You are winner! Your score is " << score << std::endl;
    }
    std::cout << "You have completed the game in " << steps_number << " steps." << std::endl;
}

void ConsoleBotView::typeError_impl() const {
    std::cout << "Error: you must enter the NUMBER" << std::endl;
    std::cout << "Try again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void ConsoleBotView::indexError_impl() const {
    std::cout << "Error: wrong index of numbers." << std::endl;
}
