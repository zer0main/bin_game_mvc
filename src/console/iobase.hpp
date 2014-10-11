#ifndef IOBASE_HPP_
#define IOBASE_HPP_

#include "ioview.hpp"

class IoBase: public IoView {
protected:
    int getWinNumber_impl() const;

    int getDeskSize_impl() const;

    int getTimeNumber_impl() const;

    Points getIndex_impl() const;

    void typeError_impl() const;

    void output_impl() const;

    void indexError_impl() const;

    void finish_impl(bool check_fail, long long int score) const;

    void sendHelpMessage_impl() const;

};

#endif

