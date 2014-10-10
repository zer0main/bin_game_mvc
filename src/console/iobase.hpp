#ifndef IOBASE_HPP_
#define IOBASE_HPP_

#include "ioview.hpp"

class IoBase: public IoView {
protected:
    int getWinNumber_impl();

    int getDeskSize_impl();

    int getTimeNumber_impl();

    Points getIndex_impl();

    void typeError_impl();

    void output_impl();

    void indexError_impl();

    void finish_impl(bool check_fail, long long int score);

    void sendHelpMessage_impl();

};

#endif
