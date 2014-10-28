#include <iostream>
#include <limits>

#include "iobase.hpp"

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

void ConsoleView::typeError_impl() const {
    std::cout << "Error: you must enter the NUMBER" << std::endl;
    std::cout << "Try again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
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

void ConsoleView::indexError_impl() const {
    std::cout << "Error: wrong index of numbers." << std::endl;
}

void ConsoleView::finish_impl(bool check_fail, long long int score) const {
    if (check_fail) {
        std::cout << "You are loser... Your score is " << score << std::endl;
    } else {
        std::cout << "You are winner! You score is " << score << std::endl;
    }
}

void ConsoleView::sendHelpMessage_impl() const {
    std::cout << "To play this game you must use the options: -w for play to win\n"
              "-t for game with real time and -s to play while not lose." << std::endl;
}

