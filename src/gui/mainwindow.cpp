#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openGameWindow() {
    game_window = new GameWindow;
    game_window->show();
}

void MainWindow::on_playButton_clicked() {
    openGameWindow();
}

void MainWindow::on_quitButton_clikced() {
    qApp->quit();
}

