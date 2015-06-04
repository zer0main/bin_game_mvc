/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef IOVIEW_HPP_
#define IOVIEW_HPP_

#include "points.hpp"
#include "game_desk.hpp"

class IoView {
public:
    IoView();

    virtual ~IoView();

    int getDeskSize() const;

    int getWinNumber() const;

    int getTimeNumber() const;

    const GameDesk* getDesk() const;

    Points getIndex() const;

    void typeError() const;

    void setDesk(const GameDesk* desk);

    void output() const;

    void indexError() const;

    void finish(bool check_fail, int score, int steps_number) const;

    void sendHelpMessage() const;

protected:
    virtual int getDeskSize_impl() const = 0;

    virtual int getWinNumber_impl() const = 0;

    virtual int getTimeNumber_impl() const = 0;

    virtual Points getIndex_impl() const = 0;

    virtual void typeError_impl() const = 0;

    virtual void output_impl() const =  0;

    virtual void indexError_impl() const = 0;

    virtual void finish_impl(bool check_fail, int score, int steps_number) const = 0;

    virtual void sendHelpMessage_impl() const = 0;

private:
    const GameDesk* desk_;
};

#endif

