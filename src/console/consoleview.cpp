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
    std::cout << "Enter the size of game desk "
                 "(desk's size >= 3 and <= 16!)" << std::endl;
    while (true) {
        if (std::cin >> deskSize) {
            if (checkRange(deskSize, 1)) {
                break;
            } else {
                rangeError();
            }
        } else {
            typeError();
        }
    }
    return deskSize;
}

int ConsoleView::getWinNumber_impl() const {
    int winNumber;
    std::cout << "What score you want to finish the "
                 "game?" << std::endl;
    std::cout << "Minimum is 10 and maximum is 9999999" << std::endl;
    while (true) {
        if (std::cin >> winNumber) {
            if (checkRange(winNumber, 3)) {
                break;
            } else {
                rangeError();
            }
        } else {
            typeError();
        }
    }
    return winNumber;
}

int ConsoleView::getTimeNumber_impl() const {
    int timeNumber;
    std::cout << "How many minutes you want to play?" << std::endl;
    std::cout << "Minimum is 1 and maximum is 1000" << std::endl;
    while (true) {
        if (std::cin >> timeNumber) {
            if (checkRange(timeNumber, 2)) {
                break;
            } else {
                rangeError();
            }
        } else {
            typeError();
        }
    }
    return timeNumber;
}

Points ConsoleView::getIndex_impl() const {
    Points points;
    std::cout << "Enter index of number1" << std::endl;
    while (!(std::cin >> points.p1.col >> points.p1.row)) {
        typeError();
    }
    std::cout << "And of number2" << std::endl;
    while (!(std::cin >> points.p2.col >> points.p2.row)) {
        typeError();
    }
    return points;
}

void ConsoleView::output_impl() const {
    outputGeneral();
}
