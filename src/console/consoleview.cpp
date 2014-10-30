#include <string>
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
    std::string str;
    if (std::cin >> str) {
        if (str == "u") {
            getUndoNumber(points);
            return points;
        }
    }
    points.undo_action = false;
    while (!(std::cin >> points.p1.col >> points.p1.row)) {
        typeError_impl();
    }
    std::cout << "And of number2: " << std::endl;
    while (!(std::cin >> points.p2.col >> points.p2.row)) {
        typeError_impl();
    }
    return points;
}

void ConsoleView::getUndoNumber(Points& points) const {
    points.undo_action = true;
    std::cout << "How many steps you want to cancel? " << std::endl;
    std::cin >> points.undo_steps_number;
}

void ConsoleView::output_impl() const {
    outputGeneral();
}
