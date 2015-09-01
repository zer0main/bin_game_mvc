/*
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <limits>

#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    go_(new GameOptions) {
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/bin_game.ico"));
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
    QString score_str = "Your score is " +
                        QString::number(score);
    QString steps = "You've completed the game in " +
                    QString::number(steps_number) +
                    " moves.";
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
    game_ = GuiGame::make(this, row_number);
    game_->controller->initialStateOfBoard();
    setBoardsModel();
    configureBoard(row_number);
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

void MainWindow::resizeBoardsContent(int boards_size) {
    if (boards_size <= RESIZE_MAX) {
        // Use the first row because heights of all
        // rows are equal
        int row_height = ui->gameBoard->rowHeight(0);
        ui->gameBoard
        ->setFont(QFont("Helvetica",
                        NUMBER_PROPORTION * row_height));
    }
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QWidget* current_page = ui->stackedWidget
                            ->currentWidget();
    if (current_page == ui->gamepage) {
        QMainWindow::resizeEvent(event);
        int boards_size = game_->desk->getRowNumber();
        resizeBoardsContent(boards_size);
    }
}

void MainWindow::setBoardsModel() {
    ui->gameBoard->setModel(game_->t_model.data());
}

void MainWindow::configureBoard(int row_number) {
    ui->gameBoard
    ->setSelectionMode(QAbstractItemView::NoSelection);
    ui->gameBoard->horizontalHeader()
    ->setResizeMode(QHeaderView::Stretch);
    ui->gameBoard->verticalHeader()
    ->setResizeMode(QHeaderView::Stretch);
    resizeBoardsContent(row_number);
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
    if (go_->game_type_ == SCORE_MODE) {
        return checkFail(*desk);
    } else if (go_->game_type_ == WIN_MODE) {
        return checkFail(*desk) || checkWin(*desk,
                                            go_->win_number_);
    } else {
        int current_time = time(NULL);
        bool time_is_up =
            (current_time - go_->starting_time_) >= go_->time_number_ * 60;
        return checkFail(*desk) || time_is_up;
    }
}

void MainWindow::tryToMove() {
    try {
        game_->controller->replace(go_->current_step_);
    } catch (...) {
    }
}

void MainWindow::settingOfScore() {
    int max_int = std::numeric_limits<int>::max();
    int boards_size = game_->desk->getRowNumber();
    int square = boards_size * boards_size;
    // Default value: board's square * 4
    ui->scoreNumber->setValue(square * 4);
    // Minimum possible: board's square * 2 + 1
    ui->scoreNumber->setRange(square * 2 + 1, max_int);
}

void MainWindow::settingOfTime() {
    int max_int = std::numeric_limits<int>::max();
    ui->timeNumber->setValue(DEFAULT_TIME);
    ui->timeNumber->setRange(1, max_int);
}

void MainWindow::settingOfSize() {
    ui->boardsSize->setValue(DEFAULT_SIZE);
    ui->boardsSize->setRange(MIN_WIDTH, MAX_WIDTH);
}

void MainWindow::setInitialParameters() {
    go_->steps_number_ = 0;
    go_->first_click_ = true;
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
}

void MainWindow::on_quitButton_clicked() {
    QApplication::quit();
}

void MainWindow::on_winButton_clicked() {
    go_->game_type_ = WIN_MODE;
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_timeButton_clicked() {
    go_->game_type_ = TIME_MODE;
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_scoreButton_clicked() {
    go_->game_type_ = SCORE_MODE;
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_startButton_clicked() {
    try {
        preparingToPlay();
        if (go_->game_type_ == SCORE_MODE) {
            setInitialParameters();
        } else if (go_->game_type_ == WIN_MODE) {
            settingOfScore();
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
    go_->time_number_ = getTimeNumber_impl();
    go_->starting_time_ = time(NULL);
    setInitialParameters();
}

void MainWindow::on_playButton2_clicked() {
    go_->win_number_ = getWinNumber_impl();
    setInitialParameters();
}

void MainWindow::on_gameBoard_clicked(const QModelIndex&
                                      index) {
    int desk_size = game_->desk->getRowNumber();
    Point p = getModelIndex(index, desk_size);
    if (go_->first_click_) {
        go_->first_click_ = false;
        go_->current_step_.p1 = p;
    } else {
        if (endOfGame()) {
            finishActions(go_->steps_number_);
        } else {
            go_->current_step_.p2 = p;
            tryToMove();
            game_->t_model->updateData();
            go_->steps_number_++;
            go_->first_click_ = true;
        }
    }
}

void MainWindow::on_endButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->startpage);
}
