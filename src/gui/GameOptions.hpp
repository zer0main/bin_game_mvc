/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_OPTIONS_HPP
#define GAME_OPTIONS_HPP

#include "Points.hpp"

enum GameType {
    WIN_MODE,
    TIME_MODE,
    SCORE_MODE,
};

/** Special game parameters */
struct GameOptions {
    GameType game_type_;

    int win_number_;
    int time_number_;
    int starting_time_;
    int steps_number_;

    bool first_click_;

    Points current_step_;
};

#endif
