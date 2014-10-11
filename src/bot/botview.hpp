#ifndef BOTVIEW_HPP_
#define BOTVIEW_HPP_

#include "ioview.hpp"

struct lua_State;

class BotView: public IoView {
public:
    BotView();

    ~BotView();

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

private:
    lua_State* L_;
};

#endif

