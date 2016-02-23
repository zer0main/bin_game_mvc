/*
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "getModelIndex.hpp"

Point getModelIndex(const QModelIndex& index,
                    int row_number) {
    Point model_index;
    model_index.row = index.column();
    int row_index = row_number - 1;
    model_index.col = row_index - index.row();
    return model_index;
}
