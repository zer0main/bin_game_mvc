/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "GuiGame.hpp"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    GuiGamePtr game_;

private slots:
    void on_quitButton_clicked();

    void on_winButton_clicked();

    void on_timeButton_clicked();

    void on_scoreButton_clicked();

    void on_endButton_clicked();
};

#endif
