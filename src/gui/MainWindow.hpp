/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "GuiGame.hpp"
#include <QMainWindow>

enum GameType {
    WIN_MODE,
    TIME_MODE,
    SCORE_MODE
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

protected:
    int getDeskSize_impl() const;

    int getWinNumber_impl() const;

    int getTimeNumber_impl() const;

    void finish_impl(bool fail, int score,
                     int steps_number) const;

    void sendHelpMessage_impl() const;

    void startGame_impl(int row_number);

    void errorHandling_impl(std::exception& e) const;

private:
    Ui::MainWindow* ui;

    GuiGamePtr game_;

    GameType game_type_;

    int win_number_;

    int time_number_;

    void setBoardsModel();

    void configureBoard();

    void preparingToPlay();

private slots:
    void on_quitButton_clicked();

    void on_winButton_clicked();

    void on_timeButton_clicked();

    void on_scoreButton_clicked();

    void on_startButton_clicked();

    void on_playButton_clicked();

    void on_playButton2_clicked();

    void on_endButton_clicked();
};

#endif
