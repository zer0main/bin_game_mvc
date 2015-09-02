/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iomanip>
#include <iostream>
#include <limits>

#include "ConsoleBotView.hpp"

static int numberOfDigits(int number) {
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

static void printSpaces(int spaces) {
    for (int i = 0; i < spaces; i++) {
        std::cout << " ";
    }
}

void ConsoleBotView::view() {
    while (true) {
        start();
        char mode;
        std::cin >> mode;
        switch (mode) {
            case 't':
                gameWithTime();
                break;
            case 'w':
                gameForWin();
                break;
            case 's':
                gameForScore();
                break;
            case 'q':
                return;
            default:
                sendHelpMessage_impl();
        }
    }
}

void ConsoleBotView::timeNumberMessage() const {
    std::cout << "How many minutes you want to play?" << std::endl;
    std::cout << "The default is " << Rules::DEFAULT_TIME
              << std::endl;
    prompt();
}

void ConsoleBotView::winNumberMessage() const {
    int square = getBoardsSquare();
    std::cout << "What score you want to finish the "
                 "game?" << std::endl;
    std::cout << "The default is " << square * 4
              << std::endl;
    prompt();
}

void ConsoleBotView::deskSizeMessage() const {
    std::cout << "Please enter size of the game board."
              << std::endl;
    std::cout << "Your board will have x * x square."
              << std::endl;
    std::cout << "(Where x is input size)" << std::endl;
    std::cout << "Minimum size is " << Rules::MIN_WIDTH
              << " and maximum is " << Rules::MAX_WIDTH
              << std::endl;
    std::cout << "But try to choose size which "
                 "corresponds to the size of your screen."
              << std::endl;
    prompt();
}

void ConsoleBotView::outputGeneral() const {
    int digits = numberOfDigits(maxDeskNumber());
    int width = Console::NUMBER_OF_SPACES + digits;
    int row_number = game_->desk->getRowNumber();
    for (int i = row_number - 1; i >= 0; i--) {
        std::cout << std::right
                  << std::setw(Console::MAX_INDEX_LENGTH)
                  << i << " ||";
        for (int x = 0; x < row_number; x++) {
            Point point;
            point.col = i;
            point.row = x;
            std::cout << std::right << std::setw(width)
                      << game_->desk->getDeskNumber(point);
        }
        std::cout << std::endl;
    }
    rowIndices(width);
    std::cout << std::endl;
}

void ConsoleBotView::prompt() const {
    std::cout << ">>> ";
}

void ConsoleBotView::typeError() const {
    std::cout << "Error: you must enter the NUMBER" << std::endl;
    std::cout << "Try again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void ConsoleBotView::rangeError(TypeOfChecking type) const {
    int max_int = std::numeric_limits<int>::max();
    std::cout << "This number is out of allowable "
                 "range." << std::endl;
    if (type == TIME) {
        std::cout << "Please enter a POSITIVE INTEGER"
                  << std::endl;
        std::cout << "Maximum is " << max_int << std::endl;
    } else if (type == SCORE) {
        int square = getBoardsSquare();
        std::cout << "For this size of the game board "
                  << "minimum is " << square * 2 + 1
                  << std::endl;
        std::cout << "Maximum is " << max_int << std::endl;

    }
    std::cout << "Try again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(max_int, '\n');
}

bool ConsoleBotView::checkRange(int verifiable,
                                TypeOfChecking type) const {
    switch (type) {
        case BOARDS_SIZE:
            return ((verifiable >= Rules::MIN_WIDTH) &&
                    (verifiable <= Rules::MAX_WIDTH));
        case TIME:
            // By checking that verifiable is greater than
            // zero we make sure that it's less or equal
            // to the allowable maximum for int also.
            // See cyclic mechanism of ints in C++.
            return (verifiable > 0);
        case SCORE:
            int square = getBoardsSquare();
            return (verifiable > square * 2);
    }
}

int ConsoleBotView::getBoardsSquare() const {
    int boards_size = game_->desk->getRowNumber();
    return boards_size * boards_size;
}

const GameDesk* ConsoleBotView::getDesk() const {
    return game_->desk.data();
}

void ConsoleBotView::finish_impl(bool fail, int score,
                                 int steps_number) const {
    if (fail) {
        std::cout << "You are loser... Your score is " << score << std::endl;
    } else {
        std::cout << "You are winner! Your score is " << score << std::endl;
    }
    std::cout << "You have completed the game in " << steps_number << " steps." << std::endl;
}

void ConsoleBotView::sendHelpMessage_impl() const {
    std::cout << "You must enter t, w, s or q" << std::endl;
    std::cout << "Try again please." << std::endl;
}

void ConsoleBotView::startGame_impl(int row_number) {
    try {
        game_ = Game::make(row_number);
        game_->controller->initialStateOfBoard();
    } catch (std::exception& e) {
        errorHandling_impl(e);
    }
}

void ConsoleBotView::errorHandling_impl(std::exception& e) const {
    std::cout << e.what() << std::endl;
}

int ConsoleBotView::maxDeskNumber() const {
    const GameDesk* desk = game_->desk.data();
    int boards_size = desk->getRowNumber();
    int max = 0;
    for (int i = boards_size - 1; i >= 0; i--) {
        for (int x = 0; x < boards_size; x++) {
            Point pt;
            pt.col = i;
            pt.row = x;
            int current_number = desk->getDeskNumber(pt);
            if (current_number > max) {
                max = current_number;
            }
        }
    }
    return max;
}

void ConsoleBotView::rowIndices(int width) const {
    int boards_size = game_->desk->getRowNumber();
    printSpaces(Console::INDEX_FIELD);
    for (int i = 0; i < width * boards_size; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
    printSpaces(Console::INDEX_FIELD);
    for (int i = 0; i < boards_size; i++) {
        std::cout << std::right << std::setw(width) << i;
    }
}

void ConsoleBotView::start() const {
    std::cout << "*** BIN_GAME ***" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "t: time mode | w: play for score | s: "
                 "play while not lose" << std::endl;
    std::cout << "q: quit" << std::endl;
    prompt();
}

void ConsoleBotView::gameForWin() {
    int desk_size = getDeskSize_impl();
    startGame_impl(desk_size);
    int win_number = getWinNumber_impl();
    const GameDesk* desk = game_->desk.data();
    output_impl();
    int steps_number = 0;
    while (!checkFail(*desk) && !checkWin(*desk,
                                          win_number)) {
        steps_number += 1;
        play();
    }
    finish_impl(checkFail(*desk), score(*desk),
                steps_number);
}

void ConsoleBotView::gameForScore() {
    int desk_size = getDeskSize_impl();
    startGame_impl(desk_size);
    const GameDesk* desk = game_->desk.data();
    output_impl();
    int steps_number = 0;
    while (!checkFail(*desk)) {
        steps_number += 1;
        play();
    }
    finish_impl(checkFail(*desk), score(*desk),
                steps_number);
}

void ConsoleBotView::gameWithTime() {
    int desk_size = getDeskSize_impl();
    int time_number = getTimeNumber_impl();
    startGame_impl(desk_size);
    int t1 = time(NULL);
    int t2 = 0;
    const GameDesk* desk = game_->desk.data();
    output_impl();
    int steps_number = 0;
    while (!checkFail(*desk) &&
           ((t2 - t1) < time_number * 60)) {
        steps_number += 1;
        play();
        t2 = time(NULL);
    }
    finish_impl(checkFail(*desk), score(*desk),
                steps_number);
}

void ConsoleBotView::play() {
    Points points = getIndex_impl();
    try {
        game_->controller->replace(points);
    } catch (std::exception& e) {
        errorHandling_impl(e);
    }
    output_impl();
}
