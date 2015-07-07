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

void MainWindow::on_endButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->startpage);
}
