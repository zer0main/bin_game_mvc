/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef BOTVIEW_HPP_
#define BOTVIEW_HPP_

#include "ConsoleBotView.hpp"

struct lua_State;

class BotView: public ConsoleBotView {
public:
    BotView();

    ~BotView();

protected:
    int getWinNumber_impl() const;

    int getDeskSize_impl() const;

    int getTimeNumber_impl() const;

    Points getIndex_impl() const;

    void output_impl() const;

private:
    lua_State* L_;

    int getBaseParameter(TypeOfChecking type,
                         const char* function_name) const;
};

#endif
