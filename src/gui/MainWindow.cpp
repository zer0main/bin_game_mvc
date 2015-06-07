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
    ui->stackedWidget->setCurrentWidget(ui->winInputpage);
}

void MainWindow::on_timeButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->timeInputpage);
}
