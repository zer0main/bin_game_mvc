/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iostream>

#include "ConsoleView.hpp"

int ConsoleView::getDeskSize_impl() const {
    deskSizeMessage();
    return getInitialParameter(BOARDS_SIZE);
}

int ConsoleView::getWinNumber_impl() const {
    winNumberMessage();
    return getInitialParameter(SCORE);
}

int ConsoleView::getTimeNumber_impl() const {
    timeNumberMessage();
    return getInitialParameter(TIME);
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
