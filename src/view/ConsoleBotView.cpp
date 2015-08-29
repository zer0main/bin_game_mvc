/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iomanip>
#include <iostream>
#include <limits>

#include "ConsoleBotView.hpp"

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
    std::cout << "Minimum is " << MIN_TIME << " and "
                 "maximum is " << MAX_TIME << std::endl;
    prompt();
}

void ConsoleBotView::winNumberMessage() const {
    int square = getBoardsSquare();
    std::cout << "What score you want to finish the "
                 "game?" << std::endl;
    std::cout << "Minimum is " << square * 2 << " and "
                 "maximum is " << MAX_SCORE << std::endl;
    prompt();
}

void ConsoleBotView::deskSizeMessage() const {
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
}

void ConsoleBotView::outputGeneral() const {
    Point point;
    int row_number = game_->desk->getRowNumber();
    for (int i = row_number - 1; i >= 0; i--) {
        std::cout << std::right << std::setw(2)
                  << i;
        for (int x = 0; x < row_number; x++) {
            point.col = i;
            point.row = x;
            std::cout << std::right << std::setw(5)
                      << game_->desk->getDeskNumber(point);
        }
        std::cout << std::endl;
    }
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

void ConsoleBotView::rangeError() const {
    std::cout << "This number is out of allowable "
                 "range." << std::endl;
    std::cout << "Try again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

bool ConsoleBotView::checkRange(int verifiable,
                                TypeOfChecking type) const {
    switch (type) {
        case BOARDS_SIZE:
            return ((verifiable >= MIN_WIDTH) &&
                    (verifiable <= MAX_WIDTH));
        case TIME:
            return ((verifiable >= MIN_TIME) &&
                    (verifiable <= MAX_TIME));
        case SCORE:
            int square = getBoardsSquare();
            return ((verifiable >= square * 2) &&
                    (verifiable <= MAX_SCORE));
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
