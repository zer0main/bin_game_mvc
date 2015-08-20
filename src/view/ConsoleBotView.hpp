/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef CONSOLEBOTVIEW_HPP_
#define CONSOLEBOTVIEW_HPP_

#include "desk_functions.hpp"
#include "constants.hpp"
#include "Game.hpp"
#include "IoView.hpp"

enum TypeOfChecking {
    SCORE,
    BOARDS_SIZE,
    TIME,
};

class ConsoleBotView: public IoView {
public:
    void view();

protected:
    void deskSizeMessage() const;

    void outputGeneral() const;

    void prompt() const;

    void typeError() const;

    void rangeError() const;

    bool checkRange(int verifiable,
                    TypeOfChecking type) const;

    int getBoardsSquare() const;

    const GameDesk* getDesk() const;

    virtual Points getIndex_impl() const = 0;

    virtual void output_impl() const =  0;

    void finish_impl(bool fail, int score,
                     int steps_number) const;

    void sendHelpMessage_impl() const;

    void startGame_impl(int row_number);

    void errorHandling_impl(std::exception& e) const;

private:
    GamePtr game_;

    void start() const;

    void gameForWin();

    void gameForScore();

    void gameWithTime();

    void play();
};

#endif
