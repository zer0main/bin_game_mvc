#ifndef BOTVIEW_HPP_
#define BOTVIEW_HPP_

#include "consolebotview.hpp"

struct lua_State;

class BotView: public ConsoleBotView {
public:
    BotView();

    ~BotView();

protected:
    int getWinNumber_impl() const;

    int getDeskSize_impl() const;

    int getTimeNumber_impl() const;

    Move getIndex_impl() const;

    void output_impl() const;

private:
    lua_State* L_;
};

#endif

