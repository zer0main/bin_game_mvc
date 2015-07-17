/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

int MainWindow::getDeskSize_impl() const {
    return ui->boardsSize->value();
}

int MainWindow::getWinNumber_impl() const {
    return ui->scoreNumber->value();
}

int MainWindow::getTimeNumber_impl() const {
    return ui->timeNumber->value();
}

void MainWindow::finish_impl(bool fail, int score,
                             int steps_number) const {
    QString result = (fail) ? "<b>You're loser...</b>" :
                     "<b>You're winner!</b>";
    QString score_str = "Your score is " + score;
    QString steps = "You've completed the game in " +
                    steps_number;
    ui->resultLabel->setText(result);
    ui->scoreLabel->setText(score_str);
    ui->stepLabel->setText(steps);
}

void MainWindow::sendHelpMessage_impl() const {
    QMessageBox help;
    help.setText("Some useful help information.");
    help.setInformativeText("");
    help.exec();
}

void MainWindow::startGame_impl(int row_number) {
    configureBoard();
    game_ = GuiGame::make(this, row_number);
    game_->controller->initialStateOfBoard();
    setBoardsModel();
}

void MainWindow::errorHandling_impl(std::exception& e) const {
    QString what = QString::fromStdString(e.what());
    QString error = "<b>The error occurred</b>."
                    "<br/><br/>Contact developers! "
                    "<b>pdolgov99@gmail.com</b>";
    what = what.replace("&", "&amp;");
    what = what.replace("'", "&apos;");
    what = what.replace("<", "&lt;");
    what = what.replace(">", "&gt;");
    what = what.replace("\"", "&quot;");
    QString m = error + "<br/><br/>" + what;
    QErrorMessage::qtHandler()->resize(400, 300);
    QErrorMessage::qtHandler()->showMessage(m);
}

void MainWindow::setBoardsModel() {
    ui->gameBoard->setModel(game_->t_model.data());
}

void MainWindow::configureBoard() {
    ui->gameBoard
    ->setSelectionMode(QAbstractItemView::NoSelection);
    ui->gameBoard->horizontalHeader()
    ->setResizeMode(QHeaderView::Stretch);
    ui->gameBoard->verticalHeader()
    ->setResizeMode(QHeaderView::Stretch);
}

void MainWindow::preparingToPlay() {
    int boards_size = getDeskSize_impl();
    startGame_impl(boards_size);
}

void MainWindow::finishActions(int steps_number) {
    const GameDesk* desk = game_->desk.data();
    finish_impl(checkFail(*desk), score(*desk),
                steps_number);
    ui->stackedWidget->setCurrentWidget(ui->resultpage);
}

bool MainWindow::endOfGame() const {
    const GameDesk* desk = game_->desk.data();
    if (game_type_ == SCORE_MODE) {
        return checkFail(*desk);
    } else if (game_type_ == WIN_MODE) {
        return checkFail(*desk) || checkWin(*desk,
                                            win_number_);
    } else {
        int current_time = time(NULL);
        bool time_is_up =
            (current_time - starting_time_) >= time_number_ * 60;
        return checkFail(*desk) || time_is_up;
    }
}

void MainWindow::on_quitButton_clicked() {
    QApplication::quit();
}

void MainWindow::on_winButton_clicked() {
    game_type_ = WIN_MODE;
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_timeButton_clicked() {
    game_type_ = TIME_MODE;
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_scoreButton_clicked() {
    game_type_ = SCORE_MODE;
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_startButton_clicked() {
    try {
        preparingToPlay();
        if (game_type_ == SCORE_MODE) {
            starting_time_ = time(NULL);
            first_click_ = true;
            ui->stackedWidget
            ->setCurrentWidget(ui->gamepage);
        } else if (game_type_ == WIN_MODE) {
            ui->stackedWidget
            ->setCurrentWidget(ui->winInputpage);
        } else {
            ui->stackedWidget
            ->setCurrentWidget(ui->timeInputpage);
        }
    } catch (std::exception& e) {
        errorHandling_impl(e);
    }
}

void MainWindow::on_playButton_clicked() {
    time_number_ = getTimeNumber_impl();
    starting_time_ = time(NULL);
    first_click_ = true;
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
}

void MainWindow::on_playButton2_clicked() {
    win_number_ = getWinNumber_impl();
    starting_time_ = time(NULL);
    first_click_ = true;
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
}

void MainWindow::on_endButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->startpage);
}
