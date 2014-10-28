#include <iostream>

#include "consoleview.hpp"

int ConsoleView::getDeskSize_impl() const {
    int deskSize;
    std::cout << "Choose the size of game desk: " << std::endl;
    while (!(std::cin >> deskSize)) {
        typeError_impl();
    }
    return deskSize;
}

int ConsoleView::getWinNumber_impl() const {
    int winNumber;
    std::cout << "What number you want to finish the game? " << std::endl;
    while (!(std::cin >> winNumber)) {
        typeError_impl();
    }
    return winNumber;
}

int ConsoleView::getTimeNumber_impl() const {
    int timeNumber;
    std::cout << "How many time you want to play (min)? " << std::endl;
    while (!(std::cin >> timeNumber)) {
        typeError_impl();
    }
    return timeNumber;
}

Points ConsoleView::getIndex_impl() const {
    Points points;
    std::cout << "Enter index of number1: " << std::endl;
    while (!(std::cin >> points.p1.col >> points.p1.row)) {
        typeError_impl();
    }
    std::cout << "And of number2: " << std::endl;
    while (!(std::cin >> points.p2.col >> points.p2.row)) {
        typeError_impl();
    }
    return points;
}

void ConsoleView::output_impl() const {
    const GameDesk* desk = getDesk();
    Point point;
    int i, x;
    for (i = desk->getRowNumber() - 1; i >= 0; i--) {
        for (x = 0; x < desk->getRowNumber(); x++) {
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
