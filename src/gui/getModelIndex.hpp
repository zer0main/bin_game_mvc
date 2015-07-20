/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GET_MODEL_INDEX_HPP_
#define GET_MODEL_INDEX_HPP_

#include <QModelIndex>

#include "Points.hpp"

/** Get model's index which is equivalent to the given
gui index.
\param index Gui index
\param row_number Width/length of game board
*/
Point getModelIndex(const QModelIndex& index,
                    int row_number);

#endif
