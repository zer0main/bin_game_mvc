#ifndef CONSOLEBOTVIEW_HPP_
#define CONSOLEBOTVIEW_HPP_

#include "ioview.hpp"

class ConsoleBotView: public IoView {
protected:
    void outputGeneral() const;
    
    void typeError_impl() const;

    void indexError_impl() const;
    
    void finish_impl(bool check_fail, int score, int steps_number) const;

    void sendHelpMessage_impl() const;
};

#endif
