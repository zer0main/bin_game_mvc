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
#include "ioview.hpp"

class ConsoleBotView: public IoView {
public:
    void view() const;

protected:
    void errorHandling(std::exception& e) const;

    void outputGeneral() const;

    void prompt() const;

    const GameDesk* getDesk() const;

    void typeError() const;

    void rangeError() const;

    virtual Points getIndex_impl() const = 0;

    virtual void output_impl() const =  0;

    void finish_impl(bool check_fail, int score, int steps_number) const;

    void sendHelpMessage_impl() const;

    void startGame_impl(int row_number);

private:
    GamePtr game_;

    void start() const;

    void gameForWin();
};

#endif
