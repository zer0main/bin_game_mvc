/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iostream>

#include "consoleview.hpp"

static bool checkRange(int verifiable, int type) {
    switch (type) {
        case 1:
            return ((verifiable >= MIN_WIDTH) &&
                    (verifiable <= MAX_WIDTH));
        case 2:
            return ((verifiable >= MIN_TIME) &&
                    (verifiable <= MAX_TIME));
        case 3:
            return ((verifiable >= MIN_SCORE) &&
                    (verifiable <= MAX_SCORE));
    }
}

int ConsoleView::getDeskSize_impl() const {
    int deskSize;
    std::cout << "Choose the size of game desk: " << std::endl;
    while (!(std::cin >> deskSize)) {
        typeError();
    }
    return deskSize;
}

int ConsoleView::getWinNumber_impl() const {
    int winNumber;
    std::cout << "What number you want to finish the game? " << std::endl;
    while (!(std::cin >> winNumber)) {
        typeError();
    }
    return winNumber;
}

int ConsoleView::getTimeNumber_impl() const {
    int timeNumber;
    std::cout << "How many time you want to play (min)? " << std::endl;
    while (!(std::cin >> timeNumber)) {
        typeError();
    }
    return timeNumber;
}

Points ConsoleView::getIndex_impl() const {
    Points points;
    std::cout << "Enter index of number1: " << std::endl;
    while (!(std::cin >> points.p1.col >> points.p1.row)) {
        typeError();
    }
    std::cout << "And of number2: " << std::endl;
    while (!(std::cin >> points.p2.col >> points.p2.row)) {
        typeError();
    }
    return points;
}

void ConsoleView::output_impl() const {
    outputGeneral();
}
