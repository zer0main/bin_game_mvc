#include <iostream>
#include <limits>

#include "iobase.hpp"

int IoBase::getDeskSize_impl() {
    int deskSize;
    std::cout << "Choose the size of game desk: " << std::endl;
    while (!(std::cin >> deskSize)) {
        typeError_impl();
    }
    return deskSize;
}

int IoBase::getWinNumber_impl() {
    int winNumber;
    std::cout << "What number you want to finish the game? " << std::endl;
    while(!(std::cin >> winNumber)) {
        typeError_impl();
    }
    return winNumber;
}

int IoBase::getTimeNumber_impl() {
    int timeNumber;
    std::cout << "How many time you want to play (min)? " << std::endl;
    while(!(std::cin >> timeNumber)) {
        typeError_impl();
    }
    return timeNumber;
}

Points IoBase::getIndex_impl() {
    Points points;
    std::cout << "Enter index of number1: " << std::endl;
    while(!(std::cin >> points.p1.col >> points.p1.row)) {
        typeError_impl();
    }
    std::cout << "And of number2: " << std::endl;
    while(!(std::cin >> points.p2.col >> points.p2.row)) {
        typeError_impl();
    }
    return points;
}

void IoBase::typeError_impl() {
    std::cout << "Error: you must enter the NUMBER" << std::endl;
    std::cout << "Try again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void IoBase::setDesk_impl(const GameDesk* desk) {
    desk_ = desk;
}

void IoBase::output_impl() {
    Point point;
    int i, x;
    for (i = desk_->getRowNumber() - 1; i >= 0; i--) {
        for (x = 0; x < desk_->getRowNumber(); x++) {
            point.col = i;
            point.row = x;
            char prev_fill = std::cout.fill(' ');
            int prev_width = std::cout.width(5);
            std::cout << desk_->getDeskNumber(point);
            std::cout.width(prev_width);
            std::cout.fill(prev_fill);
        }
        std::cout << std::endl;
    }
}

void IoBase::indexError_impl() {
    std::cout << "Error: wrong index of numbers." << std::endl;
}

void IoBase::finish_impl(bool check_fail, long long int score) {
    if (check_fail) {
        std::cout << "You are looser... Your score is " << score << std::endl;
    }
    else {
        std::cout << "You are winner! You score is " << score << std::endl;
    }
}

void IoBase::sentHelpMessage_impl() {
    std::cout << "We haven't any help yet" << std::endl;
}
