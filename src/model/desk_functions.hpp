/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef DESK_FUNCTIONS_HPP
#define DESK_FUNCTIONS_HPP

#include "GameDesk.hpp"
#include "Checker.hpp"

int score(const GameDesk& desk);

bool checkWin(const GameDesk& desk, int win_number);

bool checkFail(const GameDesk& desk);

#endif
