/*
 * Copyright (C) 2014-2016 Pavel Dolgov
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
    default_font_ = ui->gameBoard->font();
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
}

void MainWindow::resizeBoardsContent(int boards_size) {
    if (boards_size <= Gui::RESIZE_MAX) {
        QTimer::singleShot(Gui::WAIT_TIME, this,
                           SLOT(resizeBoardsContent_deferred()));
    } else {
        ui->gameBoard->setFont(default_font_);
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
            (current_time - go_->starting_time_) >=
            (go_->time_number_ * Rules::SEC_IN_MIN);
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
    // Minimum possible: board's square * 2 + 1
    ui->scoreNumber->setRange(square * 2 + 1, max_int);
    // Default value: board's square * 4
    ui->scoreNumber->setValue(square * 4);
}

void MainWindow::settingOfTime() {
    int max_int = std::numeric_limits<int>::max();
    ui->timeNumber->setRange(1, max_int / Rules::SEC_IN_MIN);
    ui->timeNumber->setValue(Rules::DEFAULT_TIME);
}

void MainWindow::settingOfSize() {
    ui->boardsSize->setRange(Rules::MIN_WIDTH,
                             Rules::MAX_WIDTH);
    ui->boardsSize->setValue(Gui::DEFAULT_SIZE);
}

void MainWindow::setInitialParameters() {
    go_->steps_number_ = 0;
    go_->first_click_ = true;
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
    int boards_size = game_->desk->getRowNumber();
    resizeBoardsContent(boards_size);
}

void MainWindow::on_quitButton_clicked() {
    QApplication::quit();
}

void MainWindow::on_winButton_clicked() {
    go_->game_type_ = WIN_MODE;
    settingOfSize();
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_timeButton_clicked() {
    go_->game_type_ = TIME_MODE;
    settingOfSize();
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_scoreButton_clicked() {
    go_->game_type_ = SCORE_MODE;
    settingOfSize();
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_startButton_clicked() {
    preparingToPlay();
    if (go_->game_type_ == SCORE_MODE) {
        setInitialParameters();
    } else if (go_->game_type_ == WIN_MODE) {
        settingOfScore();
        ui->stackedWidget
        ->setCurrentWidget(ui->winInputpage);
    } else {
        settingOfTime();
        ui->stackedWidget
        ->setCurrentWidget(ui->timeInputpage);
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

void MainWindow::resizeBoardsContent_deferred() {
    // Use the first row because heights of all
    // rows are equal
    int row_height = ui->gameBoard->rowHeight(0);
    ui->gameBoard
    ->setFont(QFont("Helvetica",
                    Gui::NUMBER_PROPORTION * row_height));
}
