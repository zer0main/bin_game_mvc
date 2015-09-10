/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

namespace Gui {

/** Waiting time (msec).
Before calling resizeBoardsContent_deferred().
*/
const int WAIT_TIME = 1;

/** The proportion of a number in a cell */
const double NUMBER_PROPORTION = 0.3;

/** Maximum size of the game board to resize content */
const int RESIZE_MAX = 5;

/** Default size of the game board */
const int DEFAULT_SIZE = 10;

}

namespace Rules {

/** Minimum width/length of game board */
const int MIN_WIDTH = 3;

/** Maximum width/length of game board */
const int MAX_WIDTH = 16;

/** Default value for the time number */
const int DEFAULT_TIME = 30;

}

namespace Console {

/** Field for indices and separator */
const int INDEX_FIELD = 5;

/** Maximum length of indices */
const int MAX_INDEX_LENGTH = 2;

/** Minimal amount of spaces between numbers on the board */
const int NUMBER_OF_SPACES = 2;

}

#endif
