/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iostream>

#include "ConsoleView.hpp"

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
    std::cout << "Please enter size of the game board."
                 "(desk's size >= 3 and <= 16!)" << std::endl;
    prompt();
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
    std::cout << "Minimum is " << MIN_SCORE << " and "
                 "maximum is " << MAX_SCORE << std::endl;
    prompt();
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
    std::cout << "Minimum is " << MIN_TIME << " and "
                 "maximum is " << MAX_TIME << std::endl;
    prompt();
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
    std::cout << "Please enter index of the first number."
              << std::endl;
    prompt();
    while (!(std::cin >> points.p1.col >> points.p1.row)) {
        typeError();
    }
    std::cout << "Please enter index of the second "
                 "number." << std::endl;
    prompt();
    while (!(std::cin >> points.p2.col >> points.p2.row)) {
        typeError();
    }
    return points;
}

void ConsoleView::output_impl() const {
    outputGeneral();
}
