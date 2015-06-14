/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TableModel.hpp"

typedef QModelIndex Index;

TableModel::TableModel(QObject* parent,
                       const GameDesk* desk):
    QAbstractTableModel(parent), desk_(desk) {
}

int TableModel::rowCount(const Index& /*parent*/) const {
    return desk_->getRowNumber();
}

int TableModel::columnCount(
    const Index& /*parent*/) const {
    return desk_->getRowNumber();
}

QVariant TableModel::data(const Index& index,
                          int role) const {
    if (role == Qt::DisplayRole) {
        Point pt;
        pt.col = index.column();
        pt.row = index.row();
        return desk_->getDeskNumber(pt);
    }
    return QVariant();
}

void TableModel::updateData() {
    reset();
}
