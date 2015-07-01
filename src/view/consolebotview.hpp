/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef CONSOLEBOTVIEW_HPP_
#define CONSOLEBOTVIEW_HPP_

#include "Game.hpp"
#include "ioview.hpp"

class ConsoleBotView: public IoView {
public:
    void view() const;

protected:
    void start() const;

    void outputGeneral() const;

    void prompt() const;

    const GameDesk* getDesk() const;

    void typeError() const;

    void indexError() const;

    void finish_impl(bool check_fail, int score, int steps_number) const;

    void sendHelpMessage_impl() const;

private:
    GamePtr game_;
};

#endif
