/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "getModelIndex.hpp"
#include "desk_functions.hpp"
#include "IoView.hpp"
#include "GuiGame.hpp"
#include "GameOptions.hpp"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, IoView {
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

    GameOptionsPtr go_;

    void setBoardsModel();

    void configureBoard();

    void preparingToPlay();

    void finishActions(int steps_number);

    bool endOfGame() const;

    void tryToMove();

    void settingOfScore();

    void setInitialParameters();

private slots:
    void on_quitButton_clicked();

    void on_winButton_clicked();

    void on_timeButton_clicked();

    void on_scoreButton_clicked();

    void on_startButton_clicked();

    void on_playButton_clicked();

    void on_playButton2_clicked();

    void on_gameBoard_clicked(const QModelIndex& index);

    void on_endButton_clicked();
};

#endif
