/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

/** The proportion of a number in a cell */
const double NUMBER_PROPORTION = 0.900000;

/** Maximum size of the game board to resize content */
const int RESIZE_MAX = 5;

/** Minimum width/length of game board */
const int MIN_WIDTH = 3;

/** Maximum width/length of game board */
const int MAX_WIDTH = 16;

/** Minimum number of minutes to play */
const int MIN_TIME = 1;

/** Maximum number of minutes to play */
const int MAX_TIME = 1000;

/** Maximum winning score */
const int MAX_SCORE = 9999999;

/** Maximum length of indices */
const int MAX_INDEX_LENGTH = 2;

/** Minimal amount of spaces between numbers on the board */
const int NUMBER_OF_SPACES = 2;

#endif
