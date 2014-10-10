#ifndef IOVIEW_HPP_
#define IOVIEW_HPP_

#include "points.hpp"
#include "game_desk.hpp"

class IoView {
public:
    int getDeskSize();

    int getWinNumber();

    int getTimeNumber();

    const GameDesk* getDesk();
    
    Points getIndex();

    void typeError();

    void setDesk(const GameDesk* desk);

    void output();

    void indexError();

    void finish(bool check_fail, long long int score);

    void sendHelpMessage();

protected:
    virtual int getDeskSize_impl() = 0;

    virtual int getWinNumber_impl() = 0;

    virtual int getTimeNumber_impl() = 0;

    virtual Points getIndex_impl() = 0;

    virtual void typeError_impl() = 0;

    virtual void output_impl() =  0;

    virtual void indexError_impl() = 0;

    virtual void finish_impl(bool check_fail, long long int score) = 0;

    virtual void sendHelpMessage_impl() = 0;

private:
    const GameDesk* desk_;
};

#endif
