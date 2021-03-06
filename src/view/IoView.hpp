/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef IOVIEW_HPP_
#define IOVIEW_HPP_

#include "Points.hpp"
#include "GameDesk.hpp"

class IoView {
protected:
    virtual int getDeskSize_impl() const = 0;

    virtual int getWinNumber_impl() const = 0;

    virtual int getTimeNumber_impl() const = 0;

    virtual void finish_impl(bool check_fail, int score, int steps_number) const = 0;

    virtual void sendHelpMessage_impl() const = 0;

    virtual void startGame_impl(int row_number) = 0;

    virtual void errorHandling_impl(std::exception& e) const = 0;
};

#endif

