/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef IOBASE_HPP_
#define IOBASE_HPP_

#include "ConsoleBotView.hpp"

class ConsoleView: public ConsoleBotView {
protected:
    int getWinNumber_impl() const;

    int getDeskSize_impl() const;

    int getTimeNumber_impl() const;

    Points getIndex_impl() const;

    void output_impl() const;

private:
    int getInitialParameter(TypeOfChecking type) const;
};

#endif

