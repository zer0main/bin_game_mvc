/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iostream>

#include "ConsoleView.hpp"

int ConsoleView::getDeskSize_impl() const {
    int deskSize;
    std::cout << "Please enter size of the game board."
              << std::endl;
    std::cout << "Your board will have x * x square."
              << std::endl;
    std::cout << "(Where x is input size)" << std::endl;
    std::cout << "Minimum size is " << MIN_WIDTH << " and "
                 "maximum is " << MAX_WIDTH << std::endl;
    std::cout << "But try to choose size which "
                 "corresponds to the size of your screen."
              << std::endl;
    prompt();
    while (true) {
        if (std::cin >> deskSize) {
            if (checkRange(deskSize, BOARDS_SIZE)) {
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
    int square = getBoardsSquare();
    std::cout << "What score you want to finish the "
                 "game?" << std::endl;
    std::cout << "Minimum is " << square * 2 << " and "
                 "maximum is " << MAX_SCORE << std::endl;
    prompt();
    while (true) {
        if (std::cin >> winNumber) {
            if (checkRange(winNumber, SCORE)) {
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
            if (checkRange(timeNumber, TIME)) {
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

int ConsoleView::getInitialParameter(TypeOfChecking type) const {
    int parameter;
    while (true) {
        if (std::cin >> parameter) {
            if (checkRange(parameter, type)) {
                break;
            } else {
                rangeError();
            }
        } else {
            typeError();
        }
    }
    return parameter;
}
