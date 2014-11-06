#ifndef IOBASE_HPP_
#define IOBASE_HPP_

#include "consolebotview.hpp"

class ConsoleView: public ConsoleBotView {
protected:
    int getWinNumber_impl() const;

    int getDeskSize_impl() const;

    int getTimeNumber_impl() const;

    Move getIndex_impl() const;

    void output_impl() const;

    void getUndoNumber(Move& move) const;

};

#endif

