/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <QApplication>

#include "MainWindow.hpp"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
